// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	if (target != me) 
		return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");
	
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������\n");

	me->add("neili", -20);
	me->receive_heal("jing", (int)me->query_skill("force") / 3);
	
        message_vision("$N�������˼����������������ö��ˡ�\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}

