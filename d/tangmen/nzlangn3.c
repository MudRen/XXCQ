//nzlangn3.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
����һ����ʯ�̾͵�С·��������������������̫�࣬�ֲڵ���
ʯ�Ѿ���ĥ�Ĺ⻬�羵��һЩ���ŵĵ��������������ﻹ���Ǻ���
�֡�������ͨ��������������������Ů���ӵ���Ϣ���ˡ�
LONG);
	set("exits", ([
			"north" : __DIR__"chufang",
			"west" : __DIR__"nzlangw1",
			"south" : __DIR__"nzlangn2",
			"east" : __DIR__"nzlange1",
	]));
	set("area", "����");
//	set("objects", ([__DIR__"npc/tangfang" : 1,]));
	setup();
	replace_program(ROOM);
}

