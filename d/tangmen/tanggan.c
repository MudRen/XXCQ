//tanggan.c		�Ĵ����š��Ƹ�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ª�����ҡ�����ֻ��һ��Ӳľ����һ����ľ������
����ס������̫̫���������ƸС�
LONG);
	set("exits", ([
			"west" : __DIR__"nzlang2",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/tanggan" : 1,]));
	setup();
	replace_program(ROOM);
}