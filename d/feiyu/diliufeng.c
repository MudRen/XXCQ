// Room: diliufeng.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
�����Ƿ���ɽׯ�����塣�Ĵ�����ŨŨ�İ������Ƿ羰�ܲ�����
����������Ҫ�ر�С�ģ������ˤ��ɽȥ�ġ�����ķ�����Ӹ�����ʮ��
���裬���´�����ÿ���ˣ�����û������ڣ�Ҳ�������͵�����ķ羰
�ˡ�˳�����ߵ�ɽ·���¿����㿴����һ������졣
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                "east" : __DIR__"yixiantiannei2",
                "southwest" : __DIR__"shaozhan",
        ]));
        setup();
        replace_program(ROOM);
}

