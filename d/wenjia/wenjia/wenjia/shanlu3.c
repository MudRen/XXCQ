// Room: shanlu3.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
һ�������˲ȳ�����ɽ·�������Ѿ��ǰ�ɽ���ˣ��ٴ�������ȥ����
�¼ҵ������ˡ���ʱ�����¼ҵĵ��Ӵ����ﾭ�������ǵ�������š�����
���߹�����ߵ�ʱ����������һ���������ζ��
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "southdown" : __DIR__"shanlu2",
                "north" : __DIR__"banshan",
        ]));
        setup();
        replace_program(ROOM);
}
