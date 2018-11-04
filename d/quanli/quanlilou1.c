//zoulang1¡£c              

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "È¨Á¦Â¥¶þ²ã");
	set("long", @LONG
LONG);
	set("valid_startroom",1);
	set("area","¹éÃÁ");
	set("exits", ([
                        "down" : __DIR__"quanlilou",
                        "up" : __DIR__"quanlilou2",
	]));
        replace_program(ROOM);
	setup();
}
