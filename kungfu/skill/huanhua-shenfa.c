// tianyu-shenfa.c 佻���
// By Load

inherit SKILL;

mapping *action = ({
([	"action" : "$n���˷����������鶯,һʽ��Դͷ��ˮ������Ȼ��$N�����������С������˹�ȥ��\n",
]),
([	"action" : "$n�����ĳ�������Ӱ��һʽ���޾���������ȴ���𹥷��ˣ�������������һ�ߡ�\n",
]),
([	"action" : "$nһʽ����Ӣ�ͷס������ζ������ɣ�Ȼ��бб���£�$N��Ȼ׷֮�����ˡ�\n",
]),
([	"action" : "$n���μ�����һʽ���������̡�����ʱ$n��Ȼ��$N��ǰƾ����ʧ����Ӱ���١�\n",
]),
([	"action" : "$n��һ������һ���������ߣ�һʽ�������˼䡹����Ȼ�漣��ĵ���$N�ı���\n",
]),
([	"action" : "$n���ܲ�����һʽ���Ϫ�ɻ��������֮����������У�Ʈ��������֮�⡣\n",
])
});

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_enable(string usage)
{
	return usage == "dodge";
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
	if( (int)me->query("jingli") < 50 )
		return notify_fail("�������̫���ˣ�������佻�����\n");
	me->receive_damage("jingli", 25);
	return 1;
}