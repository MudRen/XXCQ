// weituo-gun.c Τ�ӹ�
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action":"$Nһ�С���ʯ���ġ�������$w�����ѵ�ˮ�㣬������$n������Ҫ����ȥ",
    "force" : 160,
    "dodge" : 5,
    "parry" : 5,
    "damage": 10,
    "lvl" : 0,
    "skill_name" : "��ʯ����",
    "damage_type":"����"
]),
([      "action":"$N��$wƽ���ؿڣ�һš��һ�С�����ͣ�桹��$w�͵�����$n�ľ���",
    "force" : 180,
    "dodge" : 5,
    "parry" : 10,
    "damage": 15,
    "lvl" : 8,
    "skill_name" : "����ͣ��",
    "damage_type":"����"
]),
([      "action":"$Nһ�С�ƽ�����ɡ���ȫ���������ڵ��ϴ����ת���ٹ���$n���ظ����ȥ",
    "force" : 210,
    "dodge" : 5,
    "parry" : 15,
    "damage": 20,
    "lvl" : 16,
    "skill_name" : "ƽ������",
    "damage_type":"����"
]),
([      "action":"$N����һ��������һ�С��������硹��$wЮ��������Ѹ��ɨ��$n������",
    "force" : 250,
    "dodge" : 15,
    "parry" : 5,
    "damage": 25,
    "lvl" : 25,
    "skill_name" : "��������",
    "damage_type":"����"
]),
([      "action":"$Nһ�С����Ǹ��¡��������һ�����˱Ƴ�һ��ֱ�ߣ����ǰ�����$n��$l",
    "force" : 300,
    "dodge" : 20,
    "parry" : 15,
    "damage": 30,
    "lvl" : 35,
    "skill_name" : "���Ǹ���",
    "damage_type":"����"
]),
([      "action":"$N˫�ֳֹ����˸���ش�Ȧ��һ�С���ϼ���ա���һ����Բ�����л�����ײ��$n���ؿ�",
    "force" : 350,
    "dodge" : 20,
    "parry" : 15,
    "damage": 35,
    "lvl" : 44,
    "skill_name" : "��ϼ����",
    "damage_type":"����"
]),
([      "action":"$Nһ�С�Ͷ�޶�������$w�߾٣����������֮�ƶ�׼$n�����鵱ͷ����",
    "force" : 410,
    "dodge" : 25,
    "parry" : 20,
    "damage": 40,
    "lvl" : 52,
    "skill_name" : "Ͷ�޶���",
    "damage_type":"����"
]),
([      "action":"$NǱ��������һ�С������麣����$w��ʱ�������ɣ�������ֱ��$n���ؿ�",
    "force" : 470,
    "dodge" : 30,
    "parry" : 25,
    "damage": 50,
    "lvl" : 60,
    "skill_name" : "�����麣",
    "damage_type":"����"
]),
});

int valid_enable(string usage) { return  (usage == "club") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("banruo-changong", 1) < 20)
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
    level   = (int) me->query_skill("weituo-gun",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("�������������Τ�ӹ���\n");
    me->receive_damage("qi", 25);
    return 1;
}
