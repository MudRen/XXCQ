// houyuan.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"��Ժ"NOR);
         set ("long",
"����һ�������εĹ���, ������һ��С¥֮ǰ��С¥����һ���Ҷ�, д\n"
"�ţ�"BLINK HIM"�ƽ�¥"NOR"����ī�̺���, ¥��ǰ�������ֵĶ��ǲ軨������Щ�軨������\n"
"����������ɫ, ���⾫�µ�¥��ͤ����, δ�ⲻ�ġ�\n"
);
         set("outdoors","����Ľ��");
         set("exits",([
         "west" : __DIR__"xj2",
         "east" : __DIR__"xf",
         "south" : __DIR__"yjl",
]));
	set("objects",([
	__DIR__"npc/puren" : 1,
	]));
         setup();
         replace_program(ROOM);
}
