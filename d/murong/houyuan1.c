// houyuan1.c
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"��Ժ"NOR);
         set ("long",@long
����ˮ鿵ĺ�Ժ��Ժ�м�ɽˮʯ����һ��͸�����ϱ��һ��ķ����
�߾��Ǿ����������������ˡ�������һ��ͨ�����С����ľ�š�
long);
         set("outdoors","����Ľ��");
         set("exits",([
             "north" : __DIR__"shuixie",
             "south" : __DIR__"yanziwu",
             "east"  : __DIR__"muqiao",
]));
         setup();
         replace_program(ROOM);
}
