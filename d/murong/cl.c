// cl.c

#include <ansi.h>

inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @long
����һ�����ȣ����滭�Ž��������Ĺ��ʻ�����ɫ���������ɫ������
�ߣ�ʹ���㲻�ɵöԽ������������Ĵ��쾪̾���ѡ��ڳ������棬Ѿ�ߡ���
����������ȥ����æ���Լ������飬������һ�㵡���������ǳ��ȵ����졣
long);
         set("exits", ([
             "south" : __DIR__"cl1",
             "north" : __DIR__"qianyuan",
]));
	set("objects",([
	__DIR__"npc/jiading" : 2,
]));
         setup();
         replace_program(ROOM);
}
