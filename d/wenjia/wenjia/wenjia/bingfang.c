// Room: bingfang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
������ֺŵĲ������¼ҵ������˶���������������ҽⶾ��Ȼ����
��Ϣ��������Χ�м��Ŵ��̣��������ż������ˡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"zhiliaoshi",
        ]));

        setup();
        replace_program(ROOM);
}
