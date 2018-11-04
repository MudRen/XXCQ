// ganjiang.c  �ɽ�
// Written by Doing Lu  1998/11/2

// �ɽ����������ߵĳ��������ǲ�������ҵ���Ʒ�����������Ƶ���Ӧ�ú�Īа�򽻵���
// ��� player ��Īа���ｫһ���������ף�Īа�����ߴ��������ɽ�

// �ɽ����յ�Īа�����ĵ��ߣ���������ж������������Ժ����� object ������Ϊ noname��
// ���õ��ߵ������ߣ������ߵ�ID�������õ��ߵ���Ч���� point����Ϊ��Īа�����Ѿ������ˡ�
// ���ҵȺ� player ������ڵ��ߵ���Ϣ�������ʱ����������˵ı�־������� object
// ����û� finish ����ѯ�� player �Ƿ�������������ɵ����ļ������� player �����¼����
// ��������޸ġ�
// ���У������õ�����Ϣʱ������ set_item() �����������ã�������ִ�����ֹ��������

inherit NPC;

#include <ansi.h>
#include "itemmaker.h"

// ����ַ��������ó����ֵ����ʾ������ַ������зǷ��ĸ�ʽ
#define	ILLEGAL_STR	"."
// ��convertʱ����Ҫ��Ҫȥ����ɫ
#define	NOCOLOR		1
#define COLORABLE	0

int	ask_me();				// ��ʾ������Ϣ
int	show_order();				// ��ʾ������Ϣ
int	start_work(object me, object ob);	// ��Īа���ⲿ����
int	prepare_make(object me, object ob);	// ��ʼ����
object	set_item(string arg1, string arg2);	// ���ô��� object �ĸ�������
int	confirm_make(string arg, object ob);	// player ������Ϻ�ȷ��

void	clear_data();				// ��� ganjiang, moye, player ����ʱ������ȥ����������

// ת���ַ�������Ҫ�������ɫ���д���
string	converts(string arg, int max_len, int nocolor);

void create()
{
	set_name("�ɽ�", ({ "ganjiang", "gan jiang", "gan" }));
	set("long", "�����ô�׳�������������絶����͸��һ��Ӣ�������ǹ�������������������ʦ��\n" );

	set("nickname", HIR "��ʦ" NOR);
	set("gender", "����");
	set("attitude", "friendly");

	set("age", 1535);
	set("shen_type", 0);

	set("str", 1000);

	set("inquiry", ([
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"װ��" : (: ask_me :),
		"����" : (: ask_me :),
		"����" : (: ask_me :),
		"װ��" : (: ask_me :),

		"ԭ��" : "�����͵���ԭ�ϣ�һ��Ǯ��һ�ֻ�����ԭ�Ͼ��ܳ��ö�����\n",
		"����" : "�����кܶ࣬�Լ�ȥ�Ұɡ�\n",
		"����" : "������٣��������ƽ�Ҫ�������뽻��Īа��\n",
		"�۸�" : "���ԭ�Ϻ����ϸ�Īа����(show)�����ܸ��������һ����Ǯ��",

		"����" : (: show_order :),
		"����" : (: show_order :),
		"order": (: show_order :),
		
	]));

	seteuid("doing");

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_name", "name");
	add_action("do_name", "����");
	add_action("do_desc", "desc");
	add_action("do_desc", "����");
	add_action("do_loadmsg", "loadmsg");
	add_action("do_loadmsg", "װ��");
	add_action("do_loadmsg", "װ����Ϣ");
	add_action("do_backmsg", "backmsg");
	add_action("do_backmsg", "����");
	add_action("do_backmsg", "������Ϣ");
	add_action("do_finish", "finish");
	add_action("do_finish", "���");

	add_action("do_help", "help!");
	add_action("do_help", "����");
}

// ������ʾ��Ϣ
int ask_me()
{
	message_vision("�ɽ���$N˵������Щ������Īа����ֻ��������\n", this_player());
	return 1;
}

int accept_object(object me, object ob)
{
	if (me->query("name") == "Īа")
	{
		if (interactive(me))
		{
			command ("kick " + me->query("id"));
			message_vision("�ɽ��ٺٵļ�Ц����������$N˵��������Ϊȡ�������ӵ����־����ɱ��ң��һ�ûϹ�أ�\n", me);
			return 1;
		}
		start_work(present(me->query_temp("item/������ID"), environment()), ob);
	}
	if (ob->query("item_origin"))
	{
		message_vision("�ɽ���$N˵���������ⶫ����������Ƚ���Īа���������︶��Ǯ��˵��\n", me);
		return 0;
	} else
	{		
		message_vision("�ɽ�����Ķ�$N˵�����������Щ������ʲô����������������Щ������\n", me);
		return 0;
	}
}

