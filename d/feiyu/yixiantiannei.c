// Room: yixiantiannei.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "һ������");
        set ("long", @LONG
��һ���족��Ȼ�����鴫�����������Ͽ����Ը��ʵ��ͱڼ�ֻ¶��һ
�����ߣ����Ե��ͱ��ϳ�������ɽ�٣�էһ�������Ǽ������߲������ϡ�
һ��紵�������ܷ�������ֵ���������е�������Щ���⡣���ǿ����
�ɡ�
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 1,
        ]));

        set("exits", ([
                "northup" : __DIR__"yixiantian",
                "southdown" : __DIR__"yixiantiannei2",
        ]));
        setup();
        replace_program(ROOM);
}
