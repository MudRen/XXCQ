// Room: huoroad6.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

#include <ansi.h>

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
�����ǵ������ֺš���ɽ·��·���ֵĶ���һЩ���컨�ݡ�˵������
Щ�������ж��ģ����ǿ�Щ�뿪����ɡ���������ɽ·������ȥ����ɽ
·��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"huoroad7",
                "northup" : __DIR__"huoroad5",
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
