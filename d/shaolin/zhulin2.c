// Room: /d/shaolin/zhulin2.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ�������������ܵ�����
�������˼�������Ω�����ߵ��·�棬��ɮ��ľ������΢�紵����Ҷ����
���������������˳���Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"wuqiku",
		"south" : __DIR__"zhulin1",
		"north" : __DIR__"zhulin3",
	]));

	set("outdoors", "shaolin");

	setup();

	replace_program(ROOM);
}

