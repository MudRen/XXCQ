// sq1.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"Сʯ��"NOR);
         set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����ʯ�ŵĶ�����
һ������ʯ�̳ɵ�С������������٢��ɽׯ��ǰԺ��
long);
	set("outdoors","����Ľ��");
         set("exits",([
             "south" : __DIR__"xj2",
             "west" : __DIR__"qianyuan",
]));
	setup();
	replace_program(ROOM);
}
