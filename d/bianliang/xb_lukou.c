// xb_lukou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "·��");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"xingbu",
		"south" : __DIR__"hongbujie1",
		"east" : __DIR__"baikudajie3",
		"west" : __DIR__"baikudajie2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}