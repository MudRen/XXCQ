// Room: huoroad3.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.7.1
// 
// 

#include <ansi.h>

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
�����ǵ������ֺš���ɽ·��·���ֵĶ���һЩ���컨�ݡ�˵������
Щ�������ж��ģ����ǿ�Щ�뿪����ɡ�������ɽ·������ȥ����ɽ
·��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("objects", ([
                "/kungfu/class/wenjia/wentuke" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"huoroad4",
                "eastup" : __DIR__"huoroad2",
        ]));

        setup();
}

void init()
{
        object me = this_player();
	
        if( me->query_skill("dodge",1) < 50) 
        {
                me->receive_damage("qi", 50);
                message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�������������\n"NOR, me);
                me->move(__DIR__"dongkou");
                tell_object(me, HIR"������ɽ·����������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
        }
}
