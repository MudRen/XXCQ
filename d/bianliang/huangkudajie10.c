// huangkudajie10.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�ƿ���");
	set("long", @LONG
    �����ǻƿ��ֵľ�ͷ���򶫱�ɵ������ǵĶ������ˡ�Զ�������ٱ���ߺ��
�������Զ�֪�ٱ��������������������������ˡ�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"budongfeipu",
		"west" : __DIR__"mi_lukou",
		"east" : __DIR__"dongchengmen",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
