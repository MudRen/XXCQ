// pobanmen2.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�ư���");
	set("long", @LONG
����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ�����ĵ�û�м������ˣ������Ǹ���լ��

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"pobanmen1",
		"south" : __DIR__"pobanmen3",
		"west" : __DIR__"minzhai",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
