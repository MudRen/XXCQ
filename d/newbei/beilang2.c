// Room: /welcome/donglang2.c
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
                "south":__DIR__"beilang1",
                "north":__DIR__"liangong2",
                "west":__DIR__"qianzhuang",
                "east":__DIR__"zahuopu",
        ]));
        set("no_fight", 1);
      setup();
        replace_program(ROOM);
}
