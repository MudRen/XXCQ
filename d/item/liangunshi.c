// lianjianshi.c �����ң��ɽ�Īа�ڴ����Ƹ��ֵ���
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "������" NOR);
	set("long", @LONG
	�����������ĵط����ɽ����������ƹ�ͯ��ר�������������Ĵ������ݽ�
����һ����¯����ⰵ���ģ��������һ�����õĹ�����һ��ͯ�����е�����һ�ԣ�
���������������һЦ��
LONG
	);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhanggun" : 1,
	]));

	set("exits", ([
		"southwest" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/������"))
	{
		// ����ƹ�ͯ������������߲�����������ڣ��Ͳ���ʾ�κ���Ϣ
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("�ƹ�ͯ�Ӷ�$N�����պù�����һ��Ҫ������ʦ������\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("�ƹ�ͯ�Ӷ�$N˵��������ô������ˣ���û������ء�\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("�ƹ�ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("�ƹ�ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
