// by_xunmengyuan.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "Ѱ��԰");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"southwest" : __DIR__"by_xiaojing",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}