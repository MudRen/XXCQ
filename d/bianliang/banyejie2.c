// banyejie2.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��ҹ��");
	set("long", @LONG
����������½����ų�֪���������ĵ�˰Ǯ�������̵ģ��ô���ʯ�����·�棬
ʮ�ֻ�����

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"banyejie1",
		"east" : __DIR__"bh_lukou4",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
