// xiaojieqiao.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "С����");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"tongkujie2",
		"south" : __DIR__"bh_lukou1",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}