// Room: zhongxin.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
�����ǹ���������ġ�������׳��ľۼ��أ����Ե��������Կ�����
��׳����ε���������ȥ�����ߵ�����������ɽ���ǡ�����塱�����Ӷ�
�˿��Ե����ߵ�С�Ե�ȥ��������ǡ����ֵ�һ�������ĵꡣ��ȥ��佻�
����Ҫ�����ϱߵ�·������������ǽֵ���
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/zzman" : 1,
                __DIR__"npc/zzboy" : 1,
        ]));

        set("exits", ([
                "southeast" : __DIR__"huaqiao",
                "north" : __DIR__"jiedao",
                "west" : __DIR__"xiaochi",
                "east" : __DIR__"duxiu",
                "southwest" : __DIR__"working",
        ]));
        setup();
        replace_program(ROOM);
}

