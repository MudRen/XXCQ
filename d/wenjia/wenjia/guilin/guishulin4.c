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
ԭ�������Ϊ������Χ�зǳ���Ĺ����֡������ߵ�·���ǵ�������«��
�ҡ�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"ludi",
                "south" : __DIR__"jiedao",
        ]));
        setup();
        replace_program(ROOM);
}

