// hc.c 

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"������"NOR);
         set("long",@long
���Ų�����, ֻ�������г�ɽ�軨����ޱ�������, �������ǣţ��,
���º�, Ǿޱ֮��Ҳ��һ�䶼�ޡ��߳���ʮ�ɺ�, ֻ��ɽ��Ʒ�ֽ���, ż��
Ҳ��һ�������㲻��, ȴҲ���ֲ����䷨��
long);
         set("outdoors","����Ľ��");   
         set("exits",([
         "west" : __DIR__"hc3",
         "south" : __DIR__"hc1",
         "east" : __DIR__"hc5",
         "north" : __DIR__"hc7",         
]));
         setup();
         replace_program(ROOM);
}
