// Room: disanfeng.c
// Created by Atlus 1999.10.10
// Modified by Atlus 1999.10.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
�����Ƿ�������塣�Ĵ�����ŨŨ�İ������Ƿ羰�ܲ���������
������Ҫ�ر�С�ģ������ˤ��ɽȥ�ġ����ߵ�����ʹ����û�������
�����п�����Լ����һ����ɽ��·��
LONG);
        set("area","feiyu");
        set("outdoors", "feiyu");

        set("exits", ([
                "southdown" : __DIR__"houshan",
        ]));
        setup();
       
}

void init()
{
        object me = this_player();
        if (me->query_temp("feiyutask/given")) me->set_temp("di3mark", 1);
        return;
}
