// Room: shanjing2.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.17
// �޸ĳ�����������ˤ����
// 

#include <ansi.h>

inherit ROOM;
void create ()
{
        set ("short", "ɽ��С��");
        set ("long", @LONG
����С�����߶��Ƕ��͵�ɽ�ڣ�С���ǳ���б��һֱ������
���죬ͨ��һƬ���֡�����һ��С�ľͻ�ˤ�ӡ����Ϸ��߾ͻ�
�ص�����ƽ̹��С����
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "southeast" : __DIR__"shanjing1",
                "northdown" : __DIR__"shulin1",
        ]));
        setup();
}

void init()
{
        object me = this_player();
	
        if( random((int)me->query_skill("dodge")) <= 20) 
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�... ��...��\n"NOR, me);
                me->move(__DIR__"shulin1");
                tell_object(me, HIR"������С������������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
        }
}
		

