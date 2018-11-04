// Room: /d/shaolin/zhulin6.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���ʯ");
	set("long", @LONG
�����ʯ���Ǵ�Ħ�ɺ�����������½���ݣ��������ӭ�����꣬Ψ��
Ħ�ͷ�̽��壬�Ծ����ԣ�Ϊ����������ܽ⣬ƻ��ɽ�������ɽ������
���£�Ϊ����֮ʼ�������̨�����Ǵ�Ħ�����־��޾��꣬���ʱ������
���ϣ���������ʷ�ϴ�����������������д�˵���������书��ѧ�ķ���
��֮���ڡ�
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"zhulin15",
	]));

	set("no_clean_up", 0);

	set("outdoors", "shaolin");

	setup();
}

void init()
{
	add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
	object me;
	mapping myfam;

	me = this_player();
	myfam = (mapping)me->query("family");

	if (me->is_busy())
		return notify_fail("�����ڲ�����ڲ�����\n");

	if (me->query("jingli") < 10)
		return notify_fail("�������޷����о�����ڲ�����\n");

	tell_object(me, "����ڶ�����˫Ŀ΢�أ�������������ͼȥ������Ԫ��һ�����������ľ��硣\n");

	if ( me->query_skill("buddha",1) < 150
	|| me->query_skill("buddha",1) > 250)
		return 1;

	me->add("jingli", ( me->query("bac") - 11 ) / 5 - 4);

	if ( random(1000) < me->query("bac") )
	{
		tell_object(me, HIG"\nͻȻһ˲����е�������޼ž�����̨һƬ�������������ĳ�����һ��ͨ�������磬���á���\n"NOR);
		tell_object(me, HIG"��������ķ���������˽�һ���ļ��\n\n"NOR);
		me->improve_skill("buddha", me->query("bac") * 3 );
		me->start_busy( 3 + random(5) );
		return 1;
	}

	return 1;
}
