// sq.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"Сʯ��"NOR);
         set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����Զ���ĺ�����
���������������Զ����ֻԧ����һ��Ϸˮ�����ߵ��������ź����ϴ�����
΢��ʱ��ʱ��ҡ���š�
long);
// will add a npc to ask chuan
          set("outdoors","����Ľ��");
          set("exits", ([
           "south" : __DIR__"matou",
           "northwest" : __DIR__"hb2",
]));
          replace_program(ROOM);
          setup();
}
