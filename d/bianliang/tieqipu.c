// tieqipu.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG
������һ��������ӣ��ӻ�¯��ð���Ļ�⽫ǽ��ӳ��ͨ�죬���ӵ�
��������������ӡ������������ȸ�ʽ���������������������õ�
�������졣
LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"huangkudajie7",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
