//nzlangn1.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
����һ����ʯ�̾͵�С·��������������������̫�࣬�ֲڵ���
ʯ�Ѿ���ĥ�Ĺ⻬�羵��һЩ���ŵĵ��������������ﻹ���Ǻ���
�֡�������
LONG);
	set("exits", ([
			"south" : __DIR__"neiyuan",
			"north" : __DIR__"nzlangn2",
			"east" : __DIR__"erukou",
			"west" : __DIR__"wrukou",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/tangfang" : 1,]));
	setup();
	replace_program(ROOM);
}