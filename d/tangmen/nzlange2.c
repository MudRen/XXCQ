//nzlange2.c		�Ĵ����š���ʯС·

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
			"north" : __DIR__"bingqifang",
			"south" : __DIR__"fangjvfang",
			"east" : __DIR__"nzlange3",
			"west" : __DIR__"nzlange1",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
