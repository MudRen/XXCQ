// xs.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short", HIY"С��"NOR);
         set("long",
"��䷿��С������, ��Ϊ���š�С���Ҷ���д�š�"BLINK HIY"����"NOR"�����ֱ���,\n"
"����Ϊ������Զ����С��¶��һ���ݽǡ��������߸���һ��С����֪ͨ\n"
"�����\n"
);
         set("exits", ([
             "east" : __DIR__"xj1",
	     "north" : __DIR__"xd",
             "west" : __DIR__"tyj",
]));
         set("objects",([
             __DIR__"npc/bao" : 1,          
]));
         setup();
         replace_program(ROOM);
}

