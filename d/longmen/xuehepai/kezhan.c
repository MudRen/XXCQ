
inherit ROOM;

void create()
{
        set("short", "���ſ�ջ");
        set("long", @LONG
��������Ψһ��һ�ҿ͵꣬����������ڣ�װ�λ��������������
�����������ϵĴ��š���С����������æ������ת���Ӵ�����ǻ�����Ŀ�
�ˡ�ǽ�Ϲ���һ������(paizi)��
LONG);
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"xijie",
                "up"   : __DIR__"kedian2",
        ]));
//        set("no_clean_up", 0);
        setup();
//        "/d/longmen/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "up" )
     return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

        if ( me->query_temp("rent_paid") && dir == "west" )
        return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס���ס
���˻���ΪС���ź����أ�\n");

        return ::valid_leave(me, dir);
}


