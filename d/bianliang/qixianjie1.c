// qixianjie1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "���ͽ�");
	set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣�����Ǿ͹�ʦ��������������ʷ����

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"by_lukou",
		"south" : __DIR__"qixianjie2",
		"west" : __DIR__"by_guoshifu",
		"east" : __DIR__"by_yushifu",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
