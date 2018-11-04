// user.c

#include <origin.h>
#include <user.h>
#include <ansi.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_ENCODING;
static int last_age_set = 0;            // ��һ�θ���AGE��ʱ��
static int user_say = 0;                // һ��ʱ�������������say-action
static int user_command = 0;            // һ��ʱ��������ҷ��͵�����
static int at_time = 0;                 // ��ʲôʱ������
static int ban_to = 0;                  // ��ʲôʱ�������
static int attach_flag = 0;             // �Ƿ����ں�ϵͳ����

#define DEFAULT_PRISON          "/d/sroom/jianyu"

// globals variables
string  prison = 0;
int     time_to_leave = 0;

string query_prison()           { return prison; }
int    query_time_to_leave()    { return time_to_leave; }
int    is_in_prison();

#define MAX_COMMAND_ONE_SECTION         40
#define MAX_SAY_ONE_SECTION             5
#define BAN_SAY_PERIOD                  60

int query_current_neili_limit();
int query_neili_limit();
int query_current_jingli_limit();
int query_jingli_limit();
int query_potential_limit();

int is_user() { return 1; }

void create()
{
	::create();
	set_name("ʹ�������", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "�ն˻���̬�趨Ϊ " + term_type + "��\n", this_object());
}

void reset()
{
	if( (int)query("potential") - (int)query("learned_points") < 100 )
		add("potential", 1);
	if( (int)query("thief") > 0 )
		add("thief", -1 );
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
	int res;

        if (query_temp("user_setup") && environment())
        {
	        save_autoload();
	        res = ::save();
	        clean_up_autoload();		// To save memory
        } else
                res = 0;

	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	if( !last_age_set )
        {
                last_age_set = time();
                add("mud_age", 0);
        }

        if (! query("env/halt_age") ||
            ! environment(this_object()) ||
            ! environment(this_object())->query("chat_room"))
        {
                // Update age
	        add("mud_age", time() - last_age_set);
                if (time_to_leave)
                        time_to_leave -= time() - last_age_set;
        }

	last_age_set = time();

	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
        last_age_set = 0;
	update_age();

	::setup();

        // set the enable flag to enable save
        set_temp("user_setup", 1);

	restore_autoload();

        //delete("no_get");
        //delete("no_get_from");
}

