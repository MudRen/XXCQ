// �����Ṧ.c

inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
        "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
	"$n���˷�������ǰ̤��һ�����Ƶ�$N��;���С�\n",
	"$n���һ�����ҿ�һ����һʱ����Ӱ�ƺ��������������$N�ε��ۻ����ҡ�\n",
	"$n���������һ���������š���������$N��һ�С�\n",
	"$n�Ų�һ��һ����������$N�ı���\n",
        "$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return notify_fail("������ս���о�����۵Ľ����������ʽ����ôѧ��\n"); }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
