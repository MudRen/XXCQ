// Room: peiyaofang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "��ҩ��");
        set ("long", @LONG
��������ҩ�ң�������������������ҩ����Ҫ����������ҩȻ�����
�����ýⶾ��������ż���ҩ��������Ÿ�ʽ��ҩ����һ���¼ҵ�����
��ҩ��
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 1,
        ]));

        set("exits", ([
                "northeast" : __DIR__"huikeshi1",
        ]));

        setup();
        replace_program(ROOM);
}
