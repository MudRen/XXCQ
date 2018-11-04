// tiexian-quan.c ����ȭ
// ƽ��damage:120 ƽ��force:90 ƽ��dodge:5 ƽ��parry:-5
// ����ȭ���ص����������ϴ��мܽ��ѣ���ܽ���
// By Load

inherit SKILL;

mapping *action = ({
([	"action" : "$N��ۺ�ɨ����ȭ���������ƿ�֮��ֱ��������һʽ�����ֱײ������$n��$l��ȥ��",
	"damage" : 60,
	"parry"  : -5,
	"force"  : 50,
	"lvl"  : 0,
	"dodge"  : 10,
	"skill_name" : "���ֱײ",
	"damage_type" : "����"
]),
([	"action" : "$N����һ�ɸߣ�һʽ��ʯ���쾪����˫�ֺ�ȭ����һ����������$n��ͷ������ȥ��",
	"damage" : 70,
	"parry"  : 5,
	"force"  : 60,
	"lvl"  : 12,
	"dodge"  : -5,
	"skill_name" : "ʯ���쾪",
	"damage_type" : "����"
]),
([	"action" : "$N��ȭ���أ����ƽ�죬һʽ�������Ὥ�����������ף�������$nײ�˹�ȥ��",
	"damage" : 90,
	"parry"  : -5,
	"force"  : 70,
	"lvl"  : 24,
	"dodge"  : 10,
	"skill_name" : "�����Ὥ",
	"damage_type" : "����"
]),
([	"action" : "$N�������������������һ�����ȣ����硸����է�졹��$nһ��֮�䣬$N��ȭͷ��Ȼ��������ǰ��",
	"damage" : 100,
	"parry"  : -15,
	"force"  : 80,
	"lvl"  : 36,
	"dodge"  : 0,
	"skill_name" : "����է��",
	"damage_type" : "����"
]),
([	"action" : "$N�����һ�ٵأ���ǰ����һ����һʽ��ɽ�����ѡ���˫ȭһǰһ�󣬳�$n���˳�ȥ��",
	"damage" : 120,
	"parry"  : 0,
	"force"  : 100,
	"lvl"  : 48,
	"dodge"  : 10,
	"skill_name" : "ɽ������",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ�������ſա���˫ȭ���տ�ţ����������������������$n��$l��",
	"damage" : 140,
	"parry"  : 5,
	"force"  : 110,
	"lvl"  : 60,
	"dodge"  : 5,
	"skill_name" : "�����ſ�",
	"damage_type" : "����"
]),
([	"action" : "$N˫��ٵأ���������������ȭ�Ų��ã�һʽ���������������$n������ȥ��",
	"damage" : 180,
	"parry"  : -5,
	"force"  : 120,
	"lvl"  : 75,
	"dodge"  : 5,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$NԳ����չ�����α��ǣ�ƽ�ط��ף�һȭ���������Ϊ֮��ɫ��������޼᲻�ݡ����������ˡ�",
	"damage" : 200,
	"parry"  : -20,
	"force"  : 130,
	"lvl"  : 90,
	"dodge"  : 5,
	"skill_name" : "�޼᲻��",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "cuff") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="feixu-zhang"; }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("jiuqu-xinfa", 1) < 40)
		return notify_fail("��ľ����ķ���򲻹���\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ϰ����ȭ���ܳ�������\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������ȭ��\n");
	if ((int)me->query("jingli") < 60)
		return notify_fail("�㾫�����ƣ�ͣ��޷���ϰ����ȭ��\n");
	me->add("neili", -20);
	me->add("jingli",-30);
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("tiexian-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
	return __DIR__"tiexian-quan/" + action;
}
