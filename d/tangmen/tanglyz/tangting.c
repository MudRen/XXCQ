//tangting.c		�Ĵ����š���������

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ª�����ҡ�����ֻ��һ��Ӳľ����һ����ľ������
����ס������̫̫��������������
LONG);
	set("exits", ([
			"west" : __DIR__"nzlang3",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/tangting" : 1,]));
	setup();
	replace_program(ROOM);
}