//tangwen.c		�Ĵ����š���������

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ª�����ҡ�����ֻ��һ��Ӳľ����һ����ľ������
����ס������̫̫�����������š�
LONG);
	set("exits", ([
			"east" : __DIR__"nzlang2",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/tangwen" : 1,]));
	setup();
	replace_program(ROOM);
}