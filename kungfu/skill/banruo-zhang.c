// banruo-zhang.c ������
// Modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([  "action" : "$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
    "force" : 150,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "��ճ���"
]),
([  "action" : "$N���ƻ�һ��Բ��һʽ��������ա�������б������������$n����ǰ��Ѩ",
    "force" : 160,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 12,
    "skill_name" : "�������"
]),
([  "action" : "$Nʹһʽ���ƶ����롹�����������������ɺ����һ��˦����ն��$n��$l",
    "force" : 170,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 18,
    "skill_name" : "�ƶ�����"
]),
([  "action" : "$N���ƻ��أ���ȭ�����󷢣�һʽ����������������������$n��$l",
    "force" : 185,
    "dodge" : -5,
    "damage_type" : "����",
    "lvl" : 24,
    "skill_name" : "��������"
]),
([  "action" : "$Nʹһʽ������ء���ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
    "force" : 200,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : "�����"
]),
([  "action" : "$N���Ʊ�������һ������һʽ�����б��¡���˫�Ƽ�����$n�ļ�ͷ",
    "force" : 220,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 36,
    "skill_name" : "���б���"
]),
([  "action" : "$N���ϸ߸�Ծ��һʽ����ɽ��ˮ�����Ӹ����£���������$n��ȫ��",
    "force" : 240,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl" : 42,
    "skill_name" : "��ɽ��ˮ"
]),
([  "action" : "$Nʹһʽ��ժ�ǻ�����������������˫�����֣�һ������$n��$l�ȥ",
    "force" : 270,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl" : 48,
    "skill_name" : "ժ�ǻ���"
]),
([  "action" : "$N�������»��أ�һʽ����������������Ȼ��Ϊ�������꣬����$n",
    "force" : 310,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl" : 54,
    "skill_name" : "��������"
]),
([  "action" : "$Nһʽ����շ�ħ����˫�ֺ�ʮ������$n΢΢һҾ��ȫ���ھ�����˰���ӿ����",
    "force" : 360,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl" : 60,
    "skill_name" : "��շ�ħ"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }   

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("�������Ʊ�����֡�\n");
    if ((int)me->query_skill("banruo-changong", 1) < 60)
   return notify_fail("��İ���������򲻹����޷�ѧ�����ơ�\n");
    if ((int)me->query("max_neili") < 300)
   return notify_fail("�������̫�����޷��������ơ�\n");
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
    level = (int)me->query_skill("banruo-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("������������������ơ�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}

string perform_action_file(string action)
{
	return __DIR__"banruo-zhang/" + action;
}
