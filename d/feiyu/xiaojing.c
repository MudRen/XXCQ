// Room: xiaojing.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create ()
{
        set ("short", "С��");
        set ("long", @LONG
����һ����ʯ�̳ɵ�С������֪�����Ѿ��ߵ���С����ͷ����������
���߼����͵��˷�����Ů��Ϣ����ǰ�ˡ�����·�ϲ�ʱ���о�װ����
Ů���������������������Ů���Ӻ���ѷɫ���е��ӡ�������Լ���ü�һ
�����š�
LONG);
	    set("valid_startroom", 1);
        set("exits", 
	        ([
				"north" : __DIR__"girlroom",
				"south" : __DIR__"dongyuan",
			]));
	    set("outdoors", "feiyu");
        setup();
}

int valid_leave(object me, string dir)
{
       me = this_player();

       if (  (dir == "north" )&& (me->query("gender") == "����" )) 
	{
	 message_vision("$Nһ�������ˣ�Ҫ��Ů��������ȥ���к���ͼ��", me);
	 return notify_fail("\n");
	}

	return ::valid_leave(me, dir);
}
