// caishikou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "���п�");
	set("long", @LONG
һ�������;��������������ܿ�ȥ�����˼��٣��������ķ�����
ȫ��ͬ��������������Ĳ��п��ˡ�Ψһ��ʹ�������ֵ����ӣ�ֻ���ڴ�ն
���˵�ʱ����ܳ��֡�һ��ľ̨�Ӵ������棬������������Ѫ����
LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"heibujie7",
		"west" : __DIR__"huangkudajie7",
		"east" : __DIR__"huangkudajie8",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
