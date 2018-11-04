// by_xiaojing.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "–°æ∂");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"by_datang",
		"northeast" : __DIR__"by_xunmengyuan",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "„Í¡∫");
	setup();
	replace_program(ROOM);
}