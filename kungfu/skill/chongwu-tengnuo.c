// ����ʹ�õ��书
// By ɽèAdx @ snow 99-12-12

inherit SKILL;

mapping *action = ({
([	"action" : "$n˫צһ��������$Nͷ�����������\n",
	"dodge"  : 10
]),
([	"action" : "$n˫��һԽ��������$N�Ĺ��ơ�\n",
	"dodge"  : 30
]),
([	"action" : "$n����һ�����������$N�����\n",
	"dodge"  : 50
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("chongwu-tengnuo");

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
