//nzlange1.c		�Ĵ����š���ʯС·

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
			"north" : __DIR__"chaifang",
			"west" : __DIR__"nzlangn3",
			"east" : __DIR__"nzlange2",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}