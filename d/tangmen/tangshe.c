//tangshe.c		�Ĵ����š���������

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ª�����ҡ�����ֻ��һ��Ӳľ����һ����ľ������
����ס������̫̫�����������ࡣ
LONG);
	set("exits", ([
			"east" : __DIR__"nzlang3",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/tangshe" : 1,]));
	setup();
	replace_program(ROOM);
}