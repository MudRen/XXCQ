// Room: tulu.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.10.9
// 

inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
����һ����ͨ����·���ƻƵ���·һֱ���쵽�Ӳ�֮�У�������ȥ·
��·�ϲ�ʱ����һЩ�ݲ��š�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northup" : __DIR__"huangdi",
		"east" : __DIR__"mudi",
       ]));

        set("outdoors", "feiyu");
        setup();
        replace_program(ROOM); 
}

