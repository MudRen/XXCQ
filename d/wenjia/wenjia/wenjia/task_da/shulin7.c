// Room: shulin7.c
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.27
// 
// 

inherit ROOM;
#include <ansi.h>;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
ï�ܵ���Ҷ�ڵ������⣬��ʹ����Χ�����Ե��е���ɭ��һ���
��������Χ����Ҷ��ɳɳ�������졣�㷢�����ܶ��Ǵ�������֪��һ
·�ǳ�·��
LONG);
        set("area","����");
        set("valid_startroom", 1);
        set("outdoors", "wenjia");

        set("exits", ([
                "east" : __DIR__"shulin"+(random(8)+1),
                "south" : __DIR__"shulin"+(random(8)+1),
                "west" : __DIR__"shulin8",
                "north" : __DIR__"shulin"+(random(8)+1),
                "southeast" : __DIR__"shulin"+(random(8)+1),
                "southwest" : __DIR__"shulin"+(random(8)+1),
                "northwest" : __DIR__"shulin"+(random(8)+1),
                "northeast" : __DIR__"shulin"+(random(8)+1),
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        int qi_cost;

        me=this_player();

        qi_cost=(-1) * ( me->query("max_qi") ) / (20 + random(3) );

        if ( dir == "west"  && (me->query_temp("taskda/p_given")) ) {
                me->add("qi",qi_cost);
                message_vision(MAG"$N������Щѣ��!\n"NOR,me);
        }

        return ::valid_leave(me, dir);
}
