//mingge��c  by god

#include <room.h>
#include <skill.h>

inherit ROOM;

void create()
{	
	set("short", "Ȩ����");
	set("long", @LONG
������Ȩ����Ĵ��.

LONG);	
	set("valid_startroom",1);
	set("objects",([
	]));
	set("exits",([
		"east" : __DIR__"huozoulang",
		"south" : __DIR__"dati",
	]));

        set("area", "Ȩ����");
        set("objects",([
           __DIR__"npc/liu" : 1,
        ]));
        setup();
            replace_program(ROOM);
}