int start_work(object me, object ob)
{
	remove_call_out("prepare_make");
	call_out("prepare_make", 1, me, ob);
	return 1;
}

int prepare_make(object me, object ob)
{
	message_vision(HIC "\n�ɽ�˵�����ã���¯������\n\n" NOR, this_object());
	message_vision(HIC "�ɽ��ӹ�Īа���е�" + ob->query("name") +
		       HIC "�����ְ�������¯�ڣ���ʱ�䣬��" + ob->query("name") +
		       HIC "�ѱ���¯�е�����������û��\n" +
		       "�ɽ�������¯����˵�������֮����Ϊ��Ѫ��������֮�����������......\n\n" NOR , this_object());
	remove_call_out("work_step_1");
	call_out("work_step_1", 5, me, ob);
	return 1;
}

int work_step_1(object me, object ob)
{
	message_vision(HIG "¯�𽥽���ת������ɫ�����粻����Ծ�����������ʮ�����ȣ����Ǹɽ�Īа�������¡�\n\n" NOR, this_object());
	if (objectp(present(me, environment())))
	{
		me->set_temp("item/help", 1);
		message_vision(HIW "�ɽ���$N˵��������������ø��ã���Ҫע���Լ��ľ���Ѫ�����������д��⣬����(help!)��һ��֮����\n\n", me);
	}
	remove_call_out("work_step_2");
	call_out("work_step_2", 8, me, ob);
	return 1;
}

int work_step_2(object me, object ob)
{
	message_vision(HIR "¯�𵭵��İ������������ֳ�һƬ��ɫ......\n\n" NOR, this_object());
	remove_call_out("work_step_3");
	me->delete_temp("item/help");
	call_out("work_step_3", 3, me, ob);
	return 1;
}

int work_step_3(object me, object ob)
{
	message_vision(HIW "�ɽ����ֳ���������һ�����Ѿ�ȡ����" + ob->query("name") +
		       HIW "�����ֳֽ�մ��۾��������������\n�����ģ�" + ob->query("name") +
		       HIW "�ڸɽ����µĳ���" + ob->query("ctype") +
		       HIW "����״��\n\n" NOR, this_object());
	remove_call_out("work_step_4");
	call_out("work_step_4", 5, me, ob);
	return 1;
}

int work_step_4(object me, object ob)
{
	message_vision(HIC "�ɽ�������ϣ����һ������" + ob->query("ctype") +
		       HIC "����ˮ�أ�ֻ��˿˿���죬��ˮ������һ���������������ܡ�\n\n" NOR, this_object());
	remove_call_out("work_step_5");
	call_out("work_step_5", 3, me, ob);
	return 1;
}

int work_step_5(object me, object ob)
{
	message_vision(HIW "�ɽ������Ĵ�ˮ�س�������õ�" + ob->query("ctype") +
		       HIW "���˿��������˵���ܺã��ܺá�\n\n" NOR, this_object());
	remove_call_out("work_step_6");
	call_out("work_step_6", 2, me, ob);
}

