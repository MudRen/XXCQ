// tsh_xiaojing.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "С��");
	set("long", @LONG

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"tsh_xiangfang1",
		"northwest" : __DIR__"tsh_xiangfang2",
		"west" : __DIR__"tsh_xiangfang3",
		"southwest" : __DIR__"tsh_xiangfang4",
		"east" : __DIR__"tsh_huiketing",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}