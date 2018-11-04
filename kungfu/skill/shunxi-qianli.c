// shunxi-qianli.c ˲Ϣǧ��
// ˲Ϣǧ����С��ɽ�ɵ��Ṧ���ص�������������Ч������
// ������Ӧ��

inherit SKILL;

mapping *action = ({
([	"action" : "$n˫��ӭ�磬Ʈ�����˲���Ѿ��˳����������࣬$N����ʽҲ����Ȼ���˿ա�\n",
	"dodge"  : 15
]),
([	"action" : "$n���μ�ת����һת����һת���������ɵĽ�$N�Ĺ���ж��һ�ߡ�\n",
	"dodge"  : 30
]),
([	"action" : "$n�첽���ߣ��������У���������ļ��������ߵ���ս��֮�⡣\n",
	"dodge"  : 45
]),
([	"action" : "$n����һ�㣬���η�ҡֱ�ϣ�ȴ�ڰ����һ��ת�ۣ���ƮƮ��������$N���\n",
	"dodge"  : 60
]),
([	"action" : "����$n���Ų�æ��������������ˮ������һƮ...��һƮ����ܵ�����߿��⡣\n",
	"dodge"  : 75
]),
([	"action" : "$n�������ˣ�����ֻ������һת������һ�������$N����ӹ���\n",
	"dodge"  : 90
]),
([	"action" : "$n���˷�������$N����֮����Ȼ����վ��$N������⡣\n",
	"dodge"  : 105
]),
([	"action" : "$n�Ų����㣬����΢����$N��ǰһ����Ȼ������$n����Ӱ��\n",
	"dodge"  : 120
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shunxi-qianli");

	if (level < 80 )
		zhaoshu--;

	if (level < 60 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("�������̫���ˣ�������˲Ϣǧ�\n");
	me->receive_damage("qi", 30);
	return 1;
}