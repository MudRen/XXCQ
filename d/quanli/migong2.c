#include <room.h>
inherit ROOM;

void create()
{
        set("short", "°ËØÔÕó");
        set("long", @LONG
LONG);

        set("exits", ([
        "east" : __DIR__"migong4",
        "south" : __DIR__"migong3",
		"west" : __DIR__"migong1",
		"north" : __DIR__"migong2",
        ]));
        set("outdoors", "È¨Á¦");
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int jingli_cost;

        me=this_player();

        jingli_cost=(-1) * (( me->query("max_jingli") ) / 15 );

        return ::valid_leave(me, dir);
}
