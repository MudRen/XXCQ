// fen.c �����Ի�
// by secret
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target, *inv;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;

	me->clean_up_enemy();
	target = me->select_opponent();

        skill = me->query_skill("huoyan-dao",1);

	if( !(me->is_fighting() ))
                return notify_fail("�������Ի�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("���������˹���\n");

	if( skill < 120)
                return notify_fail("��ġ����浶���ȼ�����, ����ʹ���������Ի𡹣�\n");

    if( me->query_skill("wuxiang-shengong",1) < 100)
                return notify_fail("��ġ������񹦡��ȼ�����, ����ʹ���������Ի𡹣�\n");

	if( me->query("neili") < 600 )
                return notify_fail("��������������޷��˹���\n");
 
        msg = HIC "$N�������ƣ�ʹ��һ�С������Ի𡹣���$n���ؿڻ�ȥ��\n"NOR;

	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-600);


        neili_wound = random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

                qi_wound = random(skill)*2;
//		if(qi_wound > target->query("qi"))

		target->receive_damage("qi", qi_wound);
		target->receive_wound("qi", qi_wound);
		target->add("neili", -neili_wound);
		target->start_busy(2);
		me->start_busy(random(2));

		inv = all_inventory(target);
msg += HIR "$nֻ������ǰһ�ڣ�һ������������������ۡ���һ�����һ����Ѫ��\n"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
msg += HIR "$n�ŵ�һ�ɽ�ζ���������ϵ�"+inv[equip]->query("name")+HIR"�ѱ��յò��Ʋ����������˵��ϣ�\n"NOR;
			inv[equip]->unequip();
			inv[equip]->reset_action();
			inv[equip]->move(environment(target));
			inv[equip]->set("name", inv[equip]->query("name") + "����Ƭ");
			inv[equip]->set("value", 0);
			inv[equip]->set("armor_prop", 0);
			inv[equip]->set("long", "һ���������£������ǲ�Ƭ��Ƭʲô�ġ�\n");
			}
		}
	}
	else
	{
msg += HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me)) me->add("neili",-600);
		me->start_busy(4);
	}
    message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);

	return 1;
}
