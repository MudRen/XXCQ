// xueying-zhang.c
// by mulan

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : RED"$N ʹ��ѪӰ�Ƶģ�Ѫ����Ӱ�ݣ���Ȼ�䣬һƬ���⣬һ��ѪӰ������ֱ��$n��"NOR,
        "force" : 100,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "Ѫ����Ӱ"
]),
([      "action" : RED"$N ʹ��ѪӰ�Ƶģ�Ѫ�������ݣ����ϵĽ�����ļ���������������$n�����ߣ�$N��һ˫��ѪӰ�֡����Ѵ���$n��"NOR,
        "force" : 120,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl" : 20,
        "skill_name" : "Ѫ������"
]),
([      "action" : RED"$N ����֪��$n���У���ʱ�ƿ�˫�֣�ȴ��������ѪӰ�ݣ���$n��ȥ��"NOR,
        "force" : 140,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "����ѪӰ"
]),
([      "action" : RED"$N ���ҿ�����ʹ��ѪӰ�Ƶģ�Ӱ�����Уݣ�Ѹ����ȣ���Ǻ��н����мܲ�����    ѪӰ��ʦ��ָ���죬ʮָ��ꪣ����Ҽ���$n��"NOR,
        "force" : 160,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "Ӱ������"
]),
([      "action" : RED"$N���ֻ������ĳ��죬���д��죬ֱ��$n,һ�У�ѪӰ�ȷ��ʹ�˳���! "NOR,
        "force" : 200,
        "dodge" : 20,
        "damage_type" : "����",
        "lvl" : 20,
        "skill_name" : "ѪӰ�ȷ�"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; } 

int valid_combine(string combo) { return combo=="huoyan-dao"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��ѪӰ�Ʊ�����֡�\n");
    if (me->query("shen") > 0 )
    	return notify_fail("�㲻����а���书���ϡ� \n");
    if ((int)me->query_skill("strike",1) < 100)
        return notify_fail("��Ļ����Ʒ���򲻹���\n");
    if ((int)me->query("max_neili") < 500)
        return notify_fail("�������̫����\n");
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
    level = (int)me->query_skill("xueying-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 50)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 50)
       return notify_fail("�������������\n");
    me->receive_damage("qi", 50);
    me->add("neili", -2);
    return 1;
}


