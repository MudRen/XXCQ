// Room: yidao4.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "���");
        set ("long", @LONG
��͢���͹��ĵ��������ʱ���������߾���������ϳ��������
������ֲ��һЩ������С����������ɫ�Ե���Щ���������������߾�Ҫ��
�뻪�����ˡ������Ϸ����ǳ����������
LONG);
        set("area","�ɶ�");
        set("outdoors", "chengdu");
	set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"yidao3",
                "northwest" : "/d/chengdu/hyroad4",
        ]));
        setup();
        replace_program(ROOM);
}

