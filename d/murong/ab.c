// ab.c
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIY"����"NOR);
         set("long",@long
���������٢ɽׯ��С�����ˣ�Զ��һƬƬ���Ժ�ï�ܵ��������ڵ�ס
��������ߡ�
long);
         set("outdoors","����Ľ��");
	 set("objects",([
             __DIR__"npc/youcao" : 1,
]));
         set("exits",([
             "south" : __DIR__"liulin",
             "northeast" : __DIR__"hc1",
             "east" : __DIR__"zhuangmen",
]));
         setup();
         replace_program(ROOM);
}
