// Room: ziliaoshi1.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
�����ǻ��ֺŵ������ң������������С�ֺŵ������ҵ����ϻ���һ
���������������Ϊ�о���ҩ��׼���ġ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"yanjiushi",
        ]));

        setup();
        replace_program(ROOM);
}
