// bao.c  ��������֮����ָ���ġ�
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����ָ���ġ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query_skill("huaibao-tianxia", 1) < 100 )
        return notify_fail(WHT"��Ļ��������񹦲�������ʹ��������ָ���ġ���\n"NOR);

    msg = HIC "$N�����������������ں���������һ�㣬��Ȼ���α��������  \n"NOR;
     msg += HIC"$N��Ȼվ����$N��˫�֣���Ȼ�ſ���Ȼ�����������һ����ָ��\n"NOR;
    msg += HIC"����������˵ڶ�����ָ����һ�������˵����ڵ���ָ����ʱ�����ѱ���ˣ�ȭͷ��\n"NOR;
    msg +=HIW"ֻ��$N߳�ȵ�������ָ���ģ���������\n\n\n"NOR;


    if (random(me->query_skill("force")) > target->query_skill("force")/3||
random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
    {
        me->start_busy(2);
        damage = (int)me->query_skill("huaibao-tianxia", 1);

        damage = damage + random(damage);

        target->set("qi", target->query("qi")/2);
        target->receive_wound("qi", damage);
        target->receive_damage("jingli", damage*2/3);
        target->receive_wound("jingli", damage/2);
        target->set("neili", target->query("neili")/2);
        me->add("neili", -damage/2);
    msg +=RED"����$n�۵�һ��,��$N�޴��ȭͷ��ķɳ�����\n"NOR;

    } else
    {
        me->start_busy(4);
        msg += HIY"����$p������$P����ͼ������ͷ������һ�ߡ�\n"NOR;
    }
    message_vision(msg, me, target);

    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
