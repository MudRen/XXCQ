// heibujie5.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�ڲ���");
	set("long", @LONG
������һ����������Ĵ���ϡ��������������������ӵ���
�ˣ����Ŵ󳵵���������������ǳ����֡���ʱ����������
�������߷ɳ۶���������һ·������

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"heibujie4",
		"south" : __DIR__"heibujie6",
//		"west" : __DIR__"xb_guandi",
//		"east" : __DIR__"xb_qingniugong",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
