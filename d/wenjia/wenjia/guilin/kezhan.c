// Room: kezhan.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "��ջ");
        set ("long", @LONG
����һ����׳���ϲ����Ŀ�ջ��Ϊ�����˴��������ṩ���ʵ���Ϣ��
�����ϲ�����Ϊ���˷����ԭ���շ��ر㣬�������ˡ�������һ������
(paizi)��
LONG);
        set("area","����");
        set("no_sleep_room",1);
        set("valid_startroom", 1);

        set("item_desc", ([
                "paizi" : "���ʵĿͷ���ÿҹһ��������\n",
        ]));

        set("objects", ([
                __DIR__"npc/zzoldman" : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"jiedao",
                "enter" : __DIR__"kefang",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{

       if ( !me->query_temp("rent_paid") && dir == "enter" )
       return notify_fail("׳���ϲ�Ц����Ķ���˵���������������ͷ�Ӱɣ������ջ������ѽ���ر������ʱ�򣬸���Ǯ�ɡ���\n");

       return ::valid_leave(me, dir);
}

