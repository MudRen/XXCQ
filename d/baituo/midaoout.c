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
              "west" : __FILE__,
              "east" : __DIR__"midao8",
              "north" : __DIR__"midao7",
              "south" : __FILE__,    
        ]));
        setup(); 
}

void init()
{    
  object me = this_player();
     if (random(me->query("kar")) <15 && me->query_con() < 35){ 
             tell_object(me, HIB "���Ȼ�е�����һ����ԭ��������Ŀ������ǡ���ͨ������\n" NOR );      
             tell_room(environment(me), me->name()+"ͻȻ��ɫ��ü�Ϊ�ѿ�������������˿�����\n" NOR,
                ({ me }));
             me->add("neili", -50);
             me->add("jingli", -10);
             me->receive_wound("jing", 20);
             }    
        add_action("do_use", "use");
        add_action("do_tui", "tui");
}

int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write("���ȼ�˻��ۣ�����ǰ��ʯ������һ���ڣ�������ʯ��ס�ˣ���֪�ܲ�����(tui)������\n");
             this_player()->set_temp("marks/��", 1);
             return 1;
       }
}

int do_tui(string arg)
{
        object me;
        me = this_player();
        if (arg == "stone" || arg == "jushi" ){    
        if (me->query_temp("marks/��") ) {
          if(me->query_skill_mapped("force") != "hamagong" ){
               me->add("max_neili", -1);
               message_vision(HIR "$N�����������ʯһ�����������û�ƿ����������������Լ���\n" NOR, me);
               me->unconcious();
               return 1;
               }
           else{
            message_vision("$N���Ƶ�ס��ʯ���͵�һ�ƽ���ʯ�ƿ�һ�������˳�ȥ��\n", me);  
            me->move("/u/ellie/hj/hswz");
            message("vision", me->name() + "����ʯ�������˳�����\n",environment(me), ({me}) );
            this_player()->set_temp("marks/��", 0);
            return 1;
          }
        }
       }
        else {
            write("������ʲô��\n");
            return 1;
        }
}
