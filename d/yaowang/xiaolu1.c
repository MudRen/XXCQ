// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ������ʯ�̳ɵ�С·������ͨ��ҩ����ɽׯ�ĺ�Ժ����������
����һ���������������������ţ�����������һЩ���
LONG );
	set("area", "ҩ����");
	set("areb", "С·1");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"xiaolu2",
		"south" : __DIR__"houyuan",
		"west" : __DIR__"liandan1",
		"east" : __DIR__"liandan2",
	]));

        create_door("north", "����", "south", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="north" 
        && me->query("party/party_name")!=HIB"ҩ����"NOR)
                return notify_fail("����ֻ��ҩ�������˲��ܹ�ȥ��\n");
        return ::valid_leave(me, dir);
}
