// tianshuixiang1.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��ˮ��");
	set("long", @LONG
�첼�ֵ�������ƶ����յľ۾�������ˮ��������������ֵ���Ҳ
�Ե��������ҵöࡣ

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"bh_lukou1",
		"east" : __DIR__"tianshuixiang2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
