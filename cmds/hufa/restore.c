// restore.c

#include <ansi.h>
#include <localtime.h>

inherit F_CLEAN_UP;

private string get_backup_data_dir(string user, int day);
int help(object me);

int main(object me, string arg)
{
        int day;
        string user;
        string dir;
        string flogin, fuser;
        string msg;
        object ob, link_ob;

	if (me!=this_player(1))
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

        if (BACKUP_D->is_backuping())
        {
                write("ע�⣺�Զ��������Ͼ�Ҫ��ʼ���������ڲ���ִ�лָ�������\n");
                return 1;
        }

	if (!arg)
                return help(me);

        if (sscanf(arg, "%s from %d", user, day) != 2)
        {
                if (sscanf(arg, "%s from last", user) == 1)
                        day = 1;
                else
                if (sscanf(arg, "%s from temp", user) == 1)
                        day = 0;
                else
                if (sscanf(arg, "%s from dump", user) == 1)
                        day = -1;
                else
                {
                        user = arg;
                        day = 1;
                }
        }

        if (day < -1 || day > 7)
        {
                write("û�����������������\n");
                return 1;
        }

	seteuid(getuid());
        dir = get_backup_data_dir(user, day);
        flogin = "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__;
        fuser  = "user/"  + user[0..0] + "/" + user + __SAVE_EXTENSION__;

        msg = HIM "��ʼ�ָ����(" + user + ")�ı������ݡ�\n\n" NOR;
        // check the backup data
        if (file_size(dir + flogin) < 0)
        {
                write(sprintf("%sȱ���ļ���%s���޷��ָ���\n", msg, dir + flogin));
                return 1;
        }

        if (file_size(dir + fuser) < 0)
        {
                write(sprintf("%sȱ���ļ���%s���޷��ָ���\n", msg, dir + fuser));
                return 1;
        }

        // remove current user's data
        if (file_size(DATA_DIR + flogin) >= 0 ||
            file_size(DATA_DIR + fuser) >= 0)
        {
                if (dir == TEMP_DIR)
                {
                        msg += "�ָ��������ݴ����е����ݡ�\n";
                } else
                if (file_size(TEMP_DIR + flogin) >= 0 ||
                    file_size(TEMP_DIR + fuser) >= 0)
                {
                        msg += "�����ݴ���(/temp/)�����Ѿ���������"
                               "�����ݣ���˱��β����ݴ档\n";
                } else
                {
                        // move current user's data to /temp/
                        assure_file(TEMP_DIR + flogin);
                        assure_file(TEMP_DIR + fuser);
                        cp(DATA_DIR + flogin, TEMP_DIR + flogin);
                        cp(DATA_DIR + fuser,  TEMP_DIR + fuser);
                        msg += "���Ŀǰ��������ʱ���浽�ݴ���(/temp/)�¡�\n";
                }
                rm(DATA_DIR + flogin);
                rm(DATA_DIR + fuser);
                msg += "ɾ�����Ŀǰ�ĵ�����\n";
        }

        // after remove, if the data existed ?
        if (file_size(DATA_DIR + flogin) >= 0 ||
            file_size(DATA_DIR + fuser) >= 0)
        {
                write(sprintf("%sû���ܹ��ɹ���ɾ��������ڵĵ���(%s)��(%s)��\n"
                       "���Ȳ�֤Ȼ����ִ�б��ݲ�����\n",
                       msg, DATA_DIR + flogin, DATA_DIR + fuser));
                return 1;
        }

        // ok. copy the backup data to /data/
        assure_file(DATA_DIR + flogin);
        assure_file(DATA_DIR + fuser);
        cp(dir + flogin, DATA_DIR + flogin);
        cp(dir + fuser,  DATA_DIR + fuser);
        msg += sprintf("��(%s)�и�����ҵĵ������ݡ�\n", dir);

        // success ?
        if (file_size(DATA_DIR + flogin) < 0 ||
            file_size(DATA_DIR + fuser) < 0)
        {
                write(sprintf("%sû���ܹ��ɹ��Ĵ�(%s)�и�����ҵĵ�����\n",
                       msg, dir));
                return 1;
        }
        msg += sprintf("�������Ƴɹ���\n");
        log_file("backup", sprintf("user %s has been restore by %s from %s.\n",
                                   user, me->query("id"), dir));

        // the player online?
        if (! (ob = find_player(user)))
        {
                write(msg);
                return 1;
        }

        // restore the object
        tell_object(ob, HIM "\n�Ӵ���������������ݣ����������á�\n" NOR);
        if (! ob->restore())
        {
                write(sprintf("%s���û��޷���ȡ���ݵ����ݡ�\n", msg));
                return 1;
        }
        if (objectp(link_ob = ob->query_temp("link_ob")))
                link_ob->restore();

        write(msg);

        // re-setup the user
        ob->delete_temp("user_setup");
        ob->setup();
        if (! environment(ob))
        {
                tell_object(ob, HIC "\n���������������Ļ�������������"
                                "Ҫ�ƶ�����ʦ����ҡ�\n" NOR);
                ob->move("/d/wizard/guest_room");
                ob->set("startroom", "/d/wizard/guest_room");
        }
        tell_object(ob, NOR"\n>" HIY  "l\n" NOR);
        catch(ob->force_me("look"));
        tell_object(ob, NOR">" HIY  "hp\n" NOR);
        catch(ob->force_me("hp"));
        tell_object(ob, ">" HIY "check backup data now\n" +
                        HIC "������Ŀǰ��״���Ƿ���ȷ��\n" NOR +
                        (ob == me ? "" : ">"));
        if (ob != me)
                tell_object(me, HIC "\n����Ѿ��������á�\n\n" NOR);
	return 1;
}

