// bh_lukou5.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "·��");
	set("long", @LONG
���Ǹ�����·�ڣ������ǿ�ˮ�̣��������ư��ţ������������������š�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"qixianqiao",
		"south" : __DIR__"pobanmen1",
		"west" : __DIR__"kushuipu2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
