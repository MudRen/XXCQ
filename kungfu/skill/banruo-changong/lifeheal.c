// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if ((!target)||target->query("id")==me->query("id"))
		return notify_fail("����yun healΪ�Լ����ˡ�\n");

	if (me->query_skill("banruo-changong",1) < 60)
		return notify_fail("��û�дﵽС�����񹦵ľ��磬�޷����������ˡ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");


	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_vision(
		HIY "$N��ϥ����$n���һ���������������������������һ����������������ȥ����\n"NOR + 
		HIC"$n�����͵�һ��һ��"NOR+RED"����ɫ��Ѫ"NOR+HIC"�������ɫ��������������ࡣ\n\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/5 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -150);
	me->set("jiali", 0);
	return 1;
}