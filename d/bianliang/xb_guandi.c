// xb_guandi.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "πŸ€°");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"hongbujie2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "„Í¡∫");
	setup();
	replace_program(ROOM);
}