// Room: xiangbi.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "���ɽ");
        set ("long", @LONG
���ɽλ���һ������콭�Ļ�������ɽ������������ˮ��������棬
��̬��Ȼ�������֮���γ�Բ��������ˮ�¶���ɽ���������������ɽ��
��Ϊ�˹���ɽˮ�Ĵ���
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"guishulin3",
        ]));
        setup();
        replace_program(ROOM);
}

