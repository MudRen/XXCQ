// Room: huoroad1.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// 
// 
#include <ansi.h>

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
�����ǵ������ֺš���ɽ·��·���ֵĶ���һЩ���컨�ݡ�
˵������Щ�������ж��ģ����ǿ�Щ�뿪����ɡ���������ɽ
·��������ȥ�����ܲ��Ķ��㳡��
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "south" : __DIR__"huoroad2",
                "westup" : __DIR__"eastsquare",
        ]));
        setup();
}

void init()
{
        object me = this_player();
	
        if( (int)me->query_skill("dodge",1) < 50) 
        {
                me->receive_damage("qi", 100);
                me->receive_wound("qi",  100);
                message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�������������\n"NOR, me);
                me->move(__DIR__"dongkou");
                tell_object(me, HIR"������ɽ·����������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
        }
}
