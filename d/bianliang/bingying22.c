// bingying2.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "פ����Ӫ");
	set("long", @LONG
����һ�䰴�о������õ�Ӫ�����������У���̺�̵أ�һ��������
˿�׵Ľ����������ĺǳ���һ����٣�������������������վ�����ԣ�
���������Ҵ�һ�¡���һ����������һ��Ҫ�����ͷ�ĸо���
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"west" : __DIR__"bingying2",
	]));

	set("objects", ([
		__DIR__"npc/xianyuchou" : 1,
	]));

	set("area", "����");

	setup();

	replace_program(ROOM);
}