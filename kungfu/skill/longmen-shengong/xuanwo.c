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
                return notify_fail("�����о���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("force", 1) < 80 )
                return notify_fail("����ڹ�����̫��������ʹ�á�\n");
                                
        if( (int)me->query_skill("longmen-shengong", 1) < 80 )
                return notify_fail("��������񹦲���������\n");
                        
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������̫��������ʹ�á����о�����\n");
                        
        msg = HIC "$N���ᵤ�˫��������Ƴ�һ�ɴ������е�����������$n��\n"NOR;

            if (wizardp(me)) {
                  msg += WHT"$nֻ��������������������е������䣬ȫ�����Լ���\n"NOR;
                  target->start_busy( (int)me->query_skill("force") / 40 + 1);
          message_vision(msg, me, target);
                  return 1;
               }
        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                  target->start_busy( 4 + random(3));
                
                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query("max_neili")/10;
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -300);
                msg += WHT"$nֻ��������������������е������䣬ȫ�����Լ���\n"NOR;
                me->start_busy(2);
        } else 
        {
                msg += YEL"����$p���Ա߲���һ��,���������еĹ�����Χ��\n"NOR;
                me->add("neili", -200);
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}

