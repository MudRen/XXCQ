//zhuang��c  by god

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "����");
	set("long", @LONG
LONG);	
	set("valid_startroom",1);
	set("objects",([
	]));
	set("exits", ([
		"north" : __DIR__"whoufang",
		"east" :  __DIR__"whoufang1",
		"south" :  __DIR__"whoufang2",
		"out" :  __DIR__"enter1",
	]));
        set("area", "����");
        set("objects",([
           __DIR__"npc/quhanshan" : 1,
        ]));
        setup();
            replace_program(ROOM);
}
