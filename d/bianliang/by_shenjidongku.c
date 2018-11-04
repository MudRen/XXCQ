// by_shenjidongku.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "…Óº«∂¥øﬂ");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"by_datang",
		"northwest" : __DIR__"by_shanjing",
		"north" : __DIR__"by_bieshu",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "„Í¡∫");
	setup();
	replace_program(ROOM);
}