// shuxie.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"����ˮ�"NOR);
         set("long",
"��䷿��С������, ��Ϊ���š�С���Ҷ���д�š�"HIY"����ˮ�"NOR"���ĸ�����, \n"
"������Ϊ������������һ��С·����֪��ͨ������ġ�����ǰ�ߣ��͵��ˡ�\n"
HIW"������"NOR"�����ϱ���ˮ鿵ĺ�Ժ��\n"
);
         set("exits",([
             "north" : __DIR__"ab1",
             "south" : __DIR__"houyuan1",
]));
	set("objects",([
	__DIR__"npc/azhu" : 1,
	]));
	setup();
        replace_program(ROOM);
}
