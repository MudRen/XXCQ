// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���׳�");
	set("long", @LONG
������ҩ���ȵ����׳�����ר����������ҩ���������Ķ��
ȡҩ���õģ�����԰Ѷ���׽�������������(sha)��
LONG );
	set("area", "ҩ����");
	set("areb", "���׳�");
	set("no_fight", 1);
	set("exits", ([
		"west" : __DIR__"xiaolu2",
	]));
	setup();
}

void init()
{
	add_action("do_sha", "sha");
}

int do_sha(string arg)
{
	object me, ob;
	me=this_player();

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
         || me->query("party/level")<3 ) {
		return notify_fail("�㻹����ȡҩ�أ�����ɱ���\n");
	}

	if( !arg || !objectp(ob = present(arg, environment(me))) )
		return notify_fail("ָ���ʽ��sha <ID> \n");

        if( !ob->query("yaowang_zhuo") )
                return notify_fail("�����������������ɱ��\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ���أ�\n");

	me->improve_skill("healing", ((int)me->query_skill("healing",1)/2));
	message_vision(HIR"$N��$n�������ײ��ϣ�һ��������ȥ��\n"NOR, me, ob);
	ob->die();
	return 1;
}