int work_step_6(object me, object ob)
{
	object moye;
	int improve;
	if (!objectp(moye = present("moye", environment())))
	{
		message_vision(HIW "�ɽ����˿����ܣ�˵�����ף�Īа�أ��������ˣ������ˣ�ȥ�ɣ�\n"
			       "�ɽ������õĵ����׽���¯���ʹ˲�����\n\n" NOR, this_object());
		if (objectp(me)) me->delete_temp("item");
		if (objectp(ob)) destruct(ob);
		this_object()->delete_temp("item");
		return 1;
	}
	if (!objectp(me) || !objectp(present(me, environment())))
	{
		message_vision(HIW "�ɽ�̾�˿�����˵��������Ϊ�����ȥ�ˣ������˰��ˣ������ˣ�ȥ�ɣ�\n"
			       "�ɽ������õĵ����׽���¯���ʹ˲�����\n\n" NOR , this_object());
		if (objectp(me)) me->delete_temp("item");
		if (objectp(ob)) destruct(ob);
		this_object()->delete_temp("item");
		moye->delete_temp("item");
		return 1;
	}
	moye->set_temp("item/���ڵȺ�", 1);
	moye->delete_temp("item/��������");
	me->set_temp("item/������Ϣ", 1);
	me->delete_temp("item/׼������");
	message_vision("�ɽ���$N˵����\n"
		       "һ" + ob->query("unit") + "��" + ob->query("ctype") + NOR "����û�����֣������������ְɣ�\n", me);
	// ˽����Ϣ
	tell_object(me,"������Ҫ��������������Ϣϵͳ��ȱʡ����������ȻҲ�������Լ�Ϊ����һЩ��������\n"
		       "��Ȼ�ˣ���ò����ñ������Ĵ����־��ޡ�����ķ������¡�\n"
		       "    ����(name):    name �������� Ӣ�Ĵ��š�  (������)\n"
		       "    ����(desc):    desc �������������֡�     (��  ѡ)\n"
		       "    װ��(loadmsg): loadmsg װ��ʱ��������    (��  ѡ)\n"
		       "    ����(backmsg): backmsg ����ʱ��������    (��  ѡ)\n"
		       "����ʱ��������\\n������Ӣ�Ĵ����������е����ֶ���������ɫ��ʹ����ɫ�ķ������Բ���nick ��\n"
		       "�������ÿ����ˣ����������(finish)��Ҫ��û������������������� < ���� >\n\n" NOR);
	// ������ߵ����֣�ID�����������ԣ��������õ��ߵļ�ֵ��������
	this_object()->set_temp("item/������", ob->query("id"));
	ob->set("long", "");
	ob->set("wield_msg", "");
	ob->set("wear_msg", "");
	ob->set("unwield_msg", "");
	ob->set("remove_msg", "");
	ob->set("owner", me->query("name"));
	ob->set("ownerid", me->query("id"));
	// �����ȼ�
	improve = 0;
	if (me->query_temp("item/cost"))
	{
		improve = me->query_temp("item/cost");
		me->delete_temp("item/cost");
	}
	improve = (improve / 20 + 70);
	improve = improve * ob->query("point") / 100;
	improve = improve / 10 * 10;
	ob->set("point", improve);

	// ���õȴ�ʱ�䣬���3��
	this_object()->set_temp("item/�ȴ�", 3);

	// �����ʱ����������
	remove_call_out("waiting");
	call_out("waiting", 240, me, ob, moye);
	return 1;
}

// ����������¯����ߵ��ߵȼ�
// Ҫ�󣺾� >= 180  �� >= 300  ������Ч�ȼ� >= 50  ���� >= 800 ������� >= 100
// �����ÿ�ķ� 200 ��������������� 10%����ʼʱΪ 70%�����Ϊ 120%
int do_help()
{
	object me;
	int    cost;
	me = this_player();
	if (! me->query_temp("item/׼������"))
	{
		message_vision("�ɽ���$N��Цһ��������ʲô�£������ң�\n", me);
		return 1;
	}
	if (! me->query_temp("item/help") || me->query_temp("item/help") != 1)
	{
		tell_object(me, "���ڲ������æ��ʱ��\n", me);
		return 1;
	}
	if (me->query("jingli") < 180)
	{
		message_vision(HIR "$N��Хһ����˫�ִ���¯�ߣ���������������¯��ͻȻ��ǰһ��...\n" NOR, me);
		tell_object(me, "��е�����˥�ߡ�\n");
        me->set("jingli", 10);
		return 1;
	}
     me->receive_damage("jingli", 180);
	if (me->query("qi") < 300)
	{
		message_vision(HIR "$N��Хһ����˫�ִ���¯�ߣ���������������¯��ͻȻ��ǰһ��...\n" NOR, me);
		tell_object(me, "��е��������̡�\n");
		me->set("qi", 10);
		return 1;
	}
	me->receive_damage("qi", 300);
	cost = me->query_skill("force");
	if (me->query("neili") < 800 || me->query("max_neili")<100 || cost < 50)
	{
		message_vision(HIR "$N��Хһ����˫�ִ���¯�ߣ���������������¯��ͻȻ��ǰһ��...\n" NOR, me);
		tell_object(me, "��е������ݽߡ�\n");
		me->set("neili", 10);
		return 1;
	}
	message_vision(HIC "$N��Хһ����˫�ִ���¯�ߣ�ɲ�Ǽ䣬¯����ڣ�һ���׹⣬ֱ��������\n\n" NOR, me);
	cost = cost * 2 + random(cost * 2);
	if (cost > me->query("max_neili")) cost = me->query("max_neili") - 10;
	if (cost > 1000) cost = 1000;
	if (cost > me->query("neili")) cost = me->query("neili");
	me->set_temp("item/help", 0);
	me->set_temp("item/cost", cost);
	me->add("max_neili", -cost);
	me->add("neili", -cost);
	return 1;
}

