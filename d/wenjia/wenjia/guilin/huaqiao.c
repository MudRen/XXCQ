// Room: huaqiao.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
һ���ſ���콭���ε�ˮ·�������˹�������׳���ס�ء������Ž�
�������š���������ʯͷ���ɣ����з����������������ꡣ����������ȥ
���ǹ��������ġ�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/zzwoman" : 1,
        ]));

        set("exits", ([
                "northwest" : __DIR__"zhongxin",
                "southeast" : __DIR__"jiangdi1",
        ]));
        setup();
        replace_program(ROOM);
}

