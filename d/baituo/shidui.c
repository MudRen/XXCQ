#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����������Χȫ�Ǿ�ʯ���������������ҵ���ʯ�ӣ����Ǳ��˻����
ʯ������������顣����һ��ƽ������ʯ���϶���һֻѩ�׵ĸ�󡡣
LONG);        
        set("objects", ([
                    __DIR__"npc/chanchu" : 1,
        ]));
         set("item_desc", ([                    
                "stone": "\n��Щ��ʯ���а��棬���ó��Ǳ��������������õġ�\n",
        ]));
        set("outdoors", "����ɽ");
        setup(); 
}

void init()
{
       object me = this_player();       
       if(!me->query_temp("baituo_yun") && me->query("id") != "xuanbing chanchu" 
          && me->query("id") != "snowman"){
             message_vision(HIW"�������ͻȻ���𣬶���$Nһ�ڶ��������\n"NOR,this_player()); 
             tell_object(me, HIB "��е�����һ�����Σ���ʱ���˹�ȥ��\n" NOR ); 
             me->unconcious();
             me->move(__DIR__"yuanzi5");
             tell_room(environment(me), me->name()+"ͻȻ�Ӿ�ʯ֮��ֱ�����������ȡ���һ��ˤ�ڵ��ϣ�\n", ({ me }));
          if(me->query_skill("poison", 1) < 100) me->die();                   
          else me->add("max_neili", -1);
          }  
        add_action("do_climb", "climb");
        add_action("do_climb", "pa");
        add_action("do_strike", "strike");       
}

int do_climb(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (arg == "stone" ){   
           message_vision("$N�ֽŲ��ã������˾�ʯȥ��\n", me); 
           message_vision("$N����һ�ݣ��Ѿ����˳�ȥ��\n", me);                      
               me->move(__DIR__"yuanzi5");
               message("vision", me->name() + "���������˳�����\n",environment(me), ({me}) );
               return 1;
        }     
}

int do_strike(string arg)
{
        object me;
        int improve, cost, hmglevel;
        me = this_player();
        improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
        hmglevel = me->query("oyf_hamagong");
        if( !arg || arg=="" ) return 0;
        if (arg == "stone" ){             
            if(!me->query_skill("hamagong", 1))  
               return notify_fail("������ָ�����ƾ�ʯ������¶��һ˿�ѿ�����ɫ��\n");
            if(me->query_skill("hamagong", 1) > 64 && hmglevel <2)  
               return notify_fail("������ָ�����ƾ�ʯ������¶��һ˿�ѿ�����ɫ��\n");
            if(me->query_skill("hamagong", 1) > 100)  
               return notify_fail("��һ�����ʯ��ȥ��ֻ�����һ������ʯ��������������룡\n");
        cost = 300 / (int)me->query("int");
        cost = 300 / (int)me->query("int");

           if ((int)me->query("jingli") < cost || (int)me->query("jing") < cost){
                message_vision("$N��������, һ�����������������$N���˹�ȥ��\n",me);
                me->unconcious();
                return 1;
                } 
           if(me->query_skill("hamagong", 1) > 64) 
           message_vision("$NĬ�и�󡹦�ھ���������˫��֮�ϣ�һ�������ʯ��ȥ��\n"NOR,this_player());  
           me->improve_skill("hamagong", improve);            
           me->improve_skill("strike", improve/4); 
           me->add("jing", -cost);
           me->add("jingli", -cost);                        
           return 1;
        }     
}

int valid_leave(object me)
{        
       me->delete_temp("baituo_yun");       
       return ::valid_leave(me);
}