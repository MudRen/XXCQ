// qixianjie2.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "���ͽ�");
	set("long", @LONG
����Ĵ�ֽ���Ҫ�ȱ𴦵ĸɾ������ࡣ�����Ϊ������ʦ����Ե�ʣ�
������ʥ���������Ǹ����ûʵ��ӽ�������

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"qixianjie1",
		"south" : __DIR__"qixianqiao",
		"west" : __DIR__"by_shengxianmiao",
		"east" : __DIR__"by_pangfu",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
