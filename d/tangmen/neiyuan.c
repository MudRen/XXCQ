//neiyuan.c		�Ĵ����š���Ժ

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���������Ƹ���Ժ���������򱱾������ŵĺ�������̫̫������
��������Ҫ��������̫̫�Ʊȵ��컹�ѣ�����������һ��񷿣���
����ͨ���Ժ��С·��
LONG);
	set("exits", ([
			"south" : __DIR__"nzlang1",
			"north" : __DIR__"nzlangn1",
//			"west" : __DIR__"houroad1",
//			"east" : __DIR__"chaifang",
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