// perform: feixing.c 
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.4.30
// Big Modified
// 
 
#include <ansi.h>
 
inherit F_SSERVER;

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
	if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
	if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
	if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
	if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
	if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
	if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
	if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

varargs void report_status(object ob)
{
	message_vision( "( $N" + status_msg(
		(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
		+ " )\n", ob);
}

int perform(object me)
{
        string msg;
	object weapon, target;
	object ob;
	int skill, skill2, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

        skill = (me->query_skill("duzi-du",1)+(me->query_skill("lphand",1))/2);
	skill2 = (me->query_skill("zhixin",1)+(me->query_skill("force",1))/2);

        if( !me->is_fighting() || !living(me) )
                return notify_fail("������֮����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������֮��������ͽ��ʹ�á�\n");

        if( skill < 100)
                return notify_fail("��ġ����ֶ����ȼ�����, ����ʹ�á�����֮������\n");

        if( me->query("neili") < 200 )
                return notify_fail("��������������޷����á�����֮������\n");
 
        msg = HIC "$N�������ʳָ����ǰд��һ�����ġ������֣�Ȼ��˫��һ��ǡ������־�Ȼ��$p��ȥ��\n"NOR;
        message_vision(msg, me, target);

	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap)*2 > dp && (random(100)<10))
	{
		if(userp(me))
			me->add("neili",-100);

                msg = HIR "$nһ������������"+HIR"�ǡ������־�Ȼ��ȫ����$n����ǰ��$n�����������һ�£���ɫѸ�ٱ�ڣ�����$n�Ѿ����ˡ�\n\n"NOR;
		message_vision(msg, me, target);
                target->die();
		me->start_busy(random(6));
	}
	else if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIR "$nŬ��������һ����"+HIR"�ǡ������ֵ�һ�ǻ���������$n��$n����ɫѸ�ٱ�ڣ���Ȼ���˲�С�Ķ���$nҧ��ҧ������Ȼʹ��ú��������ˡ�\n\n"NOR;
		message_vision(msg, me, target);
		qi_wound = skill + random(skill*2);

		if(qi_wound > target->query("qi"))
			qi_wound = (target->query("qi") + 1);

		target->add("qi", -qi_wound);
		target->add("eff_qi", -(qi_wound/4));
                target->apply_condition("feixing_poison", random(me->query_skill("duzi-du")/10) + 1 + me->query_condition("feixing_poison"));
		report_status(target);
		me->start_busy(random(6));
	}
	else
	{
		msg = HIG "ֻ��$n���ҵ������������࣬"+HIG"һ����Ư�����ǡ������ֵķ���·�ߣ������ģ�\n\n"NOR;
		message_vision(msg, me, target);
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(3);
	}

	return 1;

}
