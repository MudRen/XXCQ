//liangongfang¡£c          

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "¿Õ·¿");
	set("long", @LONG
LONG);
        set("valid_startroom",1);
	set("exits", ([
                        "west" : __DIR__"biandian1",
	]));
        set("area", "È¨Á¦°ï");
        set("objects",([
          __DIR__"npc/liang" : 1,
      ]));
	setup();
	replace_program(ROOM);
}
