// Room: fuboshan.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����ɽ");
        set ("long", @LONG
����ɽ�����콭���·�ͦ�㣬�Ҷ����ء�ÿ�괺�ĺ鲨��ɽ´�����
����ʹ��ˮ�����������ʳƷ�����ɽ´�л��鶴��������һ����������
���´�ʯ�������Խ�ʯ��
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "southwest" : __DIR__"zhongxin",
        ]));
        setup();
        replace_program(ROOM);
}

