// Room: shulin2.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
������һƬï�ܵ����֡��򶫻���һƬ���֡����Ͼ���һƬ
�ݵ��ˡ�
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "east" : __DIR__"shulin1",
                "north" : __DIR__"caodi",
        ]));
        setup();
        replace_program(ROOM);
}
