// xiuluo-dao.c ���޵�
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action" : "$N�ص����գ�һ�С�������ӥ�����������¶��ϻ��˸��뻡����$n��$l��ȥ",
    "force" : 120,
    "dodge" : -10,
    "parry" : 5,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : "������ӥ",
    "damage_type" : "����"
]),
([      "action" : "$N�����������⣬һ�С�Ͷ�������������$w��ֱ����$n��$l",    
    "force" : 130,
    "dodge" : -10,
    "parry" : 10,
    "damage": 20,
    "lvl" : 12,
    "skill_name" : "Ͷ�����",
    "damage_type" : "����"
]),
([      "action" : "$Nһ�С��ͷл�졹��$w�ƾ�������ˢ��һ�����϶�����$n����",  
    "force" : 140,
    "dodge" : -5,
    "parry" : 5,
    "damage": 25,
    "lvl" : 18,
    "skill_name" : "�ͷл��",
    "damage_type" : "����"
]),
([      "action" : "$N���ַ�ִ������һ�С��۹ǳ��衹����һ����$wֱ��$n�ľ���նȥ",
    "force" : 160,
    "dodge" : 5,
    "parry" : 5,
    "damage": 30,
    "lvl" : 24,
    "skill_name" : "�۹ǳ���",
    "damage_type" : "����",
]),
([      "action" : "$Nһ�С�����ǧ�ơ����������⻯����㷱�ǣ���$n��$l��ȥ",    
    "force" : 180,
    "dodge" : 10,
    "parry" : 5,
    "damage": 35,
    "lvl" : 30,
    "skill_name" : "����ǧ��",
    "damage_type" : "����"
]),
([      "action" : "$N˫�ֺ�ִ$w��һ�С����۲�ʩ����š��ת������ֱ����$n��˫��
",
    "force" : 210,
    "dodge" : 15,
    "parry" : 15,
    "damage": 40,
    "lvl" : 36,
    "skill_name" : "���۲�ʩ",
    "damage_type" : "����"
]),
([      "action" : "$Nһ�С���Ƥ�龭��������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",  
    "force" : 240,
    "dodge" : 15,
    "parry" : 15,
    "damage": 50,
    "lvl" : 42,
    "skill_name" : "��Ƥ�龭",
    "damage_type" : "����"
]),
([      "action" : "$N��ת�����׼�Լ���һ�С����ľ�־����ȫ��һ��������$w��$n����նȥ",
    "force" : 280,
    "dodge" : 20,
    "parry" : 10,
    "damage": 60,
    "lvl" : 48,
    "skill_name" : "���ľ�־",
    "damage_type" : "����"
]),
([      "action" : "$Nһ�С������𡹣�$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��",
    "force" : 320,
    "dodge" : 10,
    "parry" : 20,
    "damage": 75,
    "lvl" : 54,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([      "action" : "$N����ƽָ��һ�С���Ѫ���ء���һƬƬ�йǵ�����쫷�����$n��ȫ��",
    "force" : 370,
    "dodge" : 5,
    "parry" : 25,
    "damage": 90,
    "lvl" : 60,
    "skill_name" : "��Ѫ����",
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

int valid_combine(string combo) { return combo=="damo-jian"; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 50)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("banruo-changong", 1) < 10)
   return notify_fail("��İ����������̫ǳ��\n");
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
    level   = (int) me->query_skill("xiuluo-dao",1);
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
   return notify_fail("����������������޵���\n");
    me->receive_damage("qi", 35);
    return 1;
}

