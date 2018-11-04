// lianjianshi.c �����ң��ɽ�Īа�ڴ����Ƹ��ֵ���
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "������" NOR);
	set("long", @LONG
	���������ȵĵط�Ȭ�ɽ�������������ͯ��ר�����������ȵĴ������ݽ�
����һ����¯�����粻�ϵ���Ծ�������Ա߷�������ģ�ߣ�һ��ͯ������ڤ˼��
�룬�ƺ������о���Щģ�ߡ�
LONG
	);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhangzhang" : 1,
	]));

	set("exits", ([
		"northeast" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/������"))
	{
		// �������ͯ������������߲�����������ڣ��Ͳ���ʾ�κ���Ϣ
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("����ͯ�Ӷ�$N�����պ�������һ��Ҫ������ʦ������\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("����ͯ�Ӷ�$N˵��������ô������ˣ���û�������ء�\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("����ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("����ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
