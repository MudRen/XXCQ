// huangkudajie9.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�ƿ���");
	set("long", @LONG
        ��ִ���������ͻȻ����������·�߿�ʼ����һЩ����֮��ķ��ݣ�
���ڳ��������˷��࣬����ĵ�������Ҳ�ȱ𴦺�����������������������ˡ�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"south" : __DIR__"mitianmengmen",
		"west" : __DIR__"huangkudajie8",
		"east" : __DIR__"mi_lukou",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
