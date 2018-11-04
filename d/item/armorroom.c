// armorroom.c �����ң��ɽ�Īа�ڴ����Ƹ��ֵ���
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIC "������" NOR);
	set("long", @LONG
	���������׵ĵط����ɽ��Ķ������Ƽ�ͯ��ר�������������׵Ĵ�������
������ʰ�øɸɾ�����û��һ�����Ķ������ݽ���һ����¯�������Ļ��粻�ϵ�
�������Ա߷���һЩ����ʹ�õĹ��ߡ�һ��ü��Ŀ���ͯ�����ڻ�¯�ԣ�����˼����
����������ƺ��벻���⡣
LONG
	);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/zhangarmor" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"jianchang",		
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object tongzi;

	if (! objectp(tongzi = present("tongzi", environment(me))) || tongzi->query_temp("item/������"))
	{
		me->delete_temp("item");
		return ::valid_leave(me, dir);
	}
	if (objectp(present("jian pi", me)))
	{
		message_vision("�Ƽ�ͯ�Ӷ�$N�����պü������ǵý�����ʦ������ҪŪ���ˡ�\n", me);
	}

	if (me->query_temp("item"))
	{
		message_vision("�Ƽ�ͯ�Ӷ�$N˵��������ô������ˣ���û������ء�\n", me);
		if (me->query_temp("item/mat_id1") &&
		    objectp(ob = present(me->query_temp("item/mat_id1"), tongzi)))
		{
			ob->move(me);
			message_vision("�Ƽ�ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		if (me->query_temp("item/mat_id2") &&
		    objectp(ob = present(me->query_temp("item/mat_id2"), tongzi)))
		{
			ob->move(me);
			message_vision("�Ƽ�ͯ�Ӱ�" + ob->query("name") + "������$N��\n", me);
		}
		me->delete_temp("item");
	}
	return ::valid_leave(me, dir);
}
