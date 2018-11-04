// lianbianshi.c �����ң��ɽ�Īа�ڴ����Ƹ��ֵ���
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "������" NOR);
	set("long", @LONG
	���������޵ĵط����ɽ����������Ʊ�ͯ��ר�����������޵Ĵ������ݽ�
����һ����¯������ϵ��һЩ˿���������洵�����·��裬һ��Ů��ĬĬ������¯
�ߣ�һ�������������������΢΢һЦ���������
LONG
	);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhangbian" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/������"))
	{
		// ����Ʊ�ͯ������������߲�����������ڣ��Ͳ���ʾ�κ���Ϣ
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("�Ʊ�ͯ�Ӷ�$N�������ˣ�������ʦ���ɡ�\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("�Ʊ�ͯ�Ӷ�$N˵�������߰�����û������ء�\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("�Ʊ�ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("�Ʊ�ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
