//houroad1.c		�Ĵ����š���ʯС·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
�����Ǻ�լ�������ʯС·�������Ŀ�������Զ������������
ˮ����չĿ��ȥ�Ѿ����Կ����ڷ���ҡ�ڵ�ƬƬ��Ҷ��һ����紵��
����һ�ɺɻ����㡣
LONG);
	set("exits", ([
			"west" : __DIR__"houroad2",
			"south" : __DIR__"nzlangw1",
			"north" : __DIR__"yaotian2",
	]));
	set("objects", ([__DIR__"npc/jiading" : 1,]));
	set("area", "����");
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( ( (dir == "north") || (dir == "west") )&& ( (string)me->query("family/family_name") != "�Ĵ�����") && !wizardp(me) && (objectp( present("jia ding", environment(me)) ) ))
		return notify_fail("�Ҷ�һ���֣�˵�������㲻���������ˣ���������ǰ���ˣ���\n");

	if ( ((dir == "north") || (dir == "west")) && !wizardp(me) && (objectp( present("jia ding", environment(me)) ) ) && !me->query_temp("tangmen") )
		return notify_fail("�Ҷ�һ����˵������û���������ǲ��ܽ�������ģ���\n");

	if ( (dir == "north") && !wizardp(me) && (objectp( present("jia ding", environment(me)) ) ) && !me->query_temp("yao") )
		return notify_fail("�Ҷ�һ����˵������û���������ǲ��ܽ���ҩ�Եģ���\n");

		return ::valid_leave(me, dir);
}