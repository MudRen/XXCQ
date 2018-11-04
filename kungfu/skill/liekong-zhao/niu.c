// fenfei.c ��ȭ
// By Load
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	object ob;
	int skill, skill2, ap, dp, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = (int)me->query_skill("claw");
	skill2 = (int)me->query_skill("force");

	if( !me->is_fighting()|| !living(me) || !(string)me->query_temp("qin_3")
	    || !objectp(ob = present((string)me->query_temp("qin_3"), environment(me)))
	    || !ob->is_fighting() || !living(ob)
	    || ob->query_temp("qin")!=1 ||ob->query_temp("qin_2")!=me->query("id"))
	    	return notify_fail("��Ť��ֻ����ս���ж���ס�Ķ���ʹ�á�\n");

	if( (int)me->query("max_neili") < 400 )
		return notify_fail("���������Ϊ�������ߣ�\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����ڵ��������㣡\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("����������ôʹ��Ť����\n");

	if(skill < 135 )
		return notify_fail("���צ���������ң��޷�ʹ�á�Ť����\n");

	if(skill2 < 120 )
		return notify_fail("���ڹ�����Ϊ����������ʹ�á�Ť��! \n");

	if( me->query_skill_mapped("claw") != "liekong-zhao") 
		return notify_fail("��û��ʹ���ѿ�צ���޷�ʹ�á�Ť����\n");
 
	ap = ((me->query("combat_exp"))*(me->query_str()));
	dp = ((target->query("combat_exp"))*(target->query_str()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		qi_wound = skill*2 + random(skill*2);

		if(qi_wound > target->query("qi"))
		{
			msg = HIY "$Nץס$n�����ͻȻһ�ɣ������ķŵ�$n��ͷ��������һ��������$n��ͷ�޷�����ת����Ȼ����������һŤ����\n\n"NOR;
			msg += HIM "����һ�������ꡱ��$n��˫�۾Ϳ��Կ����Լ����Ķ����ˡ���\n\n"NOR;
			msg += HIR "�����$nһ���������������硭��\n\n"NOR;
			message_vision(msg, me, target);
			me->start_busy(2 + random(2));
			target->die();
		}
		else
		{
			msg = HIY "$Nץס$n˫���˫צͻȻ��������Ȼ���ڲ༱תһ�ܣ�$n�ҽ�һ����˫���Ѿ�������ʹ���ˡ�\n\n"NOR;
			msg += HIR "$N�͵�һ˦����$n���ˤ�˳�ȥ��$n��ʹ�ѵ����޷����������ص�ˤ���˵��ϡ�\n\n"NOR;
			message_vision(msg, me, target);
			target->add("qi", -(qi_wound/2));
			COMBAT_D->report_status(target, 0);
			target->delete_temp("qin",1);
			target->interrupt_me();
			target->delete_temp("qin_2");
			me->delete_temp("qin_3");
			me->interrupt_me();
			me->start_busy(2);
		}

		me->add("neili",-300);
	}
	else
	{
		msg = HIY "$Nץס$n˫���˫צͻȻ��������Ȼ���ڲ�Ťȥ��$n�ĸҵ�����˳��һš��˫������һ���ѿ���$N��������\n\n"NOR;
		msg += HIG "$N��$n���Ʒ�����˫צ����һ������˳�ȥ��\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-200);
		me->interrupt_me();
		me->start_busy(3);
		target->delete_temp("qin",1);
		target->interrupt_me();
		target->delete_temp("qin_2");
		me->delete_temp("qin_3");
	}

	return 1;
}