int show_order()
{
	object me;
	me = this_object();
	if (! me->query_temp("item/������Ϣ"))
	{
		message_vision("�ɽ�������������������$N��\n", me);
		return 1;
	}
	// ˽����Ϣ
	tell_object(me,"������Ҫ��������������Ϣϵͳ��ȱʡ����������ȻҲ�������Լ�Ϊ����һЩ��������\n"
		       "��Ȼ�ˣ���ò����ñ������Ĵ����־��ޡ�����ķ������¡�\n"
		       "    ����(name):    name �������� Ӣ�Ĵ��š�  (������)\n"
		       "    ����(desc):    desc �������������֡�     (��  ѡ)\n"
		       "    װ��(loadmsg): loadmsg װ��ʱ��������    (��  ѡ)\n"
		       "    ����(backmsg): backmsg ����ʱ��������    (��  ѡ)\n"
		       "����ʱ��������\\n������Ӣ�Ĵ����������е����ֶ���������ɫ��ʹ����ɫ�ķ������Բ���nick ��\n"
		       "�������ÿ����ˣ����������(finish)��Ҫ��û������������������� < ���� >\n\n" NOR);
	return 1;
}

int waiting(object me, object ob, object moye)
{
	if (! objectp(me))
	{
		message_vision("�ɽ�̾�˿���˵������ô�����ˣ��������ˣ�ȥ�ɣ�\n", this_object());
		if (objectp(moye)) moye->delete_temp("item");
		this_object()->delete_temp("item");
		destruct(ob);
		return 1;
	}
	if (! objectp(present(me, environment())))
	{
		message_vision("�ɽ��ɻ��˵��������ô�ܵ��ˣ����ˣ��ٵ���һ��ɡ�\n", this_object());
	} else
	{
		message_vision("�ɽ���$N������㣬��㣬��ĥ�䡣\n", me);
	}
	if (this_object()->add_temp("item/�ȴ�", -1) <= 0)
	{
		// �ȴ���ʱ
		if (objectp(moye)) moye->delete_temp("item");
		if (objectp(ob)) destruct(ob);
		me->delete_temp("item");
		this_object()->delete_temp("item");
		if (! objectp(present(me, environment())))
		{
			message_vision("�ɽ�������üͷ˵����������ô��ôĥ�䣬���ˣ���Ҫ�Ͳ�Ҫ�ɣ�\n", this_object());
			return 1;
		}
		message_vision("�ɽ�������üͷ��$N˵������������ô��ôĥ�䣬��Ҫ�����ˣ�ˡ���˿\n", this_object());
		return 1;
	}
	call_out("waiting", 240, me, ob, moye);
}

void clear_data()
{
	object ob;
	object moye;
	if (objectp(moye = present("Īа", environment())))
	{
		moye->delete_temp("item");
	}
	if (objectp(ob = present(this_object()->query_temp("item/������"), this_object())))
	{
		destruct(ob);
	}
	this_player()->delete_temp("item");
	this_object()->delete_temp("item");
	remove_call_out("waiting");
}

object set_item(string arg1, string arg2)
{
	object ob;
	object moye;
	if (! objectp(ob = present(this_object()->query_temp("item/������"), this_object())))
	{
		// ���ݲ��ԣ�����������BUG��ɣ�Ҳ��������Ϊ�ɽ���update��
		write("ϵͳ���ϣ����ݲ�һ�£����޷������������Ƶ���......\n");
		clear_data();
		// ����ʧ�ܣ�ֹͣ����
		return 0;
	}
	// ������Ϣ
	ob->set(arg1, arg2);
	return ob;
}

int do_name(string arg)
{
	object me;
	string sname, sid;

	me = this_player();
	if (! me->query_temp("item/������Ϣ")) return 0;
	if (! arg || sscanf(arg, "%s %s", sname, sid) != 2)
	{
		write("��ʽ���ԣ�Ӧ���ǣ����� �������� Ӣ��ID\n���磺���� ���� sword\n");
		return 1;
	}

	// ILLEGAL_STR = "." ��ʾ�Ƿ�������
	if ((sname = converts(sname, 12, COLORABLE)) == ILLEGAL_STR) return 1;
	if (( sid = converts(sid, 6, NOCOLOR)) == ILLEGAL_STR) return 1;
	if (! objectp(set_item("item/name", sname))) return 1;
	if (! objectp(set_item("item/id", sid))) return 1;
	write("���֣�" + sname + "    ���ţ�" + sid + "\n");
	return 1;
}

