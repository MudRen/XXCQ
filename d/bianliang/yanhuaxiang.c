// yanhuaxiang.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�̻���");
	set("long", @LONG
������С�ÿ�춼�в����˽�������������Ժ�֡�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"quyuanjie1",
		"west" : __DIR__"hongbujie3",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
