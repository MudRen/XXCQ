// fenfei.c ���컨��
 
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

	skill = me->query_skill("sword");
	skill2 = me->query_skill("force");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��������ʹ����ô��ʹ���Һ�ɹ�����\n");

	if( !me->is_fighting()|| !living(me) )
	    	return notify_fail("���Һ�ɹ���ֻ����ս����ʹ�á�\n");

	if( (int)me->query("max_neili") < 600 )
		return notify_fail("���������Ϊ�������ߣ�\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�����ڵ��������㣡\n");

	if( skill < 135)
		return notify_fail("��佻���������Ϊ����������ʹ�á��Һ�ɹ���! \n");

	if( skill2 < 90)
		return notify_fail("������ķ�����Ϊ����������ʹ�á��Һ�ɹ���! \n");

	if( me->query_skill_mapped("sword") != "huanhua-jian") 
		return notify_fail("��û�м���佻��������޷�ʹ�á��Һ�ɹ�����\n");
	ob = me->query_temp("weapon");
 
	msg = HIY"$NͻȻһ������Խ��һ��������"+ob->query("name")+HIY"���ֶ�����һʽ���Һ�ɹ�������һ����Х��$n���ؿڷ����ȥ��\n\n"NOR;
	message_vision(msg, me, target);

	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap)*2 > dp && (random(100)<10))
	{
		me->add("neili",-300);
		msg = HIR "$nһ������������"+ob->query("name")+HIR"��$n����ǰ���ض�������Ѫ���˿�����������ܵ��˿����Ǽ��صġ�\n\n"NOR;
		ob->move(target);
		message_vision(msg, me, target);
		qi_wound = skill*2 + random(skill*4);

		if(qi_wound > target->query("qi"))
			qi_wound = (target->query("qi") + 1);

		target->add("qi", -qi_wound);
		target->add("eff_qi", -(qi_wound/4));
		COMBAT_D->report_status(target, 0);
		me->start_busy(random(4));
	}
	else if( random(ap) > dp )
	{
		me->add("neili",-200);
		msg = HIR "$nŬ��������һ����"+ob->query("name")+HIR"����û�д���Ҫ��������$n���˲��ᣬ��Ȼʹ��ú��������ˡ�\n\n"NOR;
		message_vision(msg, me, target);
		qi_wound = skill + random(skill*2);

		if(qi_wound > target->query("qi"))
			qi_wound = (target->query("qi") + 1);

		target->add("qi", -qi_wound);
		target->add("eff_qi", -(qi_wound/4));
		ob->move(target);
		COMBAT_D->report_status(target, 0);
		me->start_busy(random(4));
	}
	else
	{
		msg = HIG "ֻ��$n���ҵ�����һ�������ţ�����������һ����"+ob->query("name")+HIG"��Ȼ��ͷ�Ϸ����˹�ȥ�������ģ�\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-100);
		destruct(ob);
		me->start_busy(2);
	}

	return 1;
}