// return the directory of the user
// dir/login/?/??? & dir/user/?/??? would be the user's data
private string get_backup_data_dir(string user, int day)
{
        mixed lt;
        int now;

        if (day == 0)
                // restore from temp
                return TEMP_DIR;

        if (day == -1)
                // restore from dump
                return DUMP_DIR;

        lt = localtime(time());
        lt[LT_MON]++;   // the month is from 0..31 so I will adjust it
        now = lt[LT_HOUR] * 100 + lt[LT_MIN];
        if (now > BACKUP_D->query_backup_time())
        {
                // because the o'clock has pass through the backuping
                // time, so the most recently backup data is of today
                day--;
        }

        lt[LT_MDAY] -= day;
        if (lt[LT_MDAY] > 0)
                return sprintf("%s%d-%d-%d/", BACKUP_DIR,
                               lt[LT_YEAR], lt[LT_MON], lt[LT_MDAY]);

        lt[LT_MON]--;
        switch (lt[LT_MON])
        {
        case 2:
                if ((lt[LT_YEAR] % 4) == 0 && (lt[LT_YEAR] % 100) != 0)
                        lt[LT_MDAY] += 29;
                else
                        lt[LT_MDAY] += 28;
                break;

        case 3: case 5: case 7: case 8: case 10:
                lt[LT_MDAY] += 31;
                break;

        case 4: case 6: case 9: case 11:
                lt[LT_MDAY] += 30;
                break;

        case 0: // last year
                lt[LT_MDAY] += 31;
                lt[LT_MON] = 12;
                lt[LT_YEAR] --;
        }

        return sprintf("%s%d-%d-%d/", BACKUP_DIR,
                       lt[LT_YEAR], lt[LT_MON], lt[LT_MDAY]);
}

int help(object me)
{
write(@HELP
ָ���ʽ��restore <���ID> from <last | 1..7 | temp | dump>

�ӱ������ָ�һ����ҵ����ݡ�����last��Ч�ڣ�����ʾ�����һ�εı�����
�ָ���������ݻָ�ʱ����ǰ�����ݽ������浽һ���ݴ���(����ݴ�����)��
�������һָ��ı��ݲ����⣬���Դ�temp�лָ�����ҵ����ݻָ�ʱ�����
��������ϣ���ִ��restore �����������Ҵ�ʱ���ݲ�����������û�л���
����û��setup�������¸�����ҡ�

ִ����ָ������Ժ�Ӧ�ý���ҵ����ݴ��ݴ������������

ϵͳ SHUTDOWN ���߱����Ժ����еĴ������ݰ���������ݽ������浽dump
Ŀ¼�У�����Ϊ�˷�ֹϵͳ���������Ժ���ֹ��ϵ��������ܵ���ʧ�����Ҳ
���Դ�dump�лָ����ݡ�

ע�⣺�ڱ���ϵͳ��һ�������ʾ�Ժ�һֱ��������ϵĹ����У�����ִ����
�ػָ�������ݵĲ�����

���ָ�cleartemp
HELP
	);
    return 1;
}
