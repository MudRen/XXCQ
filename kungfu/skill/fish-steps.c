
// SKILL:fish-steps.c
// Created by Atlus 1999.7.23

inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ����һ�С����ƶ������ڿն���ʮ�����׵ıܿ���һ����\n",
        "$n������ת��һ�С������ĺ�����ȫ����������Ӱ�ӳ�һ��֮�⡣\n",
        "$n���۵��һ�С�������λ�������μ������㿪$N������һ����\n",
        "$n���λζ���һ�С�����������������һŤ���ӳ��߳�֮�⡣\n",
        "����$nʹһ�С������ˮ������������Ʈ�˿�ȥ�������Ƶ�$N���ᣡ\n",
        "$n����ʹ��һʽ[��Ӱ����]������Ʈ��������$N�Ĺ���ʧȥ��׼ͷ������$n������ǰ�� \n",
        "$nͻȻһ���������ڿ��гɺ�һ���Σ���һƬ��Ҷ�ɵ�ˮƽ�Ļ��ȣ�������$N��һ���� \n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("�������̫���ˣ�����Ϣһ����ɡ�\n");
        me->receive_damage("qi", 30);
        return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 20;
} 
string perform_action_file(string action)
{
	return __DIR__"feiyu-steps/" + action;
}

