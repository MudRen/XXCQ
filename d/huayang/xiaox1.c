//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��������");
        set ("long", @LONG
С�ﲢ���ܳ������涼����ӣ�����С���խ��������ǲ��㣬����
�Ľ����������ң�ż�����˴����ڳ������������ϰ���������
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"hycs",
        ]));

	set("objects", ([
		__DIR__"npc/xliumang": 1,
	]));

        set("outdoors", "huayang");
        setup();
}