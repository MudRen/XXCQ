// fenfei.c ��ȭ
// By Load
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	object ob;
	int skill, skill2, ap, dp,qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = (int)me->query_skill("cuff");
	skill2 = (int)me->query_skill("force");

	if( !me->is_fighting() || !living(me) )
	    	return notify_fail("����ȭ��ֻ����ս����ʹ�á�\n");

	if( (int)me->query("max_neili") < 800 )
		return notify_fail("���������Ϊ�������ߣ�\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("����������ôʹ����ȭ����\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("�����ڵ��������㣡\n");

	if( skill < 135 )
		return notify_fail("���ȭ���������ң��޷�ʹ�á���ȭ����\n");

	if( skill2 < 120)
		return notify_fail("���ڹ�����Ϊ����������ʹ�á���ȭ��! \n");

	if( me->query_skill_mapped("cuff") != "tiexian-quan") 
		return notify_fail("��û�м�������ȭ���޷�ʹ�á���ȭ����\n");
 
	msg = HIY "$NͻȻ��ǰ�������󲽣��������һ���ƺȣ���ȭһ�ǡ���ȭ����������Ȼ�ӳ���
�������ס���������ȴ�ּ�򵥵���ȫ�޻��ɣ�ֱ��$n��ȥ������\n\n"NOR;
	message_vision(msg, me, target);
 
	ap = ((me->query("combat_exp"))*(me->query_str()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-500);

		msg = HIR "$n������������$N����һȭ����ǰ�ģ����ء�һ�����죬ǰ����Ȼ������ȥ��
$n����ɫ���ɷ�ף�һ����Ѫ��$n���п��������\n\n"NOR;
		message_vision(msg, me, target);
		qi_wound = skill*2 + random(skill*2);

		if(qi_wound > target->query("qi"))
			qi_wound = (target->query("qi") + 1);

		target->add("qi", -qi_wound);
		COMBAT_D->report_status(target, 0);
		me->start_busy(2 + random(3));
	}
	else if( ob = target->query_temp("weapon")
	&& (random(me->query("combat_exp")))>(random(target->query("combat_exp"))))
	{
		if(userp(me))
		{
			ob = target->query_temp("weapon");
			me->add("neili",-400);
			message_vision(HIW "æ�Ҽ�$N������" + ob->name() +
				"ȥ����ȭ,ȴֻ������ž����һ����$N���е�" + ob->name() +
				"�Ѿ���Ϊ���أ�\n" NOR, target );
			ob->unequip();
			ob->move(environment(target));
			ob->set("name", "�ϵ���" + ob->query("name"));
			ob->set("value", 0);
			ob->set("weapon_prop", 0);
			target->reset_action();
			me->start_busy(random(3));
		}
	}
	else
	{
		msg = HIG "ֻ��$n��ɫһ�ݣ�����Ӳ�ӣ�һ������ʱ���˳�սȦ���㿪��$N�����Ĺ��ƣ�\n\n"NOR;
		message_vision(msg, me, target);
		if(userp(me))
			me->add("neili",-200);
		me->start_busy(3);
	}

	return 1;
}