private void user_dump(int type)
{
	switch(type)
	{
		case DUMP_NET_DEAD:
			if (environment())
			{
				tell_room( environment(), query("name") + "���߳��� " +
				NET_DEAD_TIMEOUT/60 + " ���ӣ��Զ��˳�������硣\n");
			}
			catch(command("quit"));
			if (this_object())
			{
				// command quit failed.
				seteuid(getuid());
				destruct(this_object());
			}
			break;
		case DUMP_IDLE:
			if(!wizardp(this_object()))
			{
				tell_object( this_object(), "�Բ������Ѿ��������� " +
					IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
				if (environment())
				{
					tell_room( environment(), "һ��紵�����������е�" + query("name") +
						"��Ϊһ�ѷɻң���ʧ�ˡ�\n", ({this_object()}));
				}
				command("quit");
				if (this_object())
				{
					// command quit failed.
					seteuid(getuid());
					destruct(this_object());
				}
			}
			break;
		default:
				return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	remove_all_enemy();

	set_temp("netdead", 1);
	if( userp(this_object()) )
	{
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
		tell_room(environment(), query("name") + "�����ˡ�\n", this_object());
		CHANNEL_D->do_channel(this_object(), "sys", "�����ˡ�");
	}
	else
	{
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "����������ϡ�\n");
}

int query_neili_limit()
{
	string *skill_names;
	mapping skills;
	int neili_limit;
	int base_lvl, lvl;
	int tmp;
	int i;

	skills = this_object()->query_skills();
	if (! mapp(skills))
                return 0;

        skill_names = keys(skills);

        base_lvl = ((int) skills["force"]) / 2; 
        neili_limit = base_lvl * 10;
        for (i = 0; i < sizeof(skill_names); i++)
        {
                if (file_size(SKILL_D(skill_names[i]) + ".c") == -1)
                {
                        // No such skill
                        continue;
                }

                if (! SKILL_D(skill_names[i])->valid_enable("force"))
                        continue;

                lvl = (int) skills[skill_names[i]];
                tmp = (base_lvl + lvl) * 10;
                tmp += (int) SKILL_D(skill_names[i])->query_neili_improve(this_object());
                if (tmp > neili_limit) neili_limit = tmp;
        }

        return neili_limit;
}

int query_current_neili_limit()
{
        int neili;
        string force;

        force = query_skill_mapped("force");
        neili = (int)query_skill("force", 1) / 2 * 10;
        if (stringp(force) && force != "")
        {
                neili += (int)query_skill(force, 1) * 10;
                neili += SKILL_D(force)->query_neili_improve(this_object());
        }    

        return neili;
}

int query_jingli_limit()
{
        return query_neili_limit() / 4;
}

int query_current_jingli_limit()
{
        return query_current_neili_limit() / 4;
}

int query_potential_limit()
{
        return (int)query("learned_points") +
               query_int() * 10 / 2 + 100;
}

int accept_fight(object ob)
{
	if (query_temp("pending/fight") == ob)
		return 1;

        tell_object(this_object(), YEL "�����Ը��ͶԷ����б��ԣ�����Ҳ��" +
                    ob->name() + "("+ (string)ob->query("id")+")"+
                    "��һ�� fight ָ�\n" NOR);

	tell_object(ob, YEL "���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ���" +
              "�ܽ��б��ԡ�\n" NOR);

        return 0;
}

int accept_hit(object ob)
{
        message_vision("$N��ȵ���" + ob->name() + "����Ҫ��ʲô��\n\n",
                       this_object(), ob);
        return 1;
}

int accept_kill(object ob)
{
        if (is_killing(ob->query("id")))
                return 1;

        tell_object(this_object(), HIR "�����Ҫ��" + ob->name() +
	        "�����ಫ������Ҳ�������(" + (string)ob->query("id") +
                ")��һ�� kill ָ�\n" NOR);
        return 1;
}

int accept_ansuan(object who)
{
        command(random(2) ? "say �ţ���ô..." : "say �������ã�");
        return 1;
}

int reject_command()
{
        int t;

        if (wizardp(this_object()))
                return 0;

        t = time() & 0xFFFFFFFE;
        if (at_time != t)
        {
                at_time = t;
                user_command = 1;
                user_say = 0;
        } else
                user_command++;

        if (user_command > MAX_COMMAND_ONE_SECTION)
                return 1;

        return 0;
}

int ban_say()
{
        int t;

        if (wizardp(this_object()))
                return 0;

        if (is_in_prison())
        {
                notify_fail("��ʡʡ�ɣ��ú�������Σ������ڡ�\n");
                return 1;
        }

        t = time() & 0xFFFFFFFE;
        if (ban_to > t)
        {
                notify_fail("ϵͳ��ֹ���ͳ���Ϣ������ " +
                            (ban_to - t) + " �����Ժ��ٳ��ԡ�\n");
                return 1;
        }
        if (at_time != t)
        {
                at_time = t;
                user_say = 1;
                user_command  = 0;
        } else
                user_say++;

        if (user_say > MAX_SAY_ONE_SECTION)
        {
                ban_to = t + BAN_SAY_PERIOD;
                CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                        "��˵" + query("name") + "��Ϊ̫���£����˶�ס���졣");
                notify_fail(HIR "�����㷢������Ϣ̫�࣬���ϵͳ��ʱ"
                            "��ֹ�㷢����Ϣ��\n" NOR);
                return 1;
        }

        return 0;
}

// return true if the user was in prison now
int is_in_prison()
{
        return stringp(prison);
}

// thow the person into prison
void get_into_prison(object ob, string p, int time)
{
        object me;

        me = this_object();
        if (! p) p = prison;
        if (! p) p = DEFAULT_PRISON;

        if (prison && base_name(environment()) == p)
        {
                time_to_leave += time * 60;
                if (ob && time)
                        CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                                "��˵" + query("name") + "�����ڱ�" +
                                ob->query("name") + "�ӳ���" +
                                chinese_number(time) + "���ӡ�\n");
                return;
        }

        if (prison && prison == p && base_name(environment()) != prison)
        {
                message_vision(HIM "��Ȼһ����ص��������������ܣ������������"
                       "��С�����˳�����һ��ץס$N����\n������ס�����"
                       "�ݵĽе������üһ��������...��\n\n" NOR,
                       me);

                message("vision", HIY "����һ����⣬���ʱʲôҲ��������...\n\n"
                          HIM "��������ɢȥ... " + me->name() +
                          "�����ˣ�����\n\n" NOR,
                          environment(me), ({ me }));

                me->set("startroom", prison);
                me->move(prison);
                message_vision("��ž����һ����$N�ݺݵ�ˤ���˵��ϡ�\n", me);
                if (living(me)) me->unconcious();

                CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                        "��˵" + query("name") + "Խ��Ǳ�ӣ������ץ"
                        "��ȥ�ˡ�\n");

                save();
                return;
        }

        message_vision(HIM "��Ȼһ����ص��������������ܣ������������"
                       "��С�����˳�����һ��ץס$N����\n������ס�����"
                       "�ݵĽе�����վס���㷸���ˣ���������߰ɣ���\n\n" NOR,
                       me);

        message("vision", HIY "����һ����⣬���ʱʲôҲ��������...\n\n"
                          HIM "��������ɢȥ... " + me->name() +
                          "�����ˣ�����\n\n" NOR,
                          environment(me), ({ me }));

        if (ob)
        {
                CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                        "��˵" + query("name") + "��" + ob->query("name") +
                        "�ͽ���" + p->short() + HIM "������" +
                        chinese_number(time) + "���ӡ�\n");
        }

        me->set("startroom", prison);
        me->move(p);
        prison = p;
        time_to_leave += time * 60;
        save();

        message_vision("��ž����һ����$N���ص�ˤ���˵��ϡ�\n", me);
        if (living(me)) me->unconcious();
}

