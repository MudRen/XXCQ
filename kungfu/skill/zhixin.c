// SKILL: wenguzhixin.c �¹�֪��
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.4.27
// 
// 

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("zhixin", 1);

        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ�����������������������¹�֪�¡�\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("�¹�֪��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"zhixin/" + func;
}