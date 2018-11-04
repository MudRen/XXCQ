// feiyu-jian.c ���㽣��
// Created by Atlus 1999.7.23.
//


inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�У���ɽ�����ݣ�����$w�����������$n��$l��������",
//	"parry_action" : "",
	"damage" : 20,
	"parry"  : 0,
	"force"  : 30,
	"lvl"  : 0,
	"dodge"  : -5,
	"skill_name" : "��ɽ����",
	"damage_type" : "����"
]),
([	"action" : "$N��һ����һ�У��ﾡľ������е�$w�ó�һƬ������������е���Ҷһ��ɢ��$n��$l��",
//	"parry_action" : "",
	"damage" : 30,
	"parry"  : -5,
	"force"  : 30,
	"lvl"  : 15,
	"dodge"  : -5,
	"skill_name" : "�ﾡľ��",
	"damage_type" : "����"
]),
([	"action" : "$N��Ӱ�ζ������淢��һ���⣬һ�У۶������£ݣ����е�$w������·ͻȻ����$n��$l",
//	"parry_action" : "",
	"damage" : 50,
	"parry"  : 10,
	"force"  : 60,
	"lvl"  : 25,
	"dodge"  : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N�趯$w������һת��һ�У����˴����Ю����������ֱֱ����$n��$l",
//	"parry_action" : "",
	"damage" : 50,
	"parry"  : -20,
	"force"  : 30,
	"lvl"  : 35,
	"dodge"  : -20,
	"skill_name" : "���˴���",
	"damage_type" : "����"
]),
([	"action" : "$N����$wѸ�ٳ����˲Ϣ�������������佣������$n��ȥ������һ�У��α�������",
//	"parry_action" : "",
	"damage" : 65,
	"parry"  : -15,
	"force"  : 50,
	"lvl"  : 50,
	"dodge"  : -15,
	"skill_name" : "�α�����",
        "damage_type" : "����"
]),
([	"action" : "$N����Ծ������$w����ͻ�̣�һ�С��������������մ���$n��$l",
//	"parry_action" : "",
	"damage" : 70,
	"parry"  : 0,
	"force"  : 70,
	"lvl"  : 60,
	"dodge"  : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N���ΰεض�������$wһ�񣬽�������ӿ����һ�С�����Ư�졹����$n��$l",
//	"parry_action" : "",
	"damage" : 85,
	"parry"  : 0,
	"force"  : 90,
	"lvl"  : 70,
	"dodge"  : -10,
	"skill_name" : "����Ư��",
	"damage_type" : "����"
]),
([	"action" : "$N����$w���ǻ���һƬ���⣬ͻȻһ��[��ˮ����]��ֱ��$n��$l��������",
//	"parry_action" : "",
	"damage" : 120,
	"parry"  : -20,
	"force"  : 120,
	"lvl"  : 85,
	"dodge"  : -10,
	"skill_name" : "��ˮ����",
	"damage_type" : "����"
]),
([	"action" : "$NͻȻ̧ͷ���죬�ƺ���ȫ����$n�Ĺ��ƣ�����$wȴ�����̳���ÿ����ֱָ$n������������[�������]",
//	"parry_action" : "",
	"damage" : 180,
	"parry"  : -20,
	"force"  : 140,
	"lvl"  : 120,
	"dodge"  : -15,
	"skill_name" : "�������",
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
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ�̫���ˡ�\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("û�н���ô��ϰ���㽣����\n");
	
	if ((int)me->query("jingli") < 50)
		return notify_fail("�㾫��״̬̫���ˣ�����Ъһ�������ɡ���\n");
	me->add("jingli",-25);
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("feiyu-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
	return __DIR__"feiyu-jian/" + action;
}
