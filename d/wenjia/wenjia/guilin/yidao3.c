// Room: yidao3.c
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
������ֲ��һЩ������С����������ɫ�Ե���Щ�����������Ѿ����Ĵ���
���ˡ����ߵĵ�·һֱ�������������š�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"yidao2",
                "northwest" : __DIR__"yidao4",
        ]));
        setup();
        replace_program(ROOM);
}

