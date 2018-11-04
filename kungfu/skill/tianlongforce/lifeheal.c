// lifeheal.c
// from jiuyang-shengong

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ���Ҫ����?\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 250 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 4 )
		return notify_fail( target->name() +
			"�Ѿ��������ص����ˣ������������Ὣ�������ģ�\n");
        if( me == target ) {
                return notify_fail("�������Լ����ˣ������˹��ķ������ԡ�\n");
				}
	else {message_vision(
		HIY "$N��ϥ����,�����������񹦣���������������$n���ģ������ؽ���������$n����....\n"
		    "$nֻ��һ�������ӱ���ԴԴ�������ڣ�˲������ȫ�����Ѩλ��\n"NOR,
		me, target );
	}
	target->receive_curing("qi", 30 + (int)me->query_skill("tianlongforce")/3 );
	target->add("qi", 30 + (int)me->query_skill("tianlongforce")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -150);
	me->set("jiali", 0);

	return 1;
}
