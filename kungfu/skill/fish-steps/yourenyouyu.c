//SKILL : yourenyouyu ��������
//Created by Atlus 1999.7.23.
//

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	if ( me->query_skill("fish-steps",1) < 50 ) return notify_fail("��ġ���Ծ���Ų��������������죡\n");

	if( !target ) target = offensive_target(me);

	if( !target	||	!target->is_character() ||	!me->is_fighting(target) )
		return notify_fail("���������ࡹֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail( target->name()+"�Ѿ���æ�����ˣ�\n");

	message_vision(HIR"$N�Ų�������ʹ�����������ࡹ��������ͬ����������Ԩ��������$nת����ͣ��\n"NOR,me,target);

	if( random( target->query("combat_exp")/2 ) < me->query("combat_exp") )
	{
		message_vision(WHT"���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n"NOR,target);
		me->add("neili",-200);
		target->start_busy(8);
	}
	else {
		message_vision(WHT"���$N�Լ�ת�˸�ͷ���ۻ���\n"NOR,me);
		me->add("neili",-100);
		me->start_busy(2);
	}
	return 1; 
}