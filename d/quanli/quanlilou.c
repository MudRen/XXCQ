//zoulang1��c              

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Ȩ��¥����");
	set("long", @LONG
LONG);
	set("valid_startroom",1);
	set("area","����");
	set("exits", ([
                        "out" : __DIR__"quanlili2",
                        "up" : __DIR__"quanlilou1",
	]));
        replace_program(ROOM);
	setup();
}
