//sleep��c  by god

#include <room.h>

inherit ROOM;

void create()
{	
        set("short", "����");
	set("long", @LONG
����һ����ܰ�����ҡ� 
LONG);	
	set("valid_startroom",1);
	set("no_steal", "1");
	set("no_fight", "1");
	set("sleep_room",1);
        set("exits", ([ "west" : __DIR__"dati",
        ]));
	setup();
	replace_program(ROOM);
}
