// beidajie2.c  by winder

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
		"north" : __DIR__"beidajie1",
		"south" : __DIR__"gongqiao",
		"west" : __DIR__"xd_liangshifu",
		"east" : __DIR__"xd_kongquelou",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}