// Room: yanjiushi.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "�о���");
        set ("long", @LONG
�����ǻ��ֺŵ��о��ң����¼ҵ����ڽ�����������ʲô��
�Ķ�ҩ���ͱ�����������о��ⶾ���������ֺŵĵ�һ���־���
���﹤���������ǻ���ң������������ң�������ǲض��Ĳ�
�⡣
LONG);
        set("area","����");
        set("objects", ([
                "/kungfu/class/wenjia/wennuansan" : 1,
        ]));
        set("exits", ([
                "east" : __DIR__"huikeshi1",
                "west" : __DIR__"ziliaoshi1",
                "south" : __DIR__"cangku",
        ]));
        setup();
        replace_program(ROOM);
}
