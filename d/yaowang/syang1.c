// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
inherit ROOM;
string* npcs = ({
	__DIR__"npc/xiong",
	__DIR__"npc/he",
	__DIR__"npc/lu",
	__DIR__"npc/xie",
	__DIR__"npc/she",
});
void create()
{
        set("short", "������");
        set("long",@LONG
������ҩ���ȵ�����������������һЩ����ȡҩ�ĵĶ������԰Ѷ���
׽(zhuo)�����׳�ȥɱ��ȡҩ��
LONG );
	set("area", "ҩ����");
	set("areb", "������");
	set("exits", ([
         "south" : __DIR__"xiaolu2",
	]));
        set("objects", ([
	npcs[random(sizeof(npcs))] :random(2),
	npcs[random(sizeof(npcs))] :random(2),
	npcs[random(sizeof(npcs))] :random(2),
	npcs[random(sizeof(npcs))] :random(2),
	npcs[random(sizeof(npcs))] :random(2),
	]) );
        setup();
}

void init()
{
	add_action("do_zhiliao", "zhuo");
}

int do_zhiliao(string arg)
{
	object me, ob;
	me=this_player();

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
         || me->query("party/level")<3 ) {
		return notify_fail("�㻹����ȡҩ�أ�׽�����ʲô��\n");
	}

	if( !arg || !objectp(ob = present(arg, environment(me))) )
		return notify_fail("ָ���ʽ��zhuo <ID> \n");

        if( !ob->query("yaowang_zhuo") )
                return notify_fail("�����������׽��\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ���أ�\n");

	ob->set_leader(me);
	message_vision("$N��$n�ٻ���������$n�͹ԹԵø���$N��\n", me, ob);
	return 1;
}
