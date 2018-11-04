// feixu-zhang.c ������
// ƽ��damage:90 ƽ��force:90 ƽ��dodge:-10 ƽ��parry:5
// �����Ƶ��ص�����������С���мܽ��ף���ܽ���
// By Load

inherit SKILL;

mapping *action = ({
([	"action" : "$N˫�۲�����˫�Ʒ����紺��է�֣�̤ǰһ����һʽ������ӭ������������$n��",
	"damage" : 30,
	"parry"  : 10,
	"force"  : 50,
	"lvl"  : 0,
	"dodge"  : -10,
	"skill_name" : "����ӭ��",
	"damage_type" : "����"
]),
([	"action" : "$N����΢�����۽�$n�����ֱ����ơ��ٹ����㡹������Ѹ�ݵ������$n���գ���$n����ȥ��ȴ��ͻȻ����",
	"damage" : 60,
	"parry"  : 5,
	"force"  : 60,
	"lvl"  : 12,
	"dodge"  : -15,
	"skill_name" : "�ٹ�����",
	"damage_type" : "����"
]),
([	"action" : "$N�����ڿգ���$n���壬˫�ۻ�Բ��һʽ���������ġ���˫������$n�޿��赲��������ȥ��",
	"damage" : 80,
	"parry"  : 0,
	"force"  : 70,
	"lvl"  : 24,
	"dodge"  : -5,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N���Ȱ��������$n�����һ����Ȼ����������$n����󣬶���ʽ���������꡹$n�ƺ����޲����",
	"damage" : 90,
	"parry"  : 15,
	"force"  : 80,
	"lvl"  : 36,
	"dodge"  : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$NͻȻ���٣���$n��Χ�������ߣ�����ʵʵ������˷���$n�ĳ���������Ӱ����һʽ����Ҷ֪�����$n�޴ӷ���",
	"damage" : 90,
	"parry"  : 10,
	"force"  : 100,
	"lvl"  : 48,
	"dodge"  : -20,
	"skill_name" : "��Ҷ֪��",
	"damage_type" : "����"
]),
([	"action" : "$Nվ��������Ǳ���ڹ���ͻȻһ�����ȣ�˫��һ�ƣ�һʽ����Ұ�ٷ硹��һ�ɴ���Я쫷���$nӵȥ��",
	"damage" : 100,
	"parry"  : 5,
	"force"  : 110,
	"lvl"  : 60,
	"dodge"  : 5,
	"skill_name" : "��Ұ�ٷ�",
	"damage_type" : "����"
]),
([	"action" : "$N���κ��ߺ��ͣ�˫���絶����Ե���������⣬һʽ����ѩ�涬����$n�����ϵĿ�ȥ",
	"damage" : 120,
	"parry"  : 0,
	"force"  : 120,
	"lvl"  : 75,
	"dodge"  : -10,
	"skill_name" : "��ѩ�涬",
	"damage_type" : "����"
]),
([	"action" : "$N�������˫�Ƽ��ڣ��û�Ϊ���ơ����ơ�ʮ�ơ����ƣ�һʽ��������˪������$nȫ��",
	"damage" : 150,
	"parry"  : -5,
	"force"  : 130,
	"lvl"  : 90,
	"dodge"  : -20,
	"skill_name" : "������˪",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "strike") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="tiexian-quan"; }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("jiuqu-xinfa", 1) < 20)
		return notify_fail("��ľ����ķ���򲻹���\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ϰ�����Ʋ��ܳ����κ�����\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("����������㣬�����������ơ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ������ƣ�ͣ��޷���ϰ�����ơ�\n");
	me->add("neili", -5);
	me->add("jingli",-30);
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("feixu-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
	return __DIR__"feixu-zhang/" + action;
}