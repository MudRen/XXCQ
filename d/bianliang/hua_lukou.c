// hua_lukou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "·��");
	set("long", @LONG
������һ��������·�ڣ�·�ϵ�����������ɫ�ҴҵĿ첽��������խ
խ��С���Ȼһ������Ϯ�������ʹ�˲��ɵüӿ��Լ��ĽŲ���������
�������ߣ��͵����뻨����������լ�ˡ�
LONG);	
	set("valid_startroom",1);

        set("outdoors", "bianliang");

	set("exits", ([
                "north" : __DIR__"hongbujie7",
		"east" : __DIR__"huangkudajie4",
		"west" : __DIR__"huangkudajie3",
	]));

	set("area", "����");

	setup();

	replace_program(ROOM);
}
