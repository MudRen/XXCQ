// Room: zhailu.c
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
����һ����խ����·�����ߵ���Щ������������������߼����͵�
�˷���������Ժ�ˡ�����·��һ����Ҳû�У���˵�������������˼�����
������Ӱһ�����������������Ѿ��������������ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"xiyuan",
		"south" : __DIR__"xiaowu",
       ]));

        set("outdoors", "feiyu");
        setup();
        
}

int valid_leave(object me, string dir)
{
        me=this_player();

        if (  ((dir == "south") )
                && ( present("jian", this_player())
                || present("dao", this_player()) ))
        {
	        message_vision("�㷢����С����Щ�Ź֣��������ȫ��ճ�������ò������ˣ�������Ҫ�ȷ��������ˡ�\n", me);
        	return notify_fail("\n");
        }
        return ::valid_leave(me, dir);
}

