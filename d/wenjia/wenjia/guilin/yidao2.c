// Room: yidao2.c
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
������ֲ��һЩ������С����������ɫ�Ե���Щ��������·���Ŷ�����
�����š�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"yidao1",
                "north" : __DIR__"yidao3",
        ]));
        setup();
        replace_program(ROOM);
}

