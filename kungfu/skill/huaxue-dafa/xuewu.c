// made by lks

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
        int damage;
        string msg;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("����ڹ�����̫��������ʹ�á�\n");
                                
        if( (int)me->query_skill("huaxue-dafa", 1) < 120 )
                return notify_fail("��Ļ�Ѫ�󷨲���������\n");
                        
        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("����������̫��������ʹ�á�Ѫ����\n");
                        
        msg = HIC "$N���ᵤ�ҧ����⣬�³�һ��Ѫ������$n��\n"NOR;

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
        
                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("huaxue-dafa",1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);

                me->add("neili", -300);
                msg += WHT"$nһ����������Ѫ��������ȫ��ֻ����$n��Ѫ���вҽ�����!\n"NOR;
                me->start_busy(2);
        } else 
        {
                msg += YEL"����$p���Ա߲���һ��,�����Ѫ��\n"NOR;
                me->add("neili", -100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}


