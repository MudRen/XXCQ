// Obj �����ֵ� ��ҩ
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����", ({"cao zi"}));
	set_weight(10);
	set("no_clean_up", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������ɫ�Ĳ��ѣ����������(zhong)�᳤�ɲ�ҩ��\n");
		set("value", 10);
	}
	setup();
}

void init()
{
	add_action("do_zhong", "zhong");
}

int do_zhong(string arg)
{
	object ob, me, where;

	me = this_player();
	ob = this_object();
	where=environment(me);

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
		|| me->query("party/level")<3 )
		return notify_fail("�㲻����ֲ��ҩ��\n");

	if(me->is_fighting() || me->is_busy())
		return notify_fail("���æ��ûʱ�䡣\n");

	if( !arg || !present(arg, me))
		return notify_fail("ָ���ʽ��zhong cao zi\n");

	if( !where->query("yaotian"))
		return notify_fail("ֻ������ҩ���\n");

	if( where->query("zhongyao")>=10)
		return notify_fail("�����Ѿ�û�ط���ҩ���ˡ�\n");

	if( me->query("jingli") <= 20)
		return notify_fail("��̫���ˣ���������Ϣһ�°ɣ�\n");

	if( ob->query("value")!=10)
		return notify_fail("�Ѿ����ڵ����ˣ�\n");

	message_vision("$N���Ὣ$n���ڵ��\n", me, ob);

	ob->move(where);
/*
		remove_call_out("grow_a");
		remove_call_out("grow_b");
		remove_call_out("grow_c");
		remove_call_out("grow_d");
		remove_call_out("grow_e");
*/
	message_vision(WHT"��������������ѿ��\n"NOR, ob);
        set_name( "С���" , ({"xiao qingcao"}));
	set("long", "һ�국��ɫ��С��ݣ���û�г��ɡ�\n");
	set("value", 0);
	set("no_get", 1);

	where->add("zhongyao", 1);
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/4));
	me->add("jingli", -20);
	call_out("grow_a", 1, ob);
	return 1;
}

int grow_a(object ob)
{
	int i=100+random(50);
	set("no_get", 1);
	call_out("grow_b", i, ob);
	return 1;
}

int grow_b(object ob)
{
        int i=100+random(100);
	message_vision(WHT"С��������س�����һƬҶ�ӡ�\n"NOR, ob);
        set_name( "���" , ({"qingcao"}));
	set("long", "һ�국��ɫ����ݣ���û�г��ɡ�\n");
        call_out("grow_c", i, ob);
        return 1;
}

int grow_c(object ob)
{
        int i=100+random(200);
	message_vision(WHT"��������س�����һ�㡣\n"NOR, ob);
        call_out("grow_d", i, ob);  
        return 1;
}

int grow_d(object ob)
{
        int i=100+random(400);
	message_vision(WHT"����������ֳ�����һЩ��\n"NOR, ob);
        set_name( CYN"�����"NOR , ({"da qingcao"}));
	set("long", "һ����ɫ�Ĵ���ݣ���û�г��ɡ�\n");
        call_out("grow_e", i, ob);  
        return 1;
}
/*
int grow_e(object ob)
{
	object obj;
	int i=random(4);

	if(i=0) { obj=new(__DIR__"renshen"); }
	if(i=1) { obj=new(__DIR__"shouwu"); }
	if(i=2) { obj=new(__DIR__"wugencao"); }
	if(i=3) { obj=new(__DIR__"duanchang"); }

	message_vision(WHT"����ݳ����ˣ�������������(dig)��\n"NOR, ob);
	obj->move(environment(ob));
	destruct(ob);
        return 1;
}
*/
int grow_e(object ob)
{
	object obj;

	message_vision(WHT"����ݳ����ˣ�������������(dig)��\n"NOR, ob);
	switch( random(4) ) {
		case 0:
			obj=new(__DIR__"renshen");
			obj->move(environment(ob));
			(environment(ob))->add("zhongyao",-1);
			destruct(ob);
		case 1:
			obj=new(__DIR__"shouwu");
			obj->move(environment(ob));
			(environment(ob))->add("zhongyao",-1);
			destruct(ob);
			break;
		case 2:
			obj=new(__DIR__"wugencao");
			obj->move(environment(ob));
			(environment(ob))->add("zhongyao",-1);
			destruct(ob);
			break;
		case 3:
			obj=new(__DIR__"duanchang");
			obj->move(environment(ob));
			(environment(ob))->add("zhongyao",-1);
			destruct(ob);
			break;
		case 4:
			obj=new(__DIR__"cao");
			obj->move(environment(ob));
			(environment(ob))->add("zhongyao",-1);
			destruct(ob);
			break;
		}
}
