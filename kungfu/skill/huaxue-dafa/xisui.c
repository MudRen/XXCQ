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
                return notify_fail("������󷨡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("force", 1) < 80 )
                return notify_fail("����ڹ�����̫��������ʹ�á�\n");
                                
        if( (int)me->query_skill("huaxue-dafa", 1) < 100 )
                return notify_fail("��Ļ�Ѫ�󷨲���������\n");
                        
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á�����󷨡���\n");
                        
        msg = HIC "$N���ᵤ���ʱ����һƬ���࣬˫���Ƴ�һ�������ޱȵ�����������$n��\n"NOR;
        if (wizardp(me))
        {
               msg += WHT"$nֻ����һ������Ϯ����һ�ɺ���ֱ�������衢���衢Ѫ�衢���衣������\n"NOR;
                target->apply_condition("xisui_du",15);
        message_vision(msg, me, target);
        return 1;
        }
        if (random(me->query_skill("force")) > target->query_skill("force") )
        {
                if (random(15)<10)
                {
                target->remove_all_killer();
                
                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("huaxue-dafa",1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                target->apply_condition("xisui_du",15);
                me->add("neili", -200);
                msg += WHT"$nֻ����һ������Ϯ����һ�ɺ���ֱ�������衢���衢Ѫ�衢���衣������\n"NOR;
                me->start_busy(2);
                }
        } else 
        {
                msg += YEL"����$p���Ա߲���һ��,�������������ޱȵ�������\n"NOR;
                me->add("neili", -100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

