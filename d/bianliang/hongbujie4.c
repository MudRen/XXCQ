// hongbujie4.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�첼��");
	set("long", @LONG

 ������ȫ�������Ĵ�֣���һ����������ʯ��ֵ������߶�����լ��

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"hongbujie3",
		"south" : __DIR__"hongbujie5",
		"west" : __DIR__"minzhai1",
		"east" : __DIR__"minzhai2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
