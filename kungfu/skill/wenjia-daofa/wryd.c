// ����һ��
// bye jfeng ����
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if( (int)me->query_skill("wenjia-daofa", 1) < 100 )
        return notify_fail("����¼ҵ���������죬����ʹ�á�����һ������\n");
    if( (int)me->query_skill("zhixin", 1) < 100 )
        return notify_fail("����¹�֪�²����ߣ�������[����һ��]��\n");
    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("����������̫��������ʹ�á�����һ������\n");
    msg = HIM "$N΢΢һЦ������һ����,��ʹ������һ����������$n��\n"NOR;
    if( !target->is_killing(me) ) target->kill_ob(me);
    if (me->query_skill("force")) > random((int)target->query_skill("force")) )
    {
        target->start_busy( 4 + random(2));
        damage = (int)me->query_skill("zhixin", 1);
        damage = damage +  (int)me->query_skill("qianli", 1);
        damage = damage +  (int)me->query_skill("wenjia-daofa", 1);
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/2,me);
        me->add("neili", -damage);
        msg = HIR"ֻ��$N����$wԽ��Խ�죬�������쵶�⣬ٿ������$n,\n$nֻ�����춼�ǵ�Ӱ���޴Ӷ�ܣ�$N���е�$w�Ѿ�����$n�����ѣ���\n"NOR;
        me->start_busy(2);
    } else 
    {
        msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
        me->add("neili", -150);
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
