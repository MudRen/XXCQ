// xf.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",MAG"�᷿"NOR);
         set ("long",@long
����һ���᷿, ��������, ֻ��һ�Ŵ�, һ��������һ�����ӡ�
long);
         set("no_fight", 1);
         set("sleep_room", 1);
         set("exits",([
             "east" : __DIR__"houting",
]));
 	 setup();
	 replace_program(ROOM);
}
