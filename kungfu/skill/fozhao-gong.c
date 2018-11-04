// fozhao-gong.c ��շ�צ��
// modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([      "action" : "�ں��������У�$Nʹһ�С�٤�����硹��˫���繳��ꫣ�����$n��$l",
    "force" : 100,
    "dodge" : 5,
    "lvl"   : 0,
    "skill_name" : "٤������" ,
    "damage_type" : "����"
]),
([      "action" : "$N�͵���ǰԾ����һ�С�����׽Ӱ���������߳���˫��ץ��$n������",
    "force" : 110,
    "dodge" : 5,
    "damage": 5,
    "lvl"   : 6,
    "skill_name" : "����׽Ӱ" ,
    "damage_type" : "����"
]),
([      "action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С����渧�١�����$n��$l",    
    "force" : 120,
    "dodge" : 10,
    "damage": 5,
    "lvl"   : 12,
    "skill_name" : "���渧��" ,
    "damage_type" : "����"
]),
([      "action" : "$N���������������ڻӣ�һ�С���ջ��ġ�������צ����$n�ؿ�",
    "force" : 140,
    "dodge" : 10,
    "damage": 10,
    "lvl"   : 18,
    "skill_name" : "��ջ���" ,
    "damage_type" : "����"
]),
([      "action" : "$N�������գ�����������ɽ��һ�С��޺����������͵ػ���$n��$l",  
    "force" : 160,
    "dodge" : 15,
    "damage": 10,
    "lvl"   : 24,
    "skill_name" : "�޺�����" ,
    "damage_type" : "����"
]),
([      "action" : "$N�ڲ���ǰ�����ֻ��أ�����̽����һ�С��������项����$n���ɲ�",
    "force" : 190,
    "dodge" : 15,
    "damage": 15,
    "lvl"   : 30,
    "skill_name" : "��������" ,
    "damage_type" : "����"
]),
([      "action" : "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ�С����б��С���������$n��$l",
    "force" : 220,
    "dodge" : 20,
    "damage": 15,
    "lvl"   : 35,
    "skill_name" : "���б���" ,
    "damage_type" : "����"
]),
([      "action" : "$N������ǰ������Ҹ�º��գ���ָ�繳��һ�С�������ȱ������$n�Ķ���",
    "force" : 260,
    "dodge" : 20,
    "damage": 20,
    "lvl"   : 40,
    "skill_name" : "������ȱ" ,
    "damage_type" : "����"
]),
([      "action" : "$N����б��$n����֮�䣬һ�С��������项������ȡĿ�����ַ���$n���ɲ�",
    "force" : 300,
    "dodge" : 25,
    "damage": 20,
    "lvl"   : 45,
    "skill_name" : "��������" ,
    "damage_type" : "����"
]),
([      "action" : "$Nһ����ָ$n�Ľ�����һ�С������ὣ����һ������ץ��$n���еı���",
    "force" : 350,
    "dodge" : 25,
    "damage": 25,
    "lvl"   : 50,
    "skill_name" : "�����ὣ" ,
    "damage_type" : "����"
]),
([      "action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С��������ơ�ʹ$n��������",
    "force" : 400,
    "dodge" : 30,
    "damage": 25,
    "lvl"   : 55,
    "skill_name" : "��������" ,
    "damage_type" : "����"
]),
([      "action" : "$Nǰ���ŵأ�һ�ֶ����צ��һ��ָ�أ�һ�С�����׷�ա���������$n��ȫ��",
    "force" : 460,
    "dodge" : 40,
    "damage": 30,
    "lvl"   : 60,
    "skill_name" : "����׷��" ,
    "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }     

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("����շ�צ��������֡�\n");
    if ((int)me->query_skill("banruo-changong", 1) < 20)
   return notify_fail("����ڹ���򲻹����޷�ѧ��շ�צ����\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷�����շ�צ����\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action); i > 0; i--)
   if(level >= action[i-1]["lvl"])
      return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("fozhao-gong",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("���������������շ�צ����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}

