// Room: guishulin.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
ï�ܵĹ����֣�������ֲ��һƬï�ܵĹ����֣������ﱻ��Ϊ���ֵ�
ԭ�������Ϊ������Χ�зǳ���Ĺ����֡�������ȥ�����ҵıؾ�֮·��
�����Ҿ��ڶ��ߣ����ϱ�������ɽ��
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"qixingyan",
                "north" : __DIR__"guishulin1",
                "southwest" : __DIR__"yueya",
        ]));
        setup();
        replace_program(ROOM);
}

