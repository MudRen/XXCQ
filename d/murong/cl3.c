// cl3.c
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"����"NOR);
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ���
����������ȥ����æ���Լ������飬������һ�㵡����
long);
         set("exits", ([
             "north" : __DIR__"cl2",
             "east" : __DIR__"fenmu",
]));
         setup();
         replace_program(ROOM);
}
