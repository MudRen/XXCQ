// beidajie1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"xd_lukou",
		"south" : __DIR__"beidajie2",
		"west" : __DIR__"xd_yefu",
		"east" : __DIR__"xd_guandi",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}