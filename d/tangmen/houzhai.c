//houzhai.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
���������Ƹ��լ���������򱱾������ŵĴ�������̫̫������
��������Ҫ��������̫̫�Ʊȵ��컹�ѣ�����������һ��񷿣���
����ͨ���Ժ��С·��
LONG);
	set("exits", ([
			"south" : __DIR__"nzlang1",
			"north" : __DIR__"nzlang2",
			"west" : __DIR__"houroad1",
			"east" : __DIR__"chaifang",
	]));
	set("objects", ([__DIR__"npc/tangkan" : 1,]));
	set("area", "����");
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( (dir == "north") && ( (string)me->query("family/family_name") != "�Ĵ�����") )
		return notify_fail("�㲻���������ˣ���������ǰ���ˣ�\n");

	return ::valid_leave(me, dir);
}