// xuantian-xinfa �����ķ�
// By Load

inherit FORCE;
#include <ansi.h>

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ�����ķ���\n");

        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query_skill("xuantian-xinfa", 1) < 180)
                return notify_fail(CYN"����ڹ���Ϊ���������޷��Լ����������ķ���\n"NOR);
        else
                return notify_fail(CYN"�������������ķ��ݲ����ţ�����ȴ�...\n"NOR);
}

string exert_function_file(string func)
{
        return __DIR__"xuantian-xinfa/" + func;
}
