// xiaotianshuixiang.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "Ð¡ÌðË®Ïï");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"tianshuixiang2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "ãêÁº");
	setup();
	replace_program(ROOM);
}