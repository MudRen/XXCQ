// SKILL: wenguzhixin.c �¹�֪��
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.5.28
// �޸�������
// ԭ���书�����ˣ��ޡ��Դ���

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("zhixin", 1);

        if ( me->query("gender") == "����" )
                return notify_fail("�޸����ԡ��������������в�Ů�������������ڹ�!\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("���¹�֪�¡�ֻ��ͨ��ѧ���˹�(exert)��������������!\n");
}

string exert_function_file(string func)
{
        return __DIR__"zhixin/" + func;
}