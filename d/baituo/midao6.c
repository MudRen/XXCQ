#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"�ص�"NOR);
        set("long", @LONG
�����������ص���ɽ�����������죬��֪ͨ���δ���ǰ��ĵ�·Խ��
Խ�������Ҫ�����������ˡ�����������ǣ���������һ�ɴ̱ǵ�ζ����
��һ�߹��������ͷ�Է��Σ������ж��ˡ�
LONG);                
        set("exits", ([
              "westup" : __DIR__"midao5",
              "east" : __DIR__"midao7",
              "south" : __DIR__"midao8",
              "west" : __FILE__,
              "north" : __DIR__"midao8",    
        ]));
        setup();
}

void init()
{    
  object me = this_player();
     if (random(me->query("kar")) <13 && me->query_con() < 34){ 
             tell_object(me, HIB "���Ȼ�е�����һ����ԭ��������Ŀ������ǡ���ͨ������\n" NOR );      
             tell_room(environment(me), me->name()+"ͻȻ��ɫ��ü�Ϊ�ѿ�������������˿�����\n" NOR,
                ({ me }));
             me->add("neili", -50);
             me->add("jingli", -10);
             me->receive_wound("jing", 20);
             }    
}