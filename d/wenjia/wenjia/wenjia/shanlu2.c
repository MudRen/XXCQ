// Room: shanlu2.c
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

        set("exits", ([
                "westdown" : __DIR__"shanlu1",
                "northup" : __DIR__"shanlu3",
        ]));
        setup();
        replace_program(ROOM);
}
