// huangkudajie1.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�ƿ���");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"northwest" : __DIR__"lvjinnong",
		"west" : __DIR__"xichengmen",
		"east" : __DIR__"wen_lukou",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}