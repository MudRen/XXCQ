// Room: neitang.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
�����Ƿ���������������ͽ�ĵط������Ժܿ�����������ǽ�Ϲ��ŵ�
�ͽ���������ǽ����һ���޴��ɽˮ�������Ϸ������Ϸ����������Ǻ���
Ȼ�Ǵ�ǰ�������������ƫ���������߿�ȥ�����Կ�������������Ժ����
����
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                 "/kungfu/class/feiyu/shenxingnan" : 1,
        ]));

        set("exits", ([
                "southwest" : __DIR__"xipianting",
                "southeast" : __DIR__"dongpianting",
                "east" : __DIR__"dongwuyuan",
                "west" : __DIR__"xiwuyuan",
         ]));

        setup();
}

void init()
{
        object me = this_player();
        if (me->query_temp("feiyutask/given")) me->set_temp("di1mark", 1);
        return;
}
