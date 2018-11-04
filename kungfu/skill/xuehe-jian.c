
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$Nһ�С�Ѫ�ӵ�к��������Ծ������$w��ӣ�ն��$n��",
    "force" : 200,
    "damage" : 100,
    "dodge"  : 10,
    "lvl"   : 0,
    "skill_name" : "Ѫ�ӵ�к",
    "damage_type" : "����"
]),
([  "action" : "$N����$w�����������Σ���С�Ѫ���񽣡�����$n���ұ����ն�䡣",
    "force" : 300,
    "damage" : 200,
    "dodge" : 35,
    "force" : 20,
    "lvl"   : 50,
    "skill_name" : "Ѫ����",
    "damage_type" : "����"
]),
([  "action" : "$N����һ����ˢˢˢˢ�Ľ�����$n�أ������������Ĵ����̣���һ�С�Ѫ��׷ɡ���",
    "force" : 400,
    "damage" : 300,
    "dodge" : 25,
    "force" : 25,
    "lvl"   : 100,
    "skill_name" : "Ѫ��׷�",
    "damage_type" : "����"
]),
([  "action" : "$N����һ����Х��Ѫ�������б����ǰ��$w����ֱ����Ѹ���ޱȣ�����$n��$l",
    "force" : 500,
    "damage" : 400,
    "dodge" : 80,
    "force" : 200,
    "lvl"   : 150,
    "skill_name" : "Ѫ������",
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 

int valid_learn(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
    if ((int)me->query("max_neili") < 300)
        return notify_fail("�������������\n");
/*
    if ((int)me->query("yiqiguan-riyue") < 1)
        return notify_fail("���һ�������»��̫ǳ,��û�ﵽ�������������ľ��硣\n");
*/
    if ((int)me->query_skill("sword", 1) < 50)
        return notify_fail("��Ľ������̫ǳ��\n");
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
    level   = (int) me->query_skill("xuehe-jian",1);
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
        return notify_fail("�������������Ѫ�ӽ�����\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"xuehe-jian/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        
        if( damage_bonus < 100 ) return 0;
        if (!(me->query("yiqiguan-riyue"))) return 0;
        if( random(damage_bonus/2) > victim->query_str() ) {        
        if (me->query("yiqiguan-riyue")==1) {
        victim->receive_wound("qi", (damage_bonus - 100) / 2 );
        msg= WHT "$nһ���������������м��ӵġ������������ھ����ˡ�\n" NOR;
        }
        if (me->query("yiqiguan-riyue")==2) {
        victim->receive_wound("qi",damage_bonus/2 );
        msg= CYN "$nһ���������������м��ӵġ��Ƿ��켫���ھ����ˡ�\n" NOR;
        }
        return msg;
        }
}

