// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����ҩ����������ֲ��ҩ����أ�������ò�ҩ������������ֲ��ҩ(zhong)��
�Ȳ�ҩ�ֳ��˾Ϳ�����(dig)������
LONG );
	set("area", "ҩ����");
	set("areb", "�����");
	set("no_clean_up", 1);
	set("yaotian", 1);
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"yaowanggu",
	]));

	setup();
}

void init()
{
	add_action("do_dig", "dig");
//	add_action("do_work", "get");
}

int do_dig(string arg)
{
	object ob, me;
	me = this_player();

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
		|| me->query("party/level")<3 )
		return notify_fail("�㲻����ֲ��ҩ���������ڲ�ҩ��\n");

	if(me->is_fighting() && me->is_busy())
		return notify_fail("���æ��ûʱ�䡣\n");

	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("ָ���ʽ��dig <��ҩID> \n");

	if ( ob->query("dig")!=1 )
		return notify_fail("��������ڲ�����������\n");

	message_vision("$N���Ὣ$n����������\n", me, ob);

	(environment(me))->add("yao",-1);
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/2));
    ob->delete("no_get");
	ob->move(me);
	ob->delete("dig");
	return 1;
}

int do_work()
{
	if( (environment(this_player()))->query("yao")>=1 )
	{
	write("���ﲻ��ʹ�����ָ�\n");
	return 1;
	}
}
