// mi_lukou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "·��");
	set("long", @LONG
    ������һ��������·�ڣ�·�ϵ�����������ɫ���ŵĿ첽����������
����С���Ȼһ������Ϯ�������ʹ�˲��ɵüӿ��Լ��ĽŲ���������
�������ߣ��͵����ư����ˡ�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"pobanmen5",
		"east" : __DIR__"huangkudajie10",
		"west" : __DIR__"huangkudajie9",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
