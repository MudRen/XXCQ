// Room: tiesuo.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
һ������콭�������š����������콭�Ķ��������������߾����Ĵ�
�ˣ������������ž������㾳���ˡ����濴�������ţ��Ź�������������
���ϣ��������ﻹ���콭�����Σ����µ�ˮ���ǳ����ļ�������ȥ�϶�û
�����ˣ����Ҫץ������ѽ!
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"lijiangbian2",
                "northwest" : __DIR__"lijiangbian1",
        ]));
        setup();
        replace_program(ROOM);
}

