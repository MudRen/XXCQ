// �����湦
// Write by godzilla

inherit FORCE;
int valid_enable(string usage)
{
        return usage == "force";
}
int valid_learn(object me)
{

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲������޷���������湦��\n");
        return 1;
}

int practice_skill(object me)
{
       return notify_fail("�����湦ֻ����ѧ(learn)�������������ȡ�\n");
              
}

string exert_function_file(string func)
{
        return __DIR__"tianyu-qigong/" + func;
}
