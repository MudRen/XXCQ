// Room: shulin1.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.6.10
// 
// 
#include <ansi.h>

inherit ROOM;
void init();
int do_zhao(string);

void create ()
{
        set ("short", "����");
        set ("long", @LONG
������ï�ܵ����֣�������֦��ï����ס�����⣬������Щ��ɭ�ֲ�
����ʱ����ֻҰ���ܹ�����ߡ������߻���һƬ���֣������������ǳ���
�͵�ɽ����
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/yetu" : 1,
        ]));

        set("exits", ([
                "southup" : __DIR__"shanjing2",
                "west" : __DIR__"shulin2",
        ]));

        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{

        object me;
        object chifan;

        if (!arg || arg != "up" )
        {
                return notify_fail("��Ҫ��ʲô?\n");	
        }
		
        me = this_player();	
	 	
        if( !me->query_temp("taskxiao/given"))
        {
                return notify_fail("���޲����ģ���ôϲ����?\n");	
        }

        if ( me->query_skill("dodge",1)>50)
        {
                message_vision("ֻ��$N���Ὣ����������һ�࣬��������ɣ��������ɡ�\n",me);
                me->move(__DIR__"task_xiao/shushang");
        }
        else if (me->query_skill("dodge",1)>25)
        {
                message_vision("ֻ��$˫����������һץ���ǳ���׾���������ɡ�\n",me);
                me->move(__DIR__"task_xiao/shushang");
        }
        else
                return notify_fail("����ô������û�취��������\n");	
        
        return 1;
}
