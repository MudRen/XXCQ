// Room: shanlu4.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
һ�������˲ȳ�����ɽ·�������Ѿ�����ңң�Ŀ��������¼ҵĴ���
�������Ѿ����¼��ˡ��������������š�·�����¼ҵ��Ӵ���ߵ�ʱ��
���Ƕ����ͷ�����㣬�ƺ�������ܹ֡�
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 1,
        ]));

        set("exits", ([
                "eastdown" : __DIR__"banshan",
                "north" : __DIR__"paifang",
        ]));
        setup();
        replace_program(ROOM);
}
