// luoyan.c ��������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("[��������]ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ��[��������]��\n");		
		
        if( (int)me->query_skill("youyu-quan", 1) < 100 )
		return notify_fail("�������ȭ��������죬����ʹ�á��������㡹��\n");
	                        
        if( (int)me->query("neili", 1) < 400 )
		return notify_fail("����������̫��������ʹ�á��������㡹��\n");
			
	msg = HIR "$Nʹ������ȭ���е�һʽ�۳�������ݣ�˫ȭ������������ʱȭӰ�ܲ���������$n��" NOR;
	me->add("neili", -250);

        if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("cuff")) > target->query_skill("parry")/2 )
	{
		me->start_busy(2);
		target->start_busy(random(4));
		
		damage = (int)me->query_skill("youyu-quan", 1);
		
                damage = damage/2 + random(damage/2);
		
		target->receive_damage("qi", damage*2);
		target->receive_wound("qi", damage);
                
    if( damage < 20 ) msg += HIY"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
        	else if( damage < 40 ) msg += HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
        	else if( damage < 80 ) msg += RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
                else msg += HIR"���$n��$N������һ����ǰһ�ڣ��������ɳ�������\n"NOR;
		
	} else 
	{
		me->start_busy(3);
		msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
	}
	message_vision(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}
