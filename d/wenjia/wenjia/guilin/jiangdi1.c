// Room: jiangdi.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
һ�������ĵ̰����Աߵ��콭��ˮ���������ţ���Χ��ֲ�ź�Щ������
�羰������ѽ�����̲�ס��̾���������ߵ�����������ȥ���������ĵı�
��֮·�������ϱ���һ���ۿڡ�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"jiangdi",
                "southwest" : __DIR__"gangkou",
                "northwest" : __DIR__"huaqiao",
        ]));
        setup();
        replace_program(ROOM);
}

