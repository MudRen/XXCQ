//zoulang1��c              

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Ȩ��¥");
	set("long", @LONG
LONG);
	set("valid_startroom",1);
	set("area","����");
	set("exits", ([
                        "west" : __DIR__"quanlili1",
                        "enter" : __DIR__"quanlilou",
	]));
        replace_program(ROOM);
	setup();
}
