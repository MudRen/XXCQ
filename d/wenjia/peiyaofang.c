// Room: peiyaofang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "��ҩ��");
        set ("long", @LONG
��������ҩ�ң�������������������ҩ����Ҫ����������ҩ
Ȼ����ܹ����ýⶾ��������ż���ҩ��������Ÿ�ʽ��ҩ��
��һ���¼ҵ�������ҩ��
LONG);
        set("area","����");
        set("objects", ([
                __DIR__"npc/wenjiadizi" : 1,
        ]));
        set("exits", ([
                "northeast" : __DIR__"huikeshi1",
        ]));
        setup();
        replace_program(ROOM);
}
