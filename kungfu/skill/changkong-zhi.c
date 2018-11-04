// changkon-zhi.c ������ָ

inherit SKILL;

mapping *action = ({
([	"action" : "$N����ͻȻƽֱ�������ָ��Ȼ����������$n��$l",
	"damage" : 100,
	"damage_type" : "����"
]),
([	"action" : "$NͻȻת����ָ�������Ҵ���������ָ������$n��$l",
	"damage" : 150,
	"damage_type" : "����"
]),
([	"action" : "$N����̧�ۣ��ֱ����¶�����$n��ǰҪѨ��ȥ",
	"damage" : 200,
	"damage_type" : "����"
]),
([	"action" : "$N�������ݼ�ת��ͣ�����ֲ��ϵ���ȫ��ͣ�٣���������ֱ��$n����",
	"damage" : 250,
	"damage_type" : "����"
]),
([      "action" : "$N����̩ɽΡȻ������˫��ȴ����ӳ���Ϯ��$n�����Ѩ��",
        "damage" : 300,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "finger") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="tianyu-qijian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("tianyu-qigong", 1) < 150)
		return notify_fail("��������湦��򲻹���\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ϰ������ָ���ܳ�������\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("�������������������ָ��\n");
    me->add("neili",-40);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"changkong-zhi/" + action;
}