// out of prison
void leave_prison(object ob)
{
        object me;
        string startroom;

        me = this_object();
        time_to_leave = 0;
        prison = 0;
        message_vision("��Ȼ����С��ð�˳�������ס$N���������ˣ������"
                       "���ˣ�Ҫ���ٸҷ������ߺ�...\n\n", me);

        tell_object(me, HIR "����ǰһ��...\n\n" NOR);
        message("vision", "����С���" + me->name() + "ͻȻ������ǰ��"
                          "ʧ��... �㲻��̾��һ������\n",
                          environment(me), ({ me }));
        if (me->is_ghost())
                startroom = "/d/death/gate";
        else
                startroom = "/d/bianliang/guangming";
        me->set("startroom", startroom);

        me->move(startroom);
        message("vision", "һ����ص��������ֻ��" + me->name() +
                          "ֱͦͦ�����ڵ��ϡ�\n", environment(me), ({ me }));
        if (living(me))
                me->enable_player();
        else
                me->revive();
        save();

        if (ob)
                CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                        "��˵" + query("name") + "��" + ob->name() +
                        "��ǰ�ͷ��ˡ�\n");
        else
                CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
                        "��˵" + query("name") + "�Ѿ������ͷ��ˡ�\n");
}

// when the user was in prison, the heart beaten function of
// char will call damage heal_up, then the function will call
// it
void update_in_prison()
{
        object me;

        me = this_object();
        me->set("qi", 0);
        me->set("jing", 0);
        me->set("neili", 0);

        if (time_to_leave > 0)
        {
                if (environment() && base_name(environment()) != prison)
                {
                        // escape from prison?
                        get_into_prison(0, 0, 0);
                }
                return;
        }

        leave_prison(0);
}

// return true if the user was attached system, such as
// command sameip will run a much long time, in the period
// the user shouldn't receive message except from the system
int is_attach_system()
{
        return attach_flag;
}

// start attaching
int attach_system()
{
        attach_flag = 1;
}

// stop, deatched
int detach_system()
{
        attach_flag = 0;
}
