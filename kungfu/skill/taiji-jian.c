// taiji-jian.c ̫����
// cleansword 2/15/96
// Marz 5/21/96

inherit SKILL;

mapping *action = ({
([	"action" : "$N�鲽������һ�С����ѵ�ˮ��������$w���������һ��������$n��$l",
	"force" : 60,
	"dodge" : 20,
	"parry" : 10,
	"damage" : 45,
        "lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ����һ�������ֽ���������$wʹ��һʽ��ָ���롹ֱ��$n��$l",
	"force" : 70,
	"dodge" : 15,
	"parry" : 10,
	"damage" : 50,
        "lvl" : 4,
	"damage_type" : "����"
]),
([	"action" : "$N��������һ�죬���ֽ���������$wʹ��һʽ������ǡ�����$n��$l",
	"force" : 80,
	"dodge" : 15,
	"parry" : 10,
	"damage" : 50,
        "lvl" : 9,
	"damage_type" : "����"
]),
([	"action" : "$N˫ϥ�³�������$wʹ��һʽ��̽��ʽ�������¶��ϼ���$n��$l",
	"force" : 90,
	"dodge" : 15,
	"parry" : 10,
	"damage" : 50,
        "lvl" : 14,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������Ӳ�����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 100,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 60,
        "lvl" : 19,
	"damage_type" : "����"
]),
([	"action" : "$N���������һš��һ�С�������β��������$w������$n��$l��ȥ",
	"force" : 110,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 70,
        "lvl" : 24,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$n��$l",
	"force" : 120,
	"dodge" : 10,
	"parry" : 15,
	"damage" : 70,
        "lvl" : 29,
	"damage_type" : "����"
]),
([	"action" : "$N������ϥ������$wбָ��һ�С�����Ͷ�֡�����$n��$l",
	"force" : 130,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 70,
        "lvl" : 34,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�������ˮ����$w���¶��ϻ���һ���󻡣�ƽƽ�ػ���$n��$l",
	"force" : 140,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 71,
        "lvl" : 39,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ�����������¡���$w��������ԲȦ������ֱ�������಻�ϻ���$n��$l",
	"force" : 150,
	"dodge" : 10,
	"parry" : 20,
	"damage" : 73,
        "lvl" : 44,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����Ҷ����$w����ػ�������Բ����Ѹ�ٵ���$n��$l��ȥ",
	"force" : 160,
	"dodge" : 15,
	"parry" : 20,
	"damage" : 75,
        "lvl" : 49,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����ͷ����$w����һ������ҸߵĴ󻡣�бб��ն��$n��$l",
	"force" : 170,
	"dodge" : 15,
	"parry" : 20,
	"damage" : 77,
        "lvl" : 54,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ����ʨ��ҡͷ����$w�������󻮳�һ�����֣���$nȦ������",
	"force" : 180,
	"dodge" : 15,
	"parry" : 20,
	"damage" : 79,
        "lvl" : 59,
	"damage_type" : "����"
]),
([	"action" : "$N���̤ʵ���ҽ���㣬һ�С�����ָ·��������$w����һ�Ž���������$n��$l",
	"force" : 190,
	"dodge" : 5,
	"parry" : 20,
	"damage" : 81,
        "lvl" : 64,
	"damage_type" : "����"
]),
([	"action" : "$N����Ծ��һ�С�Ұ����������$w�ڰ���л�ΪһȦ��â������$n��$l",
	"force" : 200,
	"dodge" : 15,
	"parry" : 20,
	"damage" : 83,
        "lvl" : 69,
	"damage_type" : "����"
]),
([	"action" : "$N����ǰ���󹭣�һ�С�����ʽ��������$wֱ��$n��$l",
	"force" : 210,
	"dodge" : 20,
	"parry" : 20,
	"damage" : 85,
        "lvl" : 74,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�С���ǡ�����������һ�죬���ֽ���������$wƽƽ����$n��$l��ȥ",
	"force" : 220,
	"dodge" : 40,
	"parry" : 20,
	"damage" : 87,
        "lvl" : 79,
	"damage_type" : "����"
]),
([	"action" : "$N������ϣ�һ�С���Գ�׹���������$wбб����$n��$l��ȥ",
	"force" : 230,
	"dodge" : 30,
	"parry" : 20,
	"damage" : 89,
        "lvl" : 84,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ӭ�絧������$w���������һ�ӣ�$nȴ����һ�ɾ���ӭ��Ϯ����",
	"force" : 240,
	"dodge" : 20,
	"parry" : 25,
	"damage" : 91,
        "lvl" : 89,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�˳ˮ���ۡ���$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ��",
	"force" : 250,
	"dodge" : 45,
	"parry" : 25,
	"damage" : 93,
        "lvl" : 94,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����Ǹ��¡���$w����$n��$l",
	"force" : 260,
	"dodge" : 35,
	"parry" : 25,
	"damage" : 95,
        "lvl" : 99,
	"damage_type" : "����"
]),
([	"action" : "$NͻȻ�̶���������һ�С��������¡���$w���¶��ϵ���$n��$l��ȥ",
	"force" : 270,
	"dodge" : 25,
	"parry" : 25,
	"damage" : 97,
        "lvl" : 104,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����ʽ����$w���¶������컮��һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 280,
	"dodge" : 35,
	"parry" : 25,
	"damage" : 99,
        "lvl" : 109,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��Ʒ��붴����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"force" : 290,
	"dodge" : 40,
	"parry" : 25,
	"damage" : 102,
        "lvl" : 114,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����չ�᡹������Ծ������$w����$n��$l",
	"force" : 300,
	"dodge" : 45,
	"parry" : 25,
	"damage" : 106,
        "lvl" : 119,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����ֽ�����$w����һƬ���̣�ƽƽ����$n��$l��ȥ",
	"force" : 310,
	"dodge" : 45,
	"parry" : 25,
	"damage" : 120,
        "lvl" : 124,
	"damage_type" : "����"
]),
([	"action" : "$N��������棬������ǰһ�ˣ�һ�С������пա���$w��$n��$l��ȥ",
	"force" : 320,
	"dodge" : 45,
	"parry" : 30,
	"damage" : 125,
        "lvl" : 129,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���ɨ÷����������Ծ�ڰ�գ�����$wɨ��$n��$l",
	"force" : 330,
	"dodge" : 45,
	"parry" : 30,
	"damage" : 130,
        "lvl" : 90,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ȴ���齣�������Ծ����أ�$w�س飬���ֹ���$n��$l",
	"force" : 340,
	"dodge" : 35,
	"parry" : 30,
	"damage" : 140,
        "lvl" : 139,
	"damage_type" : "����"
]),
([	"action" : "$N���Ȱ�����ף�һ�С�����Ʊա���������ָ��ת������$n��$l",
	"force" : 350,
	"dodge" : 25,
	"parry" : 30,
	"damage" : 150,
        "lvl" : 144,
	"damage_type" : "����"
]),
([  "action" : "$N����š���������鱧��һ�С�����հ�ա���$w�й�ֱ��������$n��$l",
	"force" : 380,
	"dodge" : 35,
	"parry" : 30,
	"damage" : 160,
        "lvl" : 149,
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫���񹦻��̫ǳ��\n");
	if ((int)me->query_skill("taiji-quan", 1) < 20)
		return notify_fail("���̫��ȭ���̫ǳ��\n");
	return 1;
}

mapping query_action(object me,object)
{
	int i, level;
	level   = (int) me->query_skill("taiji-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������������̫��������\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}
