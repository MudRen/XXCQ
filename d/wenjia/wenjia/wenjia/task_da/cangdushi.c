// Room: cangdushi.c
// Created by Zeus 1999.5.12
// Modified by Zeus 1999.5.12
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�ض���");
        set ("long", @LONG
���������ֺ��¼��д��ֺŵĲض��ң�����صĶ�����һЩ��
�������Ķ�ҩ��������Ҫ�Ķ�ҩ�𡭡�����
LONG);
        set("area","����");

        set("exits", ([
                "north" : __DIR__"duku",
                "out" : "/d/wenjia/xiaojing",
        ]));

        set("objects", ([
                __DIR__"npc/wenxiao" : 1,
        ]));

        replace_program(ROOM);
        setup();
}