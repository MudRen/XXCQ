// Room: yueya.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����ɽ");
        set ("long", @LONG
����ɽ�����붴��״��������ɽ��´�������ң��в���ʯ�̡�ʫ��
���������Ϊ���𺣱��֡���
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"guishulin2",
        ]));
        setup();
        replace_program(ROOM);
}

