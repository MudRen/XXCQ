// tsh_datang.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "¥ÛÃ√");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"tsh_neitang",
		"south" : __DIR__"tsh_huiketing",
		"east" : __DIR__"tsh_restroom",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "„Í¡∫");
	setup();
	replace_program(ROOM);
}