int do_desc(string arg)
{
	object ob;
	object me;

	me = this_player();
	if (! me->query_temp("item/������Ϣ")) return 0;
	if (! arg)
	{
		write("��ʽ���ԣ�Ӧ���ǣ�desc ���������֡�\n���磺һ�ѷ�����$n\\n������������������ -- ����\\n��ʾ���У�$n������ߡ�\n");
		return 1;
	}
	if ((arg = converts(arg, 100, COLORABLE)) == ILLEGAL_STR) return 1;
	if (! objectp(ob = set_item("long", arg))) return 1;
	arg = replace_string(arg, "$n", ob->query("item/name"));
	ob->set("long", arg);
	arg = replace_string(arg, "\\n", "\n");
	write("����۲�����ʱ�򽫻��������������\n" + arg + "\n");
	return 1;
}

int do_loadmsg(string arg)
{
	object ob;
	object me;

	me = this_player();
	if (! me->query_temp("item/������Ϣ")) return 0;
	if (! arg)
	{
		write("��ʽ���ԣ�Ӧ���ǣ�loadmsg ���������֡�\n���磺$N����һ�������һ�ѷ��������� -- ����$N��ʾ���Լ���$n������ߡ�\n");
		return 1;
	}
	if ((arg = converts(arg, 100, COLORABLE)) == ILLEGAL_STR) return 1;
	// ��������������װ�����������ļ�ʱ�Զ�ѡ��һ����Ϣ
	if (! objectp(ob = set_item("wield_msg", arg))) return 1;
	if (! objectp(ob = set_item("wear_msg", arg))) return 1;
	arg = replace_string(arg, "\\n", "\n");
	arg = replace_string(arg, "$N", me->query("name"));
	arg = replace_string(arg, "$n", ob->query("item/name"));
	write("����װ������ʱ�򽫻��������������\n" + arg + "\n");
	return 1;
}

int do_backmsg(string arg)
{
	object ob;
	object me;

	me = this_player();
	if (! me->query_temp("item/������Ϣ")) return 0;
	if (! arg)
	{
		write("��ʽ���ԣ�Ӧ���ǣ�backmsg ���������֡�\n���磺$N����һ�ӣ�$n�������ڡ� -- ����$N��ʾ���Լ���$n������ߡ�\n");
		return 1;
	}
	if ((arg = converts(arg, 100, COLORABLE)) == ILLEGAL_STR) return 1;
	// ��������������װ�����������ļ�ʱ�Զ�ѡ��һ����Ϣ
	if (! objectp(ob = set_item("unwield_msg", arg))) return 1;
	if (! objectp(ob = set_item("remove_msg", arg))) return 1;
	arg = replace_string(arg, "\\n", "\n");
	arg = replace_string(arg, "$N", me->query("name"));
	arg = replace_string(arg, "$n", ob->query("item/name"));
	write("�����ջ�����ʱ�򽫻��������������\n" + arg + "\n");
	return 1;
}

