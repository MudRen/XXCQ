// quyuanjie1.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��Ժ��");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"yanhuaxiang",
		"west" : __DIR__"bh_lukou2",
		"east" : __DIR__"quyuanjie2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}