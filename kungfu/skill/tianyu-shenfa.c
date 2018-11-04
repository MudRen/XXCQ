// tianyu-shenfa.c ������

inherit SKILL;

mapping *action = ({
([
	"action" : "$nһʽ���沨����������ͬ�������ľ���ݿ壬��󵹷���һ�ɿ��⡣\n",
]),
([
	"action" : "$nһʽ����Ӱ���Ρ���������һ���ڸ���$N���$N����ôҲ�޷����ѡ�\n",
]),
([
	"action" : "$nһʽ�����л�λ����$N����ǰ��û����$n�ټ���һʱ����ԭ�ز�֪����Ǻá�\n",
]),
([
	"action" : "$nһʽ�������½�����������$N����������������ǰ����\n",
]),
([
	"action" : "$nһʽ��ʯ���󺣡�������ͻȻһ������$N�ٿ�ȥȴû������Ӱ��\n",
])
});

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
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
//	action = query_action(ob, me);

	return action["action"];
//	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("�������̫���ˣ���������������\n");
	me->receive_damage("qi", 30);
	return 1;
}