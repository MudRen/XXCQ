// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if ((int)me->query_skill("pingfeng-dafa", 1) < 40)
		return notify_fail("����������Ϊ��������\n");
	if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
		return notify_fail("�������������\n");
	if ((int)me->query("eff_qi") > ((int)me->query("max_qi")-1))
		return notify_fail("�㲻��Ҫ���ˡ�\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "��ȫ����ɣ�����������������ڹ�����ʼ���ˡ�\n" NOR);
	message("vision",
		HIW + me->name() + "���ۡ���һ���³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
		environment(me), me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
      me->start_busy(1);

	return 1;
}
