//wzlang1.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ƹ���������ȡ�����ͨ�����ŵı��������ϱ�������
����������ʱ�Ĵ���������ȡ�
LONG);
	set("exits", ([
//			"south" : __DIR__"liangong",
			"north" : __DIR__"wselfroom1",
			"west" : __DIR__"wzlang2",
			"east" : __DIR__"nzlang1",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}