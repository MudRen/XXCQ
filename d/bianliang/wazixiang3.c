// wazixiang3.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG
�����������ǵ�������,������һ��С��ͬ���ѡ�·���м������ˡ�
��������ڶ��ߡ�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"wazixiang2",
		"south" : __DIR__"wazixiang4",
		"west" : __DIR__"wa_dangpu",
		"east" : __DIR__"xiangbita",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
