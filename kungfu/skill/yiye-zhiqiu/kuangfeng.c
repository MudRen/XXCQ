// kuangfeng.c  ���ɨ��Ҷ

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object ob;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����ɨ��Ҷ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ( !ob=present("bajiaoye",me) )
		return notify_fail("�����Ϻ���ȱһ�����������ܷ������е�������\n");
	
         if ( (int)me->query("shen") < 5000 )
		return notify_fail("��������������������Ʋ�����Ҷ�ķ��й켣��\n");
		
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return 0;
		
	if( (int)me->query_skill("yiye-zhiqiu", 1) < 50 )
		return notify_fail("���һҶ֪�ﲻ����죬����ʹ�á�\n");
	                        
	if( (int)me->query_skill("bairen-shengong", 1) < 50 )
		return notify_fail("��İ��̲���һŭ�񹦲����ߡ�\n");
			
	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á����ɨ��Ҷ����\n");
			
	msg = CYN "$N����Ϣ�������󼲶���һ���׹����ȭ������$n��\n"NOR;

	if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
                target->start_busy( (int)me->query_skill("yiye-zhiqiu") / 20 + 1);
		
		damage = (int)me->query_skill("bairen-shengong", 1);
		damage = damage +  (int)me->query_skill("yiye-zhiqiu", 1);
		damage = damage +  (int)me->query_skill("cuff", 1);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
                me->add("neili", -(damage/3));
		msg += HIR"ֻ���׹��Ϊһ�ߣ�����$n,\n$nֻ��һ���������Ķ�������ͷһ����Ѫ���������\n"NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
		me->add("neili", -100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
