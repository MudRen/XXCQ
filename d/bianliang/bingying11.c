// bingying1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "פ����Ӫ");
	set("long", @LONG
����һ�䰴�о������õ�Ӫ�����������У���̺�̵أ��߽�������
�е�һ�������ѹ����һ�������硢�ڼ׵Ľ������ڰ���������ٷ���
���ԣ��������������Ŀ�����㣬����λ����ȴͷҲ��̧��������������
�İ���
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"east" : __DIR__"bingying1",
	]));

	set("objects", ([
		__DIR__"npc/lenghuer" : 1,
	]));

	set("area", "����");

	setup();

	replace_program(ROOM);
}