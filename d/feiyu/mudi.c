// Room: mudi.c
// Created by Atlus 1999.10.9
// Modified by Atlus 1999.10.9
// 

inherit ROOM;

void create ()
{
        set ("short", "Ĺ��");
        set ("long", @LONG
�شԼ䣬Ʈ����Ԫ��ֽǮ�Ļҽ����ɲݱ��紵������˿��Ʈ�ţ���
�Ź���Խ��Խ��Ĳ�����Զ�������������Ǻ�����������Ĺ԰���һ
������ɨĹ��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"tulu",
		]));

        set("objects", ([
		"/d/feiyu/npc/cangjian": 1,
	    ]));

        set("outdoors", "feiyu");
        setup();
        replace_program(ROOM); 
}

