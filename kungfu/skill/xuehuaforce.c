// SKILL: xuehuaforce.c ѩ���ķ�
// god


inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if ( me->query("gender") == "����" )
                return notify_fail("�޸����ԡ��������������в�Ů���������������ڹ�!\n");
        
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰѩ���ķ���\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ѩ���ķ���ֻ��ͨ��ѧϰ������������!\n");
}

string exert_function_file(string func)
{
        return __DIR__"xuehuaforce/" + func;
}

