// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ������ʯ�̳ɵ�С·������ͨ��ҩ����ɽׯ�ĺ�Ժ��������һ��
�����������������׳���
LONG );
	set("area", "ҩ����");
	set("areb", "С·2");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"xiaolu1",
		"west" : __DIR__"syang",
         "north" : __DIR__"syang1",
		"east" : __DIR__"tuzai",
	]));

        create_door("south", "����", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="south" 
        && me->query("party/party_name")!=HIB"ҩ����"NOR)
                return notify_fail("����ֻ��ҩ�������˲��ܹ�ȥ��\n");
        return ::valid_leave(me, dir);
}
