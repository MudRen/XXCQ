// by snowcat
// sameip

#include <ansi.h>

inherit F_CLEAN_UP;

string fname(object ob);

nosave object run_user = 0;

int main(object me, string arg)
{
        object who;
        int    i, count;
        string *dir;
        string name, address;
        string *result;

        if (me != this_player(1))
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

        if (!arg)
	        return notify_fail("ָ���ʽ��sameip <ʹ��������> | <IP ��ַ>\n");

        if (find_call_out("search_dir") != -1)
        {
                if (run_user && run_user != me)
                        return notify_fail("��ǰ" + run_user->query("name") +
                                           "(" + run_user->query("id") + ")" +
                                           "����ʹ�ø�ָ����в��ң����Ժ���ʹ�á�\n");
                remove_call_out("search_dir");
        }

        seteuid(getuid());
        if (member_array('.', arg) != -1)
        {
                address = arg;
        } else
        {
                name = arg;
                if (file_size(DATA_DIR + "login/" + name[0..0] + "/"  + name + __SAVE_EXTENSION__) < 0)
                        return notify_fail("û����λʹ���ߡ�\n");

                who = new(LOGIN_OB);
                who->set("id", name);
                if (! who->restore())
                        return notify_fail("û����λʹ���ߡ�\n");

                write(fname(who) + "�ϴδ� " + who->query("last_from")+" ���ߡ�\n");
                if (! who->query("last_from"))
                        return notify_fail("�޷���֪������ϴ����ߵص㡣\n");
                address = who->query("last_from");
                destruct(who);
        }

        write("Ѱ�Ҵ� " + address + " ���ߵ�ʹ���ߣ�\n");
        count = 0;
        dir = get_dir(DATA_DIR + "login/");
        i = 0;
        result = ({ });
        call_out("search_dir", 0, count, dir, i, address, me, result);
        write(HIG "����ϵͳ��ͳ�����ݣ��Ժ�㱨��\n"
              HIG "���ȣ�" + process_bar(0) + "\n");
        me->attach_system();
        run_user = me;
        return 1;
}

void search_dir(int count, string *dir, int i, string address, object me, string *result)
{
        object ob;
        int j;
        string *ppls, str, adr;
        string info;

        if (! objectp(me))
        {
                result = 0;
                return;
        }

        if (! me->is_attach_system())
        {
                run_user = 0;
                result = 0;
                return;
        }

        if (i == sizeof(dir))
        {
                info = ESC + "[256D" + ESC + "[K"
                       HIC "\n����������ҵĽ�����£�\n" NOR WHT;
                for (i = 0; i < sizeof(result); i++)
                {
                        info += result[i];
                        if (i % 20)
                        {
                                message("system", info, me);
                                info = "";
                        }
                }
                info += HIG "���� " + to_chinese(count) + " λʹ���ߴ������ַ���ߡ�\n\n" NOR;
                message("system", info, me);
                run_user = 0;
                me->detach_system();
                me->write_prompt();
                result = 0;
                return;
        } else
        {
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                for(j = 0; j < sizeof(ppls); j++)
                {
                        reset_eval_cost();
                        if (sscanf(ppls[j], "%s.o", str)==1)
                        {
                                ob = new(LOGIN_OB);
                                ob->set("id", str);
                                if (! ob->restore() ||
                                    ! (adr = ob->query("last_from")) ||
                                    strsrch(adr, address) == -1)
                                {
                                        destruct(ob);
                                        continue;
                                }

                                info = sprintf("%-14s%-14s%-11s%-6s%s\n",
                                              ob->query("id"),
                                              fname(ob),
                                              ctime(ob->query("last_on"))[0..10],
                                              ctime(ob->query("last_on"))[20..24],
                                              ob->query("last_from"));
                                result += ({ info });
                                destruct(ob);
                                count++;
                        }
                }
                i++;
        	message("system", ESC + "[1A" + ESC + "[256D"
                                  HIG "���ȣ�" + process_bar(i * 100 / sizeof(dir)) +
                                  "\n" HIR "ִ����" NOR "> ", me);
                call_out("search_dir", 0, count, dir, i, address, me, result);
    }
}

string fname(object ob)
{
        string s1, s2;

        s1 = ob->query("surname");
        s2 = ob->query("purename");
        if (! s1) s1= "";
        if (s2) s1 += s2;
        if (s1 == "") s1 = "����";
        return s1;
}

int  help(object  me)
{
write(@HELP
ָ���ʽ��sameip <ʹ��������> | <IP ��ַ>

����������ʹ������ͬһ��ַ���ߵ�ʹ���ߡ�
HELP
    );
        return  1;
}
