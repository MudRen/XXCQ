// bh_lukou3.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "·��");
	set("long", @LONG
���Ǹ�ʮ��·�ڣ�������������ʯ���������������������,������ͨ�˴

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"gongqiao",
		"south" : __DIR__"huangshanjie1",
		"west" : __DIR__"quyuanjie2",
		"east" : __DIR__"banyejie1",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
