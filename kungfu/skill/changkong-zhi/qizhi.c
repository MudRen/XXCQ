// qizhi.c ������ָ
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill;

	skill = me->query_skill("changkong-zhi",1);

	if( !(me->is_fighting() ))
		return notify_fail("��������ָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��������ָ������ͽ��ʹ�á�\n");

	if( skill < 100)
		return notify_fail("��ġ�����ָ���ȼ�����, ����ʹ�á�������ָ����\n");

	if( me->query("neili") < 220 )
		return notify_fail("��������������޷����á�������ָ����\n");
 
	msg = HIC "$NͻȻ������Х��˫�ֽ����ӳ����������쾢��������㵯����ָ��\n"NOR;
	message_vision(msg, me, target);

	me->clean_up_enemy();
	target = me->select_opponent();

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
//	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
//	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
//	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

 	me->add("neili", -200);
	me->start_busy(random(3));

	return 1;
}
