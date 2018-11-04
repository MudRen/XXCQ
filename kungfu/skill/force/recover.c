// recover.c

//inherit SSERVER;

int exert(object me, object target)
{
	int n, q;

	if (me != target)
		return notify_fail("��ֻ�����ڹ������Լ�����Ϣ��\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("�������������\n");

	q = (int)me->query("eff_qi") - (int)me->query("qi");
	if (q < 10)
		return notify_fail("�������������档\n");
	n = 100 * q / me->query_skill("force");
	if (n < 20)
		n = 20;
	if ((int)me->query("neili") < n) {
		q = q * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

	me->add("neili", -n);
	me->receive_heal("qi", q);
	
        message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
