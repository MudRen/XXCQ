// Room: shanlu1.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
һ�������˲ȳ�����ɽ·����������ȥ�����¼ҵ������ˡ���ʱ����
�¼ҵĵ��Ӵ����ﾭ�������ǵ�������š��������߹�����ߵ�ʱ�����
������һ���������ζ��
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 1,
        ]));

        set("exits", ([
                "northdown" : __DIR__"shandi",
                "eastup" : __DIR__"shanlu2",
        ]));
        setup();
        replace_program(ROOM);
}
