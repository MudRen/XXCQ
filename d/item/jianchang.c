// jianchang.c �������ɽ�Īа�ڴ����Ƹ��ֵ���
// Written by Doing Lu 1998/11/3

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIR "����" NOR);
	set("long", @LONG
	�����Ǹɽ�Īа�����ĵط�����Ȼ�ˣ����˽�Ҳ�����������ߡ���������
һ���յ�ͨ��Ļ�¯�����������޵Ļ��磬��¯������һλ��������Ĵ󺺣�����
��¯���Բ���ſ���վ��һλ���ŵ�Ů�ӣ��ƺ������ᣬ�����������������΢
΢һЦ��ǽ�Ϲ���һ������(paizi)������ͨ��һЩС���ӡ�
LONG
	);

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "���Ƹ�������װ��������������̸��\n",
	]));

	set("objects", ([
		"adm/npc/moye" : 1,
		"adm/npc/ganjiang" : 1,
	]));

	set("exits", ([
                "south" : "/d/room/playtown/guandao4",
		"west"      : __DIR__"lianjianshi",	// ������
		"east"      : __DIR__"armorroom",	// ������
		"north"     : __DIR__"lianbianshi",	// ������
		"southeast" : __DIR__"lianchuishi",	// ������
		"southwest" : __DIR__"lianzhangshi",	// ������
		"northeast" : __DIR__"liangunshi",	// ������
		"northwest" : __DIR__"liandaoshi",	// ������
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	object moye;
	// ���ѯ�ʹ�Īа�ı�־
	this_player()->delete_temp("query_moye");

	if (! objectp(moye = present("moye", environment(me))))
	{
		return ::valid_leave(me, dir);
	}
	if ((int) me->query_temp("item/��������") == 1 &&
	    moye->query_temp("item/������ID") == me->query("id"))
	{
		message_vision("Īаһ�Ѱ�$Nץס��˵�������ʲô���Ż����ŵģ���������Ҫ�ˣ�\n", me);
		if (objectp(ob = present(moye->query_temp("item/����"), moye)))
		{
			// ��������
			ob->move(me);
			message_vision("Īа�Ѵ���������$N��\n", me);
		}
		moye->delete_temp("item");
		me->delete_temp("item");
	} else
	if (objectp(present("item permit", me)))
	{
		message_vision("Īа��$NЦ�������ż��պ��ˣ�������Ŷ��\n", me);
		
	} else
	if (me->query_temp("item"))
	{
		message_vision("Īа��$N��������Ҫ�������ߣ�Ҫ���㲻����������Ū�������ǿɲ����𰡡�\n", me);
	}

	return ::valid_leave(me, dir);
}
