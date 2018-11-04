// huanhua-jian.c 佻�����
// ƽ��damage:100 ƽ��force:100 ƽ��dodge:-5 ƽ��parry:-5
// ����ȭ���ص���������һ�㣬���мܺͶ�ܾ�����
// By Load

inherit SKILL;

mapping *action = ({
([	"action" : "$N����һ��һʽ��÷����Ū��������$w����ʵʵ��������÷����ͻ�ĺ�Ϊһ��������$n��",
    "damage" : 50,
	"parry"  : -10,
	"force"  : 30,
	"lvl"  : 0,
	"dodge"  : -10,
	"skill_name" : "÷����Ū",
	"damage_type" : "����"
]),
([	"action" : "$N�������죬����һʽ�������Ƕ���������������ǹ⣬ֱ��$n�����޴Ӷ���",
      "damage" : 100,
	"parry"  : -15,
	"force"  : 40,
	"lvl"  : 10,
	"dodge"  : -10,
	"skill_name" : "�����Ƕ�",
	"damage_type" : "����"
]),
([	"action" : "$N��ʽһ����һʽ���ޱ���ľ����$w������֮�����϶���б������������$n��$l��",
      "damage" :120,
	"parry"  : 10,
	"force"  : 50,
	"lvl"  : 20,
	"dodge"  : 5,
	"skill_name" : "�ޱ���ľ",
	"damage_type" : "����"
]),
([	"action" : "$N����$w����б������$n�����Ҳ࣬Ȼ��ͻȻ�۽�$n��һʽ���ƻ�����$w��$n���̹�ȥ��",
      "damage" : 150,
	"parry"  : -15,
	"force"  : 60,
	"lvl"  : 30,
	"dodge"  : -5,
	"skill_name" : "�ƻ�����",
	"damage_type" : "����"
]),
([	"action" : "$N����������һʽ��������ƾ����$w������ң���Ȼ������Ʈ��֮��ֱ��$n��$l��ȥ��",
      "damage" : 180,
	"parry"  : -10,
	"force"  : 70,
	"lvl"  : 40,
	"dodge"  : -5,
	"skill_name" : "������ƾ",
	"damage_type" : "����"
]),
([	"action" : "$N̤��һ��������$w��һ���������������һʽ��������ա�������֮������$n��",
      "damage" : 200,
	"parry"  : 0,
	"force"  : 85,
	"lvl"  : 50,
	"dodge"  : 10,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N����$w���롱Ȼ���֣��������࣬����ʳ�����һʽ��������֮������������ΰ���н����ˡ�",
      "damage" : 220,
	"parry"  : 10,
	"force"  : 95,
	"lvl"  : 60,
	"dodge"  : -10,
	"skill_name" : "��ʳ���",
	"damage_type" : "����"
]),
([	"action" : "$N���μ�����Ծ����գ�ʹ��������ֱ�¡�һʽ�����˴�����������$n��",
     "damage" : 250,
	"parry"  : 10,
	"force"  : 110,
	"lvl"  : 70,
	"dodge"  : 0,
	"skill_name" : "����ֱ��",
	"damage_type" : "����"
]),
([	"action" : "$N�������ߣ�������Զ��һʽ���·�ԶӰ����һ��$w��ǰ�����Ҳ��ϴ���$n��$l��",
      "damage" : 280,
	"parry"  : -20,
	"force"  : 120,
	"lvl"  : 80,
	"dodge"  : -10,
	"skill_name" : "�·�ԶӰ",
	"damage_type" : "����"
]),
([	"action" : "$N��һ��أ��������һʽ���������ӡ���$w���϶��´���һ����ãã�Ľ���������$n��",
      "damage" : 300,
	"parry"  : 10,
	"force"  : 130,
	"lvl"  : 90,
	"dodge"  : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N�������顢�������Σ�һʽ��������Ӱ���������ıƽ�$n���������ͻȻ��������$n��$l������ȥ��",
      "damage" : 320,
	"parry"  : -10,
	"force"  : 140,
	"lvl"  : 100,
	"dodge"  : -10,
	"skill_name" : "������Ӱ",
	"damage_type" : "����"
]),
([	"action" : "$N����$n�Ĺ��ƣ���ǰ���壬����$w���������ǹ⡹����$n��ȫ������һƬ����֮�С�",
      "damage" : 350,
	"parry"  : -20,
	"force"  : 150,
	"lvl"  : 110,
	"dodge"  : -15,
	"skill_name" : "����ǹ�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

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

	if (!objectp(weapon = me->query_temp("weapon"))	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("û�н���ô��ϰ佻�������\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��̫���ˣ�����Ъһ�������ɡ���\n");
	me->add("jingli",-30);
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("huanhua-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
	return __DIR__"huanhua-jian/" + action;
}
