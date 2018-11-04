#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(RED"�׶���"NOR, ({"heding hong", "hong", "heding"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long", RED"����һ�����ʵĺ׶��죬��ɢ��������������\n"NOR);
        set("value", 50000);
        }
        setup();
}

int init()
{
    call_out("dest", 800);
   add_action("do_eat", "fu"); 
}

int do_eat(string arg)
{
   object me = this_player();
   int damage;

   if(!id(arg))
       return notify_fail("��Ҫ��ʲô��\n");

   message_vision("$N����һ��" + name() + "��\n", me);  
   tell_object(me, MAG "��о�����һ�ɾ��۴�����˲��ȫ����ȹ��̣�\n" NOR);

    damage = (int)me->query("max_jing");
                damage = damage/15;
                damage = damage*14;

   me->receive_wound("jing", damage);
   me->receive_damage("qi", damage);

   if ((int)me->query_condition("hb_poison") > 1){ 
        me->apply_condition("hb_poison", 1);
        return 0;
        }
   if ((int)me->query_condition("cold_poison") > 1){ 
        me->apply_condition("cold_poison", 1);
        return 0;
        }

   me->apply_condition("hot_poison", 70); 

  
   destruct(this_object());
   return 1;
}

void dest()
{
        object me = this_player();
        if (present(this_object(), me))
        tell_object(me, HIR "�׶��������ɢ���������ɿ��ˡ�\n" NOR);

        destruct(this_object());
}


