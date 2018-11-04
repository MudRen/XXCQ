// ����ָ
// bye jfeng ����
inherit SKILL;
mapping *action = ({
([      "action" : "$N��ָ�ӳ���һʽ��ǧ��һ����������$n����Ե",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "ǧ��һ��",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��֮������һָ��һʽ��ʮ��𼱡���ָ��$n����ǰ",
        "force" : 140,
        "dodge" : 30,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "ʮ���",
        "damage_type" : "����"
]),
([      "action" : "$N�����������Ѩ������һʽ�����绽�꡹����$n��$l����",
        "force" : 180,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "���绽��",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀŭ�ӣ�һʽ����ɽ��������˫ָ����$n�Ķ�����硢�ۡ���
����",
        "force" : 220,
        "dodge" : 5,
        "damage": 85,
        "lvl" : 45,
        "skill_name" : "��ɽ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��Цָ���ա��������������⣬��ָ���Ƶ���$n��$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 130,
        "lvl" : 60,
        "skill_name" : "Цָ����",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ų�������������һʽ���������䡹����$n��ȫ��",
        "force" : 400,
        "dodge" : 100,
        "damage": 200,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="zhuifeng-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ָ������֡�\n");
//        if ((int)me->query_skill("zhixin", 1) < 50)
//                return notify_fail("����¹�֪�»�򲻹�����\n");
        if ((int)me->query("max_neili") < 400)
                return notify_fail("�������̫�����޷�������ָ��\n");
        return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("leiting-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("��ľ�̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�����������������ָ��\n");
        me->receive_damage("jing", 30);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
    return __DIR__"leiting-zhi/" + action;
}
