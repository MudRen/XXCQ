// Exert: jieduother.c 
// Created by Zeus 1999.6.9
// Modified by Zeus 1999.6.9
// �������⣺����ж����������ʲô��
// 

#include <ansi.h>

int exert(object me, object target)
{
        if(!living(target))
                return notify_fail("����ô���������ˣ�\n");

        if ((int)me->query_skill("zhixin", 1) < 60)
                return notify_fail("��ġ��¹�֪�¡���Ϊ��������\n");
        if( me->is_fighting() )
                return notify_fail("ս���а���˽ⶾ��������\n");
        if( target->is_fighting() )
                return notify_fail("��������ս������ô����˽ⶾ��\n");

        if ((int)me->query("neili") < 200 )
                        return notify_fail("��������������޷��ⶾ��\n");

        if ((int)target->query("neili") < 100 )
                        return notify_fail("�Է��������������޷��ⶾ��\n");

        target->apply_condition("feixinag_poison", 0);
        target->apply_condition("shengdu_poison", 0);
        target->apply_condition("xiangshi_poison", 0);
        target->apply_condition("duzun_poison", 0);

        message_vision(YEL"$N����$n���ϴ�Ѩ��Ȼ��˫�ְ���$n��������ڹ���$n�����³�"+BLK"��ɫŨѪ��\n"NOR,me,target);

        me->start_busy(1);
        me->add("neili",-200);
        target->add("neili",-100);
        target->start_busy(3);
        return 1;
}
