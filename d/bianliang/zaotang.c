// zaotang.c  by winder

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "����ش���");
	set("long", @LONG
����ذ����ϵ����ɾ��ǲ�ͬ���죬������һƬ�ؽ࣬����һ���Ҷ�
����̫���ױ���ġ��ػ����塱�ĸ����֡��ڴ��������ж�ʮ������Σ�
��������Ϣ��һ��С��������ȥ��Ϊ�����Ƿ��񡣴������Ҹ���һ���ţ�
���ϵĲ������Ϸֱ�д�С��С�����Ů����������
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"west" : __DIR__"huangshanjie3",
		"north" : __DIR__"boywash",
		"south" : __DIR__"girlwash",
	]));

	set("objects", ([
		__DIR__"npc/chunhua" : 1,
	]));

	set("area", "����");

	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if (  (dir == "north" )&& (me->query("gender") == "Ů��" )) 
	{
        	if(objectp(present("meng chunhua", environment(me))))
			return notify_fail("�ϴ���������ס�����������в����Ǳ߲�����ý��ĵط���\n");
	}

	if (  (dir == "south" )&& (me->query("gender") == "����" )) 
	{
        	if(objectp(present("meng chunhua", environment(me))))
			return notify_fail("�ϴ������ɻ���۹����������������Ů������ʲô��˼��\n");
	}

	return ::valid_leave(me, dir);
}