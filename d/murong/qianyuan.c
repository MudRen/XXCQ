// qianyuan.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIR"ǰԺ"NOR);
         set("long",@long
������������ɽׯ��ǰԺ, ֻ��һ����Ѿ��, ��Ů������������Ϣ, ��
�Ҹ�����������, ��Ȼ�书������Ժ�ӵĶ�����һ��Сʯ�ţ�������һ�����ȡ�
�����߾͵���ׯ�š�
long);
         set("outdoors","����Ľ��");
         set("exits",([
             "north" : __DIR__"zhuangmen",
             "east" : __DIR__"sq1",
             "south" : __DIR__"cl",
]));
	set("objects",([
		__DIR__"npc/binu" : 2,
]));
         setup();
         replace_program(ROOM);
}
