// luohan-quan.c �޺�ȭ
// modified by Venus Oct.1997
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([  "action" : "$N�����ϲ���һʽ����ݺ��ܡ��������ַֿ�����ȭΪ�ƣ�����$n��$l",
    "force" : 180,
    "dodge" : 5,
    "lvl" : 0,
    "skill_name" : "��ݺ���",
    "damage_type" : "����"
]),
([  "action" : "$N�����̤��ȫ����ת��һ�С����ﳯ�����������͵ز���$n��$l",
    "force" : 200,
    "dodge" : 10,
    "lvl" : 8,
    "skill_name" : "���ﳯ��",
    "damage_type" : "����"
]),
([  "action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С����Ӷ�Ӧ����˫ȭ��$n��$l��ȥ",
    "force" : 220,
    "dodge" : 15,
    "lvl" : 15,
    "skill_name" : "���Ӷ�Ӧ",
    "damage_type" : "����"
]),
([  "action" : "$N����Ȧ���������⵱�أ����ڳ��ϣ�һ�С�ƫ�����ǡ�����$n��$l",
    "force" : 260,
    "dodge" : 20,
    "lvl" : 24,
    "skill_name" : "ƫ������",
    "damage_type" : "����"
]),
([  "action" : "$Nʹһ�С��ຣ��ͷ��������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
    "force" : 300,
    "dodge" : 25,
    "lvl" : 33,
    "skill_name" : "�ຣ��ͷ",
    "damage_type" : "����"
]),
([  "action" : "$N˫�ƻ�����һ�ǡ�Юɽ���������Ƴ���磬һ�����е�$n������",
    "force" : 360,
    "dodge" : 30,
    "lvl" : 42,
    "skill_name" : "Юɽ����",
    "damage_type" : "����"
]),
([  "action" : "$Nʩ��������������˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
    "force" : 420,
    "dodge" : 35,
    "lvl" : 50,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$N����ڿۣ�����������һʽ�������������˫�����밴��$n���ؿ�",
    "force" : 480,
    "dodge" : 40,
    "lvl" : 58,
    "skill_name" : "�������",
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }      

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail("���޺�ȭ������֡�\n");
    if ((int)me->query_skill("banruo-changong", 1) < 10 && (int)me->query_skill("wuxiang-shengong", 1) < 10)
       return notify_fail("����ڹ���򲻹����޷�ѧ�޺�ȭ��\n");
    if ((int)me->query("max_neili") < 50)
       return notify_fail("�������̫�����޷����޺�ȭ��\n");
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
    level   = (int) me->query_skill("luohan-quan",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("��������������޺�ȭ��\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( me->query_skill("luohan-quan",1) > 80 
	&& random(me->query("str"))>random(victim->query("str"))
	&& random(me->query_skill("shaolin-quan",1))>80
	&& me->query("neili")>50)
	{
		victim->receive_wound("qi", random(50) + (me->query_skill("shaolin-quan",1)) / 2 );
		me->add("neili",-50);
		return HIY "$N������ͻȻ����������⣬����Ʈ�裬��ɫ���أ����ư��磬�������޺��·�����һȭ����Ҳ��ò�ͬ������\n" NOR;
	}
	else if ( me->query_skill("shaolin-quan",1) > 160
	&& random(me->query("str")*me->query("combat_exp"))>random(victim->query("str")*victim->query("combat_exp"))
	&& random(me->query_skill("shaolin-quan",1))>150
	&& me->query("neili")>50)
	{
		victim->start_busy(2);
		me->add("neili",-50);
		return HIW "ͻȻʮ�����޺���Ӱ��$n���˹�ȥ$n�Ѿ��Ҳ�����$N��������Ӱ��\n" NOR;
	}
}