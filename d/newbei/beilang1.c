// Room: /welcome/donglang1.c
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
                "south":__DIR__"houting",
                "north":__DIR__"beilang2",
                "west":__DIR__"chaguan",
        ]));
        set("no_fight", 1);
	setup();
        replace_program(ROOM);
}
