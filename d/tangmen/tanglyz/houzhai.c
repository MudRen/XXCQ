//houzhai.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
���������Ƹ��լ���������򱱾������ŵ���ͷ����̫̫������
��������Ҫ��������̫̫�Ʊȵ��컹�ѣ�����������һ��񷿣���
����ͨ���Ժ��С·��
LONG);
	set("exits", ([
			"north" : __DIR__"nzlang2",
	]));
	set("objects", ([__DIR__"npc/tangsi" : 1,]));
	set("area", "����");
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( (dir == "north") && ( (string)me->query("family/family_name") != "�Ĵ�����") && !wizardp(me) && (objectp( present("tang si", environment(me)) ) ))
		return notify_fail("��˼һ���֣�˵�������㲻���������ˣ���������ǰ���ˣ���\n");
	else
		return ::valid_leave(me, dir);
}