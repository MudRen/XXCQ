// SKILL: duzun.c Ω�Ҷ��� �¼ҵ���������书
// Created by Zeus 1999.5.1
// Modified by Zeus 1999.5.7
// 
// 
inherit SKILL;

mapping *action = ({
([	"action" : "$N���ֻ��أ����ֱ��ƣ�����һ�С�����ͷ�ѡ�",
	"damage" : 5,
	"parry"  : -20,
	"force"  : 10,
	"lvl"  : 0,
	"dodge"  : 5,
	"skill_name" : "����ͷ��",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�С�����ɡ���˫�������ĳ�һ�����",
	"damage" : 10,
	"parry"  : -15,
	"force"  : 15,
	"lvl"  : 7,
	"dodge"  : 10,
	"skill_name" : "С������",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С����ж��������������ĳ�һ�����������ָָ����Ʈ��һ������",
	"damage" : 15,
	"parry"  : -10,
	"force"  : 20,
	"lvl"  : 14,
	"dodge"  : 15,
	"skill_name" : "���ж�",
        "damage_type" : "����"
]),
([	"action" : "$N˫��ƽ��ָ����$n��ǰ������ָ�Σ�����ָ�ģ�һ�С����Ķ��Ρ�",
	"damage" : 15,
	"parry"  : -10,
	"force"  : 20,
	"lvl"  : 21,
	"dodge"  : 15,
	"skill_name" : "���Ķ���",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֻط�������������һ�С��������ˡ����������һ������",
	"damage" : 20,
	"parry"  : -5,
	"force"  : 25,
	"lvl"  : 28,
	"dodge"  : 20,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N������ָ�ſ�������һ��������������ָ��һ�ų�������һ�С�����ҹ����",
	"damage" : 20,
	"parry"  : -5,
	"force"  : 25,
	"lvl"  : 35,
	"dodge"  : 20,
	"skill_name" : "����ҹ��",
        "damage_type" : "����"
]),
([	"action" : "$N���α�죬������������ָ����ʱ��Χ������������һ�С������඾��",
	"damage" : 25,
	"parry"  : 0,
	"force"  : 30,
	"lvl"  : 42,
	"dodge"  : 25,
	"skill_name" : "�����඾",
        "damage_type" : "����"
]),
([	"action" : "$Nʹ��������һ�桹������˳��˫����ָ����$n����ǰ�����һ�㶾��",
	"damage" : 35,
	"parry"  : 0,
	"force"  : 30,
	"lvl"  : 49,
	"dodge"  : 30,
	"skill_name" : "����һ��",
        "damage_type" : "����"
]),
([	"action" : "$N���ִ���ǰһ��������һ�Ŷ��أ���$n��ȥ��һ�С�����һ����",
	"damage" : 40,
	"parry"  : 10,
	"force"  : 35,
	"lvl"  : 56,
	"dodge"  : 35,
	"skill_name" : "����һ��",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С����������������ƾ�Ȼ������â����â����$n����",
	"damage" : 45,
	"parry"  : 15,
	"force"  : 40,
	"lvl"  : 63,
	"dodge"  : 40,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N��������һ��Сľ����������ľ����һ����������$n��ȥ������һ�С��������ġ�",
	"damage" : 50,
	"parry"  : 20,
	"force"  : 45,
	"lvl"  : 70,
	"dodge"  : 50,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N˫���鱧ԲȦ��ͻȻ˫����$n���Ŀ�ָȥ������һ�С����۽��ġ�",
	"damage" : 60,
	"parry"  : 30,
	"force"  : 55,
	"lvl"  : 77,
	"dodge"  : 60,
	"skill_name" : "���۽���",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֲ����ų���������һ�С������Ĳ𡹣�������$n�����ѹ�ȥ",
	"damage" : 70,
	"parry"  : 40,
	"force"  : 70,
	"lvl"  : 85,
	"dodge"  : 80,
	"skill_name" : "�����Ĳ�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "lphand"); }


string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("zhixin", 1) < 20)
                return notify_fail("��ġ��¹�֪�¡���򲻹���\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("duzun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��ϰ��Ω�Ҷ��𡹲��ܳ�������\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("��̫���ˣ�����Ъһ�������ɡ���\n");
	me->add("qi",-20);
        return 1;
}
