// tianshuixiang2.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��ˮ��");
	set("long", @LONG
�첼�ֵ�������ƶ����յľ۾�������ˮ��������������ֵ���Ҳ
�Ե��������ҵö࣬������ת�����������ߵ�·�ڡ�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"xiaotianshuixiang",
		"west" : __DIR__"tianshuixiang1",
		"east" : __DIR__"bh_lukou2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
