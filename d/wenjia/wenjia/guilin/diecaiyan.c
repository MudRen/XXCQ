// Room: diecaiyan.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
�����ҵ���������Ϊ�Ҳ�ˮƽ����ʽ�����ɽ��һ����綴���ϱ���
�������ܹ��ˣ��ļ�������磬�����綴��ɽ���е���ͤ����ֹ�õ��ƴ�
������ʯ�̡�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"guishulin",
        ]));
        setup();
        replace_program(ROOM);
}

