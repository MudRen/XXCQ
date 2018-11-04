// zui-gun.c -�������
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action":"�����ɺͣ�����Ȱ�������ʡ���$N����$w���ᣬ��������$n��$l",    
    "force" : 180,
    "dodge" : 0,
    "parry" : 5,
    "damage": 10,
    "lvl" : 10,
    "skill_name" : "���ɺͣ�����Ȱ��������",
    "damage_type":"����"
]),
([      "action":"�����ɹã������������ɲ�����$N���ƻ��أ��ұ�Ю���͵�ɨ��$n������",
    "force" : 200,
    "dodge" : 5,
    "parry" : 10,
    "damage": 15,
    "lvl" : 20,
    "skill_name" : "���ɹã������������ɲ�",
    "damage_type":"����"
]),
([      "action":"���ܹ��ˣ�ǧ���������ѡ���$N����$w��ָ���أ���$n��$l��ȥ",
    "force" : 230,
    "dodge" : 5,
    "parry" : 5,
    "damage": 20,
    "lvl" : 30,
    "skill_name" : "�ܹ��ˣ�ǧ����������",
    "damage_type":"����"
]),
([      "action":"�������ӣ������������������$N����$w�����˻��˸���Ȧ������$n��$l",
    "force" : 270,
    "dodge" : 5,
    "parry" : 5,
    "damage": 25,
    "lvl" : 40,
    "skill_name" : "�����ӣ��������������",
    "damage_type":"����"
]),
([      "action":"�������룬������������������$N���й������ţ�����������$n",  
    "force" : 320,
    "dodge" : 10,
    "parry" : 15,
    "damage": 30,
    "lvl" : 50,
    "skill_name" : "�����룬��������������",
    "damage_type":"����"
]),
([      "action":"��������ߵ���ɽ����ء���$N����֧�أ�һ��һ���������$n��$l",
    "force" : 380,
    "dodge" : 5,
    "parry" : 15,
    "damage": 35,
    "lvl" : 55,
    "skill_name" : "������ߵ���ɽ�����",
    "damage_type":"����"
]),
([      "action":"���Ź��ϣ�����ױ�����¿����$NŤ������$w�ӿ�����������$n���ؿ�",
    "force" : 450,
    "dodge" : 5,
    "parry" : 20,
    "damage": 40,
    "lvl" : 60,
    "skill_name" : "�Ź��ϣ�����ױ�����¿",
    "damage_type":"����"
]),
([      "action":"�������������������ǧ������$N�ڿն�����ɽ��Ӱ������ѹ��$n",
    "force" : 530,
    "dodge" : 10,
    "parry" : 25,
    "damage": 50,
    "lvl" : 64,
    "skill_name" : "�����������������ǧ��",
    "damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "club") || (usage == "parry");
 }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("banruo-changong", 1) < 20 && (int)me->query_skill("wuxiang-shengong", 1) < 20)
       return notify_fail("����ڹ���򲻹����޷�ѧ���������\n");
    if ((int)me->query_con() < 25)
	return notify_fail("��ĸ��ǲ��ʺ�ѧϰ�����\n");
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
    level   = (int) me->query_skill("zui-gun",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("����������������������\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zui-gun/" + action;
}

