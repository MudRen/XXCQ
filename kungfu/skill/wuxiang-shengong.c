// wuxiang-shengong.c ���� ������
// dts@xkx, cleansword@xkx

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
    if ( (int)me->query_skill("buddha", 1) < 20 && (int)me->query_skill("buddha", 1) <= (int)me->query_skill("wuxiang-shengong", 1))
		return notify_fail("��������ķ����򲻹����޷���������������񹦡�\n");

	if ( (int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷���������񹦡�\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"wuxiang-shengong/" + func;
}
