//liangongfang��c          

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�շ�");
	set("long", @LONG
LONG);
        set("valid_startroom",1);
	set("exits", ([
                        "east" : __DIR__"biandian",
	]));
        set("area", "Ȩ����");
        set("objects",([
          __DIR__"npc/hua" : 1,
      ]));
	setup();
	replace_program(ROOM);
}
