#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"�ص�"NOR);
        set("long", @LONG
�����������ص���ɽ�����������죬��֪ͨ���δ��������ʯ�ڷǳ�
��ʪ������������ˮԴ�������￪ʼ�Ե��ֳ����������ߣ������ߺ����
�Կ���һ�����⡣
LONG);                
        set("exits", ([
              "westdown" : __DIR__"midao3",
              "eastdown" : __DIR__"midao5",
              "eastup" : __DIR__"midao1",
        ]));
        setup(); 
}

void init()
{    
  object me = this_player();
     if (random(me->query("kar")) <8 && me->query_con() < 30)
            { 
             tell_object(me, HIB "���Ȼ�е�����һ����ԭ��������Ŀ������ǡ���ͨ������\n" NOR );      
             tell_room(environment(me), me->name()+"ͻȻ��ɫ��ü�Ϊ�ѿ�������������˿�����\n" NOR,
                ({ me }));
             me->add("neili", -50);
             me->add("jingli", -10);
             me->receive_wound("jing", 20);
             }           
}