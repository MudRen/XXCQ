// fenfei.c �����׷�
 
#include <ansi.h>
 
inherit F_SSERVER;

void banruo2(object me);
void banruo3(object me);

int perform(object me)
{
	string msg;
	object weapon, target;
	int ap, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( !me->is_fighting()|| !living(me) )
	    	return notify_fail("������������ֻ����ս����ʹ�á�\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ��С�����������򲻳�����\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����ڵ��������㡣\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("����������ôʹ��������������\n");

	if(me->query_skill("strike") < 90)
		return notify_fail("����Ʒ��������ң���С�����������򲻳�����\n");

	if(me->query_skill("force") < 90)
		return notify_fail("���ڹ�����Ϊ��������С�����������򲻳�����\n");

	if( me->query_skill_mapped("strike") != "banruo-zhang") 
		return notify_fail("��û�м��������ƣ��޷�ʹ�ð�������\n");
 
	if( me->query_skill_mapped("force") != "banruo-changong") 
		return notify_fail("���õ��ڹ����ǰ����������޷�ʹ�ð�������\n");

	if (me->query_temp("banruo",1))
		return notify_fail("���Ѿ������ð��������ˡ�\n");

	msg = HIY "$NͻȻ�������ƣ�����С���������������ƴ�һ�㵭���İ���ֱֱ����$n����ǰ��\n\n"NOR;
	message_vision(msg, me, target);

	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		msg = HIR "$n����һ�ţ�һ��������������$N�ĵ���ʵʵ���ڵ�ӡ�����ţ�$n���������̾�������ȥ��\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-300);
		damage = 100 + me->query_skill("strike") + random(me->query_skill("force"));
		target->receive_damage("qi", damage);
		COMBAT_D->report_status(target, 0);
		me->start_busy(3);
	}
	else
	{
		msg = HIG "ֻ��$n��ɫһ�ݣ�����Ӳ�ӣ�һ������ʱ���˳�սȦ���㿪��$N�����Ĺ��ƣ�\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-100);
		me->start_busy(3);
	}

	call_out("banruo2", 3, me);

	return 1;
}

void banruo2(object me)
{
	string msg;
	object weapon, target;
	int ap, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( !me->is_fighting()|| !living(me) )
	    	return;

	if( (int)me->query("max_neili") < 1000 )
		return;

	if( (int)me->query("neili") < 500 )
		return;

	if (objectp(weapon = me->query_temp("weapon")))
		return;

	if(me->query_skill("strike") < 180)
		return;

	if(me->query_skill("force") < 180)
		return;

	if( me->query_skill_mapped("strike") != "banruo-zhang") 
		return;

	if( me->query_skill_mapped("force") != "banruo-changong") 
		return;

	msg = WHT "$N˫��һ����ɫ������Ȼ����ȫ������֮��������ڶ��ơ��������������Ȼ�ĳ���\n\n"NOR;
	message_vision(msg, me, target);

	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap * 4 / 3) > dp )
	{
		msg = HIR "$n���Ŀ�䣬$N˫���ѵ�����ǰ���ھ�һ�£�$n��ʱ������Ѫ�����ɳ��������࣡\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-500);
		damage = 200 + me->query_skill("strike") + 2 * random(me->query_skill("force"));
		target->receive_damage("qi", damage);
		COMBAT_D->report_status(target, 0);
		me->start_busy(3);
	}
	else
	{
		msg = HIG "$n���޿ɶ㣬�͵�һ�����ǳ��Ǳ��Ŀ����㿪����ڶ��ơ�\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-200);
		me->start_busy(3);
	}

	call_out("banruo3", 3, me);

	return;
}

void banruo3(object me)
{
	string msg;
	object weapon, target;
	int ap, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( !me->is_fighting()|| !living(me) )
	    	return;

	if( (int)me->query("max_neili") < 1500 )
		return;

	if( (int)me->query("neili") < 700 )
		return;

	if (objectp(weapon = me->query_temp("weapon")))
		return;

	if(me->query_skill("strike") < 270)
		return;

	if(me->query_skill("force") < 270)
		return;

	if( me->query_skill_mapped("strike") != "banruo-zhang") 
		return;
 
	if( me->query_skill_mapped("force") != "banruo-changong") 
		return;

	msg = HIW "$N��ɫ���أ������߳߾���ӿ����ͻȻ���һ���������ְ������������Ϲ����ջ��������������������ӿ������\n\n"NOR;
	message_vision(msg, me, target);

	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap * 3 / 2) > dp )
	{
		msg = HIR "$n��һƬ��Ҷ�������������������ӿ������Χ������ѹ�⡢���£����ص�ˤ�ڵ��ϣ��ۿ��ǲ����ˣ�\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-700);
		damage = 300 + me->query_skill("strike") + 3 * random(me->query_skill("force"));
		target->receive_damage("qi", damage);
		COMBAT_D->report_status(target, 0);
		me->start_busy(random(10));
	}
	else
	{
		msg = HIG "$nһ���ۣ���$N�ķ�������һ�����ǰ㼱�˶���������ӹ��Ź��ϼ����һ������\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-300);
		me->start_busy(5);
	}

	return;
}
