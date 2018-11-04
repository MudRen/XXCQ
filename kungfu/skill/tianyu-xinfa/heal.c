// heal.c	heal for tianyu-xinfa by winder

#include <ansi.h>

int exert(object me, object target)
{
	if ( (string)target->query("id") == (string)me->query("id") )
	{
		if ((int)me->query_skill("tianyu-xinfa", 1) < 20)
			return notify_fail("��������ķ���Ϊ��������\n");

		if( me->is_fighting() )
			return notify_fail("ս�����˹����ˣ�������\n");
	
		if( (int)me->query("neili") < 50 )
			return notify_fail("�������������\n");

		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

		if( ((int)me->query("eff_qi") == (int)me->query("max_qi")) && ( (int)me->query("qi") == (int)me->query("eff_qi") ))
			return notify_fail("�����ڲ���Ҫ�˹����ƣ�\n");

		write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
		message("vision",HIW + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,environment(me), me);
	
		me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
		me->add("neili", -50);
		me->set("jiali", 0);
		me->start_busy(1);

		return 1;
	}
	else
	{
		if( !objectp(present(target, environment(me))) || !living(target) )
			return notify_fail("����û������ˡ�\n");
		
		if ((int)me->query_skill("tianyu-xinfa", 1) < 20)
			return notify_fail("��������ķ���Ϊ��������\n");

		if( me->is_fighting() || target->is_fighting())
			return notify_fail("ս�����޷��˹����ˣ�\n");

		if( (int)me->query("max_neili") < 100 )
			return notify_fail("���������Ϊ������\n");

		if( (int)me->query("neili") < 100 )
			return notify_fail("�������������\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

		if( ((int)target->query("eff_qi") == (int)target->query("max_qi")) && ( (int)target->query("qi") == (int)target->query("eff_qi") ))
			return notify_fail( target->name() + "���ڲ���Ҫ�˹����ƣ�\n");

		message_vision(HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,	me, target);

//		target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
		target->add("qi", 10 + (int)me->query_skill("force")/3 );
		target->add("jingli", 10 + (int)me->query_skill("force")/3 );

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") )
			target->set("eff_qi", (int)target->query("eff_qi") + (int)target->query("max_qi")/20);

		if( (int)target->query("eff_qi") > (int)target->query("max_qi") )
			target->set("eff_qi", (int)target->query("max_qi"));

		if( (int)target->query("jingli") > (int)target->query("eff_jingli") )
			target->set("jingli", (int)target->query("eff_jingli"));

		if( (int)target->query("qi") > (int)target->query("eff_qi") )
			target->set("qi", (int)target->query("eff_qi"));

		me->add("neili", -100);
		me->set("jiali", 0);
		me->start_busy(2);
		target->start_busy(1);

		return 1;
	}
}