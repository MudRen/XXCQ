// qin.c ��
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int num, skill, skill2, ap, dp,damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = (int)me->query_skill("claw");
	skill2 = (int)me->query_skill("force");
	num = skill / 50;

	if( !me->is_fighting()|| !living(me) )
	    	return notify_fail("���ܡ�ֻ����ս����ʹ�á�\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ�������ߣ�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�����ڵ��������㣡\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("����������ôʹ���ܡ���\n");

	if(skill < 100 )
		return notify_fail("���צ���������ң��޷�ʹ�á��ܡ���\n");

	if(skill2 < 90)
		return notify_fail("���ڹ�����Ϊ����������ʹ�á��ܡ�! \n");

	if( me->query_skill_mapped("claw") != "liekong-zhao") 
		return notify_fail("��û��ʹ���ѿ�צ���޷�ʹ�á��ܡ���\n");
 
	msg = HIW "$N���һצ��ͻȻ����������˫צ����������Ѹ�ײ����ڶ�֮�ƿ���$n��˫��\n\n"NOR;

	message_vision(msg, me, target);
 
	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/3;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if (random(me->query("max_neili")*me->query_str())>random((target->query("max_neili")*target->query_str())/2))
		{
			me->add("neili",-200);
			msg = HIY "$nһ������������˫���ѱ�$N�۸����ţ�$N˳��һŤ���Ѿ���$n��˫��Ť�������$nһ���ӱ㶯�������ˣ�\n\n"NOR;
			message_vision(msg, me, target);
			me->start_busy(6);
			target->start_busy(6);
			target->set_temp("qin",1);
			target->set_temp("qin_2",me->query("id"));
			me->set_temp("qin_3",target->query("id"));
			call_out("check", 6, me, target);
		}
		else
		{
			damage = skill + random(skill);
			target->add("neili",100);
			me->add("neili",-200);
			msg = HIR "$nû�ж�������$N˫צһ��$n��˫��ͻ����������ʱһ�ɴ�����$N�����ȥ��$N�е����һ��һ����Ѫ�����˳�����\n\n"NOR;
			message_vision(msg, me, target);
			target->receive_damage("qi", damage);
			target->receive_wound("qi", damage/3);
			COMBAT_D->report_status(me, 0);
		}
	}
	else
	{
		msg = HIG "ֻ��$n˫�ۼ�����һ�����������߳߿��⣬�㿪��$N������һ�ۣ�\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-100);
		me->start_busy(3);
	}

	return 1;
}

int check(object me,object target)
{
	object weapon;
	string msg;

 	if(me->is_fighting() && living(target) && living(me) && (!objectp(weapon = me->query_temp("weapon")))
		&& target->query_temp("qin"))
	{
		int a,b;
		a=(me->query("max_neili"))*(me->query_str());
		b=(target->query("max_neili"))*(target->query_str());
		if ((random(a)>random(b))&& me->query("neili")>200)
		{
			msg = HIY "\n$n��������������$N˫������ǯһ����˿������ʵ�����Ѳ�����\n\n"NOR;
			message_vision(msg, me, target);
			me->add("neili",-100);
			if (target->query("neili")>50) target->add("neili",-50);
			me->start_busy(6);
			target->start_busy(6);
			target->set_temp("qin",1);
			target->set_temp("qin_2",me->query("id"));
			me->set_temp("qin_3",target->query("id"));
			call_out("check", 6, me, target);
		}
		else
		{
			msg = HIC "\n$n����$N�ƺ��������Ĺ���˫צ���ɣ�æ�û���ȫ������ƴ��һ������Ȼ���ѿ���$N��������\n\n"NOR;
			message_vision(msg, me, target);
			target->delete_temp("qin",1);
			target->interrupt_me();
			target->delete_temp("qin_2");
			me->delete_temp("qin_3");
			me->interrupt_me();
			me->start_busy(2);
		}
	}
	return 1;
}
