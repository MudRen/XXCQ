// ab1.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIY"����"NOR);
         set("long",
"ԶԶ��ȥ��ֻ��һ��С���ϰ˾ż䷿�䣬����������¥������������Լ¶\n"
"��һ���Ʒ���"BLINK HIY"����ˮ�"NOR"����\n"
);
         set("outdoors","����Ľ��");
         set("exits",([
             "south" : __DIR__"shuixie",
]));
         setup();
         replace_program(ROOM);
}
