// ����ָ [����һ��]
// bye jfeng ����
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int)me->query_str() < 20)
                return notify_fail("���������,����ʹ����һ����!\n");
        if((int)me->query_skill("zhixin",1) < 100)
                return notify_fail("���¹�֪�µĹ�������!\n");
        if((int)me->query_skill("finger") < 100)
                return notify_fail("���ָ����Ϊ����!\n");
        if((int)me->query("neili") < 500)
                return notify_fail("���������ڲ���! \n");
        if((int)me->query("max_neili") < 400)
                return notify_fail("��������Ϊ����! \n");
        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
               msg +=
HIM "$Nʹ������ָ����������һ�������ع������������������۾�һ�㣬��
��ʳ�ж�ָ��$n������ȥ��$n�������У�ƴ�����$Nָ����ʱ�������ҡ�\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 )
        {
                msg +=  HIG "���$p��$Pָ�����м���Ѩ��! \n" NOR;
                target->start_busy( (int)me->query_skill("leiting-zhi",1) / 20 + 2);
                me->add("neili", -150);
        }
        else
        {
                msg += HIM "$p�鼱����������һԾ���˳���Զ��\n" NOR;
                me->start_busy(4);
        }
        return 1;
        message_vision(msg, me, target);
}
