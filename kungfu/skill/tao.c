// tao.c ����˼��
// By Star

inherit FORCE;

int valid_learn(object me)
{
	if ( me->query_skill("buddha",1)
	|| me->query_skill("confu",1))
		return notify_fail("�塢�͡������һ������ݣ��㻹���������˼�룬��ôѧϰ�������ۣ���\n");

	return 1;
}