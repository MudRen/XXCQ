// bh_lukou1.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "·��");
	set("long", @LONG
�����Ǹ�����·�ڣ�������С���ţ�����������ʮ�����֣�
�ϱ߾��������

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"xiaojieqiao",
		"south" : __DIR__"wazixiang1",
		"east" : __DIR__"tianshuixiang1",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
