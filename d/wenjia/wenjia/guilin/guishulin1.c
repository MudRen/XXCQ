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
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"jiangdi",
                "south" : __DIR__"guishulin2",
        ]));
        setup();
        replace_program(ROOM);
}

