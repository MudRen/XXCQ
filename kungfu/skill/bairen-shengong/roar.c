// roar.c 

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if(environment(me)->query("no_fight"))
		return notify_fail("�����ֹս�����޷����ڹ����ˣ�\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 10);
	me->start_busy(5);
	message_vision(
        HIY "$N��������˼�ȫ���������һ����\n" NOR, me);
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me )
			continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
			continue;
		if( !ob[i]->is_killing(me) )
			ob[i]->kill_ob(me);
		if( !me->is_killing(ob[i]) )
			me->fight_ob(ob[i]);
		damage = skill *2 - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("jingli", damage * 2 );
			ob[i]->add("douzhi",-50);
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jingli", damage);
		tell_object(ob[i], "��ֻ������ǰһ������������������ֱ���������ޱȡ�\n");
		}
	}
	return 1;
}

