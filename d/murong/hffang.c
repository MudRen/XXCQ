// hffang.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",BLU"���ʷ�"NOR);
         set ("long",@long
ֻ��һ��������������������������һ��ѩ���ĳ���, ����һ����ˮ, 
���ֱð������
long);
         set("exits",([
         "west" : __DIR__"hxlou",
]));
         set("objects",([
         __DIR__"npc/yan" : 1,
]));       
	setup();
	replace_program(ROOM);
}
