// huangkudajie5.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�ƿ���");
	set("long", @LONG
��ִ���������ͻȻ����������·���Ѿ�û�и��ֵ��̡����ˣ���
������ȥ��������Զ���Ǿ������Ĺ㳡�ˡ�������ͨ�򾩳������İ���
�������¸���
LONG);	
	set("valid_startroom",1);

	set("exits", ([
                "west" : __DIR__"huangkudajie4",
		"east" : __DIR__"guangchang",
//              "west" : __DIR__"jiebei3",
	]));

	set("outdoors", "bianliang");
	set("area", "����");

	setup();

	replace_program(ROOM);
}
