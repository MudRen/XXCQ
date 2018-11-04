
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
        string msg;
       object weapon,target;
         int skill,qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = (me->query_skill("chixin-jian",1)+(me->query_skill("sword",1))/2);

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ����ô��ʹ���ຣ�ޱߡ���\n");

        if( !me->is_fighting()|| !living(me) )
                return notify_fail("���ຣ�ޱߡ�ֻ����ս����ʹ�á�\n");

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("���������Ϊ�������ߣ�\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("�����ڵ��������㣡\n");

        if( skill < 120)
                return notify_fail("����Ľ�������Ϊ����������ʹ�á��ຣ�ޱߡ�! \n");

        if( me->query_skill_mapped("sword") != "chixin-jian") 
                return notify_fail("��û�м������Ľ�����\n");
 
        msg = HIY "$N˫�ŵ�أ��͵�����һԾ�����������ֻ�ߣ����һ�����ຣ�ޱߡ���\n��Ȼת�����£�����$n��ɱ��ȥ��\n\n"NOR;
        message_vision(msg, me, target);
 
        if ( ((random(me->query("combat_exp"))) > (target->query("combat_exp")/2)) || wizardp(me))
        {       
                if(userp(me))
                        me->add("neili",-200);

                msg = HIR "$nֻ���ý����㣬����������ס��ȫ���޳��ɶ㡣\n\n"NOR;
                message_vision(msg, me, target);

                qi_wound = 100 + skill + random(skill*2);

                if(qi_wound > target->query("qi"))
                        qi_wound = (target->query("qi") + 1);

                target->add("qi", -qi_wound);
                target->add("eff_qi", -(qi_wound/4));

               target->start_busy(3+random(3));
               me->start_busy(2);
        }
        else
        {
                msg = HIG "ֻ��$n��һ��أ���������ߣ����������������Ľ�Ӱ��\n\n"NOR;
                message_vision(msg, me, target);
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }

        call_out("perform_hui", 8, me);
        return 1;
}

int perform_hui(object me)
{
        string msg;
        object weapon, target;
          int skill,qi_wound;

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return 0;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = (me->query_skill("chixin-jian",1)+(me->query_skill("sword",1))/2);
        
        if (me->query_skill_mapped("force")!="bairen-shengong" || me->query_skill("bairen-shengong",1)<100 )   return 0;

             if (!me->is_fighting())  return notify_fail("��û�н���ս��״̬��\n");
        msg = HIY "\n$N�ż�ո�մ�أ�������һ������δ˥��������������ͷ�ǰ�����\n�������м�תһȦ�����н�һ��,������ɨ��\n\n"NOR;
        
        message_vision(msg, me, target);
        
        if ( ( (random(me->query("combat_exp"))) > (target->query("combat_exp")/3)) || (target->is_busy()) )
        {       
                if(userp(me))
                        me->add("neili",-200);

                msg = HIR "$nһ����ֻ������һ�����ѵ������ţ������м� ��\n\n"NOR;
        
                message_vision(msg, me, target);

                qi_wound = 100 + skill;

                if(qi_wound > target->query("qi"))
                        qi_wound = (target->query("qi") + 1);

                target->add("qi", -qi_wound);
                target->add("eff_qi", -(qi_wound/4));

                me->start_busy(random(4));
        }
        else
        {
                msg = HIG "ֻ��$n����һ�㣬�ܿ��������������һ����\n\n"NOR;
                message_vision(msg, me, target);
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(2);
        }

        
        return 1;
}


