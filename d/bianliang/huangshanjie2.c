// huangshanjie2.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"huangshanjie1",
		"south" : __DIR__"huangshanjie3",
		"west" : __DIR__"duchang",
		"east" : __DIR__"xiyuan",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}