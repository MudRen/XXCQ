// tongkujie2.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "Õ¥ø‡Ω÷");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"tongkujie1",
		"south" : __DIR__"xiaojieqiao",
		"west" : __DIR__"shh_niangmiao",
		"east" : __DIR__"shh_tongkuxiang",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "„Í¡∫");
	setup();
	replace_program(ROOM);
}