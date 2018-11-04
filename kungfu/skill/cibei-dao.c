// cibei-dao.c �ȱ���
// Modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([  "action" : "$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ",
    "force" : 120,
    "dodge" : -10,
    "lvl" : 0,
    "skill_name" : "ͣ����·",
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
    "force" : 130,
    "dodge" : -10,
    "damage" : 5,
    "lvl" : 8,
    "skill_name" : "ͯ�ӹһ�",
    "damage_type" : "����"
]),
([  "action" : "$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
    "force" : 140,
    "dodge" : -5,
    "damage" : 15,
    "lvl" : 16,
    "skill_name" : "�ƴ�����",
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
    "force" : 160,
    "dodge" : 5,
    "damage" : 25,
    "lvl" : 24,
    "skill_name" : "���ż�ɽ",
    "damage_type" : "����"
]),
([  "action" : "$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�",
    "force" : 180,
    "dodge" : 10,
    "damage" : 30,
    "lvl" : 33,
    "skill_name" : "��Ϫ����",
    "damage_type" : "����"
]),
([  "action" : "$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n",
    "force" : 210,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 42,
    "skill_name" : "�Ź�����",
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
    "force" : 240,
    "dodge" : 5,
    "damage" : 50,
    "lvl" : 51,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
    "force" : 280,
    "dodge" : 20,
    "damage" : 60,
    "lvl" : 60,
    "skill_name" : "ͣ����·",
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

int valid_combine(string combo) { return combo=="fumo-jian"; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
      return notify_fail("�������������\n");
    if ((int)me->query_skill("banruo-changong", 1) < 20)
      return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
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
    level   = (int) me->query_skill("cibei-dao",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
      return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
      return notify_fail("��������������ȱ�����\n");
    me->receive_damage("qi", 25);
    return 1;
}

