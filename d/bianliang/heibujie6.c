// heibujie6.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�ڲ���");
	set("long", @LONG
������һ����������Ĵ���ϡ��������������������ӵ���
�ˣ����Ŵ󳵵���������������ǳ����֡�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"heibujie5",
		"south" : __DIR__"heibujie7",
//		"west" : __DIR__"xb_helianwangfu",
//		"east" : __DIR__"xb_tongguanfu",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
