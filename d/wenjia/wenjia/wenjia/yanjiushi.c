// Room: yanjiushi.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�о���");
        set ("long", @LONG
�����ǻ��ֺŵ��о��ң����¼ҵ����ڽ�����������ʲô�µĶ�ҩ��
�ͱ�����������о��ⶾ���������ֺŵĵ�һ���־������﹤������
���ǻ���ң������������ң�������ǲض��Ĳֿ⡣
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wennuansan" : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"huikeshi1",
                "west" : __DIR__"ziliaoshi1",
                "south" : __DIR__"cangku",
        ]));

        setup();
        replace_program(ROOM);
}
