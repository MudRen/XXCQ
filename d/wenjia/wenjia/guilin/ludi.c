// Room: jiangdi.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "«����");
        set ("long", @LONG
«������һ�����������ʯ�����ܶ��������д�������ʯ��Ѥ����ʣ�
�������档���οͱ����ĵط���
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"guishulin4",
        ]));
        setup();
        replace_program(ROOM);
}

