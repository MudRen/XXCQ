// Room: yidao1.c
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
������ֲ��һЩ������С����������ɫ�Ե���Щ��������·�������ǹ�
�ֵ��콭���ˡ���������ȴ�ǳ����������
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"lijiangbian1",
                "northwest" : __DIR__"yidao2",
        ]));
        setup();
        replace_program(ROOM);
}

