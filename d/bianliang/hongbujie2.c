// hongbujie2.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�첼��");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"hongbujie1",
		"west" : __DIR__"xb_guandi",
		"east" : __DIR__"xb_qingniugong",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}