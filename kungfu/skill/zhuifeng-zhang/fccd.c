// �紵�ݶ�
// bye jfeng ����
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�紵�ݶ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int)me->query_skill("strike") < 100)
                return notify_fail("��Ļ����Ʒ���򲻹����޷�ʹ�÷紵�ݶ���\n");
        if((int)me->query_skill("zhuifeng-zhang",1) < 100)
                return notify_fail("���׷���ƻ�򲻹����޷�ʹ�÷紵�ݶ���\n");
        if((int)me->query_skill("zhixin",1) < 100)
                return notify_fail("����¹�֪�»�򲻹����޷�ʹ�÷紵�ݶ���\n");
        if( me->query("max_neili") < 500 || me->query("neili") < 700 )
                return notify_fail("���������Ϊ�������޷�ʹ�÷紵�ݶ���\n");
        message_vision(HIR"$N���Ծ��,���һ����˫���뷢����ɽ�����ľ�������$n������\n"NOR, me, target);
        me->add("neili", -200);
        me->add_temp("apply/strength", 2*(int)me->query("str") );
        me->add_temp("apply/dexerity", 2*(int)me->query("dex") );
        COMBAT_D->do_attack(me, target);
        me->add_temp("apply/strength", -2*(int)me->query("str") );
        me->add_temp("apply/dexerity", -2*(int)me->query("dex") );
        me->start_busy(4);
        return 1;
}
