#include <ansi.h>
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	if ( (int)me->query("kill") < 100)
		return notify_fail("Ѫ�����书��Ҫ����һ����ɱ���֣����ɱ��̫���ˡ�\n");
	if ( (int)me->query_skill("force", 1) < 20)
                return notify_fail("��Ļ����ڹ���򻹲������޷���ữѪ�󷨡�\n");
	return 1;
}
int practice_skill(object me)
{
        return notify_fail("��Ѫ��ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
        return __DIR__"huaxue-dafa/" + func;
}

