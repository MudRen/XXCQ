// tangmen-biaofa	�����ڷ�

inherit SKILL;

//int valid_enable(string usage) { return usage=="finger"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("tangmen-biaofa", 1);

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������������ڷ���\n");
	return 1;
}

int practice_skill(object me)
{
    return notify_fail("�����ڷ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
    return __DIR__"tangmen-biaofa/" + func;
}