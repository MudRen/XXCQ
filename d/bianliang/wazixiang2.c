// wazixiang2.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG
�����������ǵ�������,������һ��С��ͬ���ѡ�·���м������ˡ�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"wazixiang1",
		"south" : __DIR__"wazixiang3",
		"west" : __DIR__"miandian",
		"east" : __DIR__"xiaozuoweifang",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
