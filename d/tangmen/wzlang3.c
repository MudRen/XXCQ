//wzlang3.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ƹ���������ȡ�һ���������̱�İ���������ԭ����
��ͨ����Ů���ӵ���Ϣ�ҡ������ɲ�Ҫ�ߴ���ѽ��
LONG);
	set("exits", ([
			"east" : __DIR__"wzlang2",
			"north" : __DIR__"wselfroom3",
//			"south" : __DIR__"grestroom",
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