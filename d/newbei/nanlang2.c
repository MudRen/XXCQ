// Room: /welcome/xiting2.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"��ѩ����"NOR);
    set("long", @LONG
������һ����������������ȵ���������ש�����ߵ�ǽ�Ϲ���һЩ�ֻ���
LONG
    );
        set("exits", ([
                "north":__DIR__"nanlang1",
                "south":__DIR__"liangong1",
                "west":__DIR__"yaopu",
                "east":__DIR__"datiepu",
        ]));
        set("no_fight", 1);
	setup();
        replace_program(ROOM);
}