// ת���ַ����е���ɫ��־
string converts(string arg, int max_len, int no_color)
{
	// ȥ���ַ����еĿո����ţ����ⱻ�����������ƻ�
	arg = replace_string(arg, " ", ""); 
	arg = replace_string(arg, "\"", "'");

	if (no_color)
	{
		arg = replace_string(arg, "$BLK$", "");
		arg = replace_string(arg, "$RED$", "");
		arg = replace_string(arg, "$GRN$", "");
		arg = replace_string(arg, "$YEL$", "");
		arg = replace_string(arg, "$BLU$", "");
		arg = replace_string(arg, "$MAG$", "");
		arg = replace_string(arg, "$CYN$", "");
		arg = replace_string(arg, "$WHT$", "");
		arg = replace_string(arg, "$HIR$", "");
		arg = replace_string(arg, "$HIG$", "");
		arg = replace_string(arg, "$HIY$", "");
		arg = replace_string(arg, "$HIB$", "");
		arg = replace_string(arg, "$HIM$", "");
		arg = replace_string(arg, "$HIC$", "");
		arg = replace_string(arg, "$HIW$", "");
		arg = replace_string(arg, "$NOR$", "");
	} else
	{
		arg = replace_string(arg, "$BLK$", BLK);
		arg = replace_string(arg, "$RED$", RED);
		arg = replace_string(arg, "$GRN$", GRN);
		arg = replace_string(arg, "$YEL$", YEL);
		arg = replace_string(arg, "$BLU$", BLU);
		arg = replace_string(arg, "$MAG$", MAG);
		arg = replace_string(arg, "$CYN$", CYN);
		arg = replace_string(arg, "$WHT$", WHT);
		arg = replace_string(arg, "$HIR$", HIR);
		arg = replace_string(arg, "$HIG$", HIG);
		arg = replace_string(arg, "$HIY$", HIY);
		arg = replace_string(arg, "$HIB$", HIB);
		arg = replace_string(arg, "$HIM$", HIM);
		arg = replace_string(arg, "$HIC$", HIC);
		arg = replace_string(arg, "$HIW$", HIW);
		arg = replace_string(arg, "$NOR$", NOR);
		arg = arg + NOR;
	}
	if (strlen(arg) > max_len + 12)
	{
		write("�Բ�������ַ���̫���ˣ��벻Ҫ���볬��" + chinese_number(max_len) +
		      "���ַ������ַ�����\n");
		// ��ʾ�Ƿ�������
		return ILLEGAL_STR;
	}
	return arg;
}

int do_finish()
{
	object me;
	object ob;
	object moye;
	string msg;

	me = this_player();
	if (! me->query_temp("item/������Ϣ")) return 0;

	if (! objectp(ob = present(this_object()->query_temp("item/������"), this_object())))
	{
		// ���ݲ��ԣ�����������BUG��ɣ�Ҳ��������Ϊ�ɽ���update��
		write("ϵͳ���ϣ����ݲ�һ�£����޷�������Ƶ��ߣ�\n");
		me->delete_temp("item");
		this_object()->delete_temp("item");
		if (objectp(moye = present("Īа", environment())))
		{
			moye->delete_temp("item");
		}
		// ����ʧ�ܣ�ֹͣ����
		return 0;
	}
	
	if (! ob->query("item/name"))
	{
		message_vision("�ɽ�����$Nһ�ۣ�˵��������ô�ܲ�����������֣���Ҫ�ǲ���Ҫ�˾����ˣ�\n", me);
		return 1;
	}

	// ��ʾ player �������Ϣ
	msg = sprintf("�ɽ���$N˵����ĵ����������£��뿴����û�д�\n");
	message_vision(msg, me);
	// ˽����Ϣ
	msg = sprintf("�������֣�%s   ����Ӣ�Ĵ��ţ�%s\n",
		      ob->query("item/name"), ob->query("item/id"));
	if (ob->query("long") != "")
		msg += sprintf("����������£�\n%s\n", ob->query("long"));
	else
		msg += "����ȱʡ�����������\n";

	if (ob->query("wield_msg") != "")
		msg += sprintf("װ��ʱ�������£�\n%s\n", ob->query("wield_msg"));
	else
		msg += "װ��ʱ����ȱʡ��������\n";

	if (ob->query("unwield_msg") != "")
		msg += sprintf("�ջ�ʱ�������£�\n%s\n", ob->query("unwield_msg"));
	else
		msg += "�ջ�ʱ����ȱʡ��������\n";
		msg += "���û�����⣬�Ϳ��Լ���������(y/n):";
	msg = replace_string(msg, "$N", me->query("name"));
	msg = replace_string(msg, "$n", ob->query("item/name"));

	tell_object(me, msg);

	// �ж� player �Ƿ�������ɵ���
	input_to("confirm_make", ob);

	return 1;
}

int confirm_make(string arg, object ob)
{
	object me;
	object moye;
	string item_filename;

	me = this_player();

	if (arg == "y" || arg == "Y")
	{
		message_vision("�ɽ���$N˵�����ã����Ͼͺã�\n", this_player());
		if ((item_filename = create_file(ob)) != "")
		{
			destruct(ob);
			ob = new(item_filename);
			ob->move(me);
			message_vision("�ɽ���" + ob->query("name") + "������$N��\n", me);
		}

		if (objectp(moye = present("moye", environment())))
		{
			moye->delete_temp("item");
		}
		me->delete_temp("item");
		this_object()->delete_temp("item");
		remove_call_out("waiting");
		return 1;
	}
	return 1;
}
