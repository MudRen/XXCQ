//nzlangw3.c		�Ĵ����š���ʯС·

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
			"east" : __DIR__"nzlangw2",
			"west" : __DIR__"shufang",
			"north" : __DIR__"brestroom",
			"south" : __DIR__"grestroom",
	]));
	set("area", "����");
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( (dir == "north") && ( (string)me->query("gender") != "����") )
		return notify_fail("ι�����ﶼ������ѽ��\n");

	if ( (dir == "south") && ((string)me->query("gender") != "Ů��") )
		return notify_fail("ι���ô�Ů������Ϣ�ң����Ź�ģ�\n");

	return ::valid_leave(me, dir);
}