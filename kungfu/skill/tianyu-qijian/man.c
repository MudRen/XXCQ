// man.c
// ��ţ�Ƴ�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ţ�Ƴ���ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "�Ķ����Ѿ�����������\n");
                
        if( (int)me->query_skill("tianyu-qijian", 1) < 100 )
                return notify_fail("��������潣������죬����ʹ�á���ţ�Ƴ�����\n");
      if((int)me->query("int")<25)
          return notify_fail("�����潣�ؼ�����һ�������֡�,�����Բ����޷�ʹ�á���ţ�Ƴ���!\n");

        if(!me->query("lingwu_perform"))
                return notify_fail("�㻹û����������С�\n");

        msg = CYN "\n���ܵĿ����ƺ��Ѿ��������̣���ǰ��һ���Ѿ�����������$N����ʹ����\n���µ�һ����"+BLINK+WHT+"����ţ�Ƴ���\n"NOR;

        if(me->query("combat_exp") > random(target->query("combat_exp")))
        {
                msg += RED"���$p��ȫ��$P����ʽ�����ƣ���ʽ��������������\n" NOR;
                target->start_busy(3+random(3));
                
        } 
        else 
        {
                msg += WHT"$p��������ʽ��������ȻӦ�����硣\n" NOR;
                me->start_busy(random(2));
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me))
        target->fight_ob(me);
        return 1;
}

