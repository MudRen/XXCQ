// Exert: jiedu.c 
// Created by Zeus 1999.6.8
// Modified by Zeus 1999.6.9
// �������⣺����ж����������ʲô��
// 

#include <ansi.h>

int exert(object me, object target)
{
        if ((int)me->query_skill("zhixin", 1) < 40)
                return notify_fail("��ġ��¹�֪�¡���Ϊ��������\n");
        if( me->is_fighting() )
                return notify_fail("ս�����˹��ⶾ��������\n");

        if ((int)me->query("neili") < 100 )
                        return notify_fail("��������������޷��ⶾ��\n");

        me->apply_condition("feixing_poison", 0);
        me->apply_condition("shengdu_poison", 0);
        me->apply_condition("xiangshi_poison", 0);
        me->apply_condition("duzun_poison", 0);

        message_vision(YEL"$N�������ϴ�Ѩ��Ȼ�������ڹ��������³�"+BLK"��ɫŨѪ��\n"NOR,me);

        me->add("neili",-100);

        me->start_busy(1);
        return 1;
}
