// Room: ziliaoshi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
������ʵ�����Աߵ������ң����ﴢ���˸��ֶ�ҩ��������
������������˼�����е������Ķ�ҩ����ʱ���˴������ʵ����
�����������ϡ�
LONG);
        set("area","����");
	set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"shiyanshi",
        ]));
        setup();
        replace_program(ROOM);
}
