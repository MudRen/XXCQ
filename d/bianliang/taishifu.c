// taishifu.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "̫ʦ��");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"tsh_huiketing",
		"south" : __DIR__"tsh_lukou",
		"west" : __DIR__"tsh_menwei1",
		"east" : __DIR__"tsh_menwei2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}