// kushuipu1.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��ˮ��");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"bh_lukou4",
		"east" : __DIR__"kushuipu2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
