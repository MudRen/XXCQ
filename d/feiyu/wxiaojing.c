// Room: wxiaojing.c
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
���߼����͵��˷���������Ϣ����ǰ�ˡ�����·�ϲ�ʱ���о�װ����
��������߹��������������ĵ��Ӹ�����������������Լ���ü�һ��С
·��
LONG);
        set("valid_startroom", 1);
        set("exits", 
            ([
		        "north" : __DIR__"nanxiuxishi",
		        "south" : __DIR__"xiyuan",
            ]));
        set("outdoors", "feiyu");
		setup();
}

int valid_leave(object me, string dir)
{
       me = this_player();

       if (  (dir == "north" )&& (me->query("gender") == "Ů��" )) 
	{
	 message_vision("$Nһ������ң�Ҫ���е�������ȥ��ʲô��", me);
	 return notify_fail("\n");
	}

	return ::valid_leave(me, dir);
}
