// Room: /welcome/xilang1.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"��ѩ����"NOR );
    set("long", @LONG
������һ����������������ȵ���������ש�����ߵ�ǽ�Ϲ���һЩ�ֻ���
LONG
    );
        set("exits", ([
                "north":__DIR__"houting",
                "south":__DIR__"nanlang2",
                "west":__DIR__"jiulou",
        ]));
        set("no_fight", 1);
      setup();
        replace_program(ROOM);
}
