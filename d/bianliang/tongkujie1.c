// tongkujie1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "ʹ���");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"shh_lukou",
		"south" : __DIR__"tongkujie2",
		"west" : __DIR__"shh_guandi1",
		"east" : __DIR__"shh_guandi2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}