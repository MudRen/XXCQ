// bushuiting.c

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short", HIC"��ˮͤ"NOR);
         set("long",@long
���Ǻ��е�һ��Сͤ�ӣ�������ȥ����������(tiaowang)�����������
��ɫ,�����Ŀ�������ͤ�ӱ��Ͽ̻��Ž���ˮ������˷羰�����˲�������
���롣
long);
         set("exits",([
             "north" : __DIR__"muqiao",
]));
         set("item_desc", ([
             "liang" : "�������Ϻõ��ľ����,���滹��ʮ�ֹŹֵ��ֻ���\n",
]));
	 setup();
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan(string arg)
{
	mixed *local;                                                                	
	object me;
	me = this_player();
	local = localtime(time() * 60);
	if(!living(me)) return 0;
	if(me->is_fighting())
		return notify_fail("����������ս�������ﻹ������ȥ��������������\n");
	if(local[2] < 5 && local[2] > 20) 
	{
		tell_object(me, "���������������ȥ������һƬ�����ʲô��û�п�����\n");
	}
	else
	{
		tell_object(me,"ԲԲ��һ�������, ���ü��������м���С����
С�����ƺ���ЩС�ڵ����ƶ�����֪����ʲôˮ�����ҰѼ��\n");                                              
	}
	message("vision", "$N˫��ֱ�ɵɵ����ź��߷��������\n", environment(me), ({me}));	
	return 1;
}
