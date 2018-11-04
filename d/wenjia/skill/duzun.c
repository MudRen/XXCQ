// SKILL: duzun.c Ω�Ҷ��� 
// Created by Zeus 1999.5.1
// Modified by Zeus 1999.6.8
// ����perform Ω�Ҷ���
// ԭ���书�����ˣ��ޡ��Դ����������
 
inherit SKILL;

mapping *action = ({
([      "action" : "$N���ֻ��أ����ֱ��ƣ�����һ�С�Ω�Ҷ���",
        "damage" : 15,
        "parry"  : -10,
        "force"  : 15,
        "lvl"  : 0,
        "dodge"  : -10,
        "skill_name" : "Ω�Ҷ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��򶾻��项��˫�������ĳ�һ�����",
        "damage" : 20,
        "parry"  : -15,
        "force"  : 25,
        "lvl"  : 15,
        "dodge"  : -15,
        "skill_name" : "�򶾻���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������䡹�����������ĳ�һ�����������ָָ����Ʈ��һ������",
        "damage" : 25,
        "parry"  : -20,
        "force"  : 35,
        "lvl"  : 30,
        "dodge"  : -20,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N˫��ƽ��ָ����$n��ǰ������ָ�Σ�����ָ�ģ�һ�С����Ķ��Ρ�",
        "damage" : 35,
        "parry"  : -25,
        "force"  : 45,
        "lvl"  : 45,
        "dodge"  : -25,
        "skill_name" : "���Ķ���",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֻط�������������һ�С��������ˡ����������һ������",
	"damage" : 45,
        "parry"  : -30,
        "force"  : 55,
        "lvl"  : 60,
        "dodge"  : -30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N������ָ�ſ�������һ��������������ָ��һ�ų�������һ�С�����ҹ����",
        "damage" : 55,
        "parry"  : -35,
        "force"  : 60,
        "lvl"  : 75,
        "dodge"  : -35,
        "skill_name" : "����ҹ��",
        "damage_type" : "����"
]),
([      "action" : "$N���α�죬������������ָ����ʱ��Χ������������һ�С������඾��",
        "damage" : 65,
        "parry"  : -40,
        "force"  : 65,
        "lvl"  : 90,
        "dodge"  : -40,
        "skill_name" : "�����඾",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��������һ�桹������˳��˫����ָ����$n����ǰ�����һ�㶾��",
        "damage" : 75,
        "parry"  : -45,
        "force"  : 75,
        "lvl"  : 105,
        "dodge"  : -45,
        "skill_name" : "����һ��",
        "damage_type" : "����"
]),
([      "action" : "$N���ִ���ǰһ��������һ�Ŷ��أ���$n��ȥ��һ�С�����һ�ġ�",
        "damage" : 80,
        "parry"  : -50,
        "force"  : 85,
        "lvl"  : 120,
        "dodge"  : -50,
        "skill_name" : "����һ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��������꡹�����ƾ�Ȼ������â����â����$n����",
        "damage" : 90,
        "parry"  : -55,
        "force"  : 95,
        "lvl"  : 135,
        "dodge"  : -55,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N��������һ��Сľ����������ľ����һ����������$n��ȥ������һ�С�����ר�С�",
        "damage" : 100,
        "parry"  : -65,
        "force"  : 90,
        "lvl"  : 150,
        "dodge"  : -65,
        "skill_name" : "����ר��",
        "damage_type" : "����"
]),
([      "action" : "$N˫���鱧ԲȦ��ͻȻ˫����$n���Ŀ�ָȥ������һ�С����߽��ġ�",
        "damage" : 130,
        "parry"  : -80,
        "force"  : 100,
        "lvl"  : 175,
        "dodge"  : -80,
        "skill_name" : "���߽���",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֲ����ų���������һ�С������Ĳá���������$n�����ѹ�ȥ",
        "damage" : 150,
        "parry"  : -100,
        "force"  : 130,
        "lvl"  : 200,
        "dodge"  : -100,
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
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("��Ω�Ҷ�����Ҫ����������!\n");
        if ((int)me->query_skill("lphand", 1) < 100)
                return notify_fail("��Ω�Ҷ�����Ҫ�������ġ�ʩ���ַ���!\n");
        if ((int)me->query_skill("zhixin", 1) < 100)
                return notify_fail("��Ω�Ҷ�����Ҫ�������ڹ�!\n");
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
                return notify_fail("��Ω�Ҷ������á�ʩ���ַ����Ŷ��ģ������������Ŷ���!\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("��ƣ�͵�ʱ����ϰ��Ω�Ҷ�����û���õ�!\n");
        me->add("qi",-40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"duzun/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("duzun_poison", random(me->query_skill("duzun",1)/10) + 1 + victim->query_condition("duzun_poison"));
}
