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
		"north" : __DIR__"houfang",
		"west" :  __DIR__"houfang1",
		"south" :  __DIR__"houfang2",
		"out" :  __DIR__"enter1",
	]));
        set("area", "����");
        setup();
            replace_program(ROOM);
}
