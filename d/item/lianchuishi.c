// lianjianshi.c �����ң��ɽ�Īа�ڴ����Ƹ��ֵ���
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "������" NOR);
	set("long", @LONG
	�����������ĵط����ɽ����ĵ����ƴ�ͯ��ר�������������Ĵ������ݽ�
����һ����¯����ⰵ���ģ�������Ҳ��æ�����ﵽ�����Ÿ��ָ����Ĵ���������
����һЩû�����ɵĴ��ĳ��Ρ�
LONG
	);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhangchui" : 1,
	]));

	set("exits", ([
		"northwest" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/������"))
	{
		// ����ƴ�ͯ������������߲�����������ڣ��Ͳ���ʾ�κ���Ϣ
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("�ƴ�ͯ�Ӷ�$N�����պô�����һ��Ҫ������ʦ������\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("�ƴ�ͯ�Ӷ�$N˵��������ô������ˣ���û���괸�ء�\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("�ƴ�ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("�ƴ�ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
