// kushuipu2.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��ˮ��");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣�ϱ߱���һ�þӡ�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"yidejv",
		"west" : __DIR__"kushuipu1",
		"east" : __DIR__"bh_lukou5",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
