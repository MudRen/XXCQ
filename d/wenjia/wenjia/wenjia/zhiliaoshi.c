// Room: zhiliaoshi.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
������ֺ���������ң��¼ҵ������˶������������ⶾ�����ڱ�
��Ĳ�������Ϣ�����Ϸ������ǻ���ҡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"huikeshi1",
                "north" : __DIR__"bingfang",
        ]));

        setup();
        replace_program(ROOM);
}
