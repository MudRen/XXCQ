// shaolin-quan.c ������ȭ
// ������ȭ�ǽ���������ͨ�Ĺ���֮һ,���������Ҳ�����
// load 5/14/99
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N��������һʽ���ڻ����ġ�����ȭ����������ֱ��$n��$l��ȥ",
	"damage" : 20,
	"parry"  : -10,
	"force"  : 90,
	"lvl"  : 0,
	"dodge"  : 10,
	"skill_name" : "�ڻ�����",
	"damage_type" : "����"
]),
([	"action" : "$N����Ծ��һС����һʽ����طֽ𡹣�˫����ȭ�Ӱ���͵���������",
	"damage" : 30,
	"parry"  : -5,
	"force"  : 120,
	"lvl"  : 10,
	"dodge"  : 0,
	"skill_name" : "��طֽ�",
	"damage_type" : "����"
]),
([	"action" : "$N�����ӡ������ţ�һʽ��������ɽ����˫ȭͬʱ������ֱ��$n��$l��ȥ",
	"damage" : 40,
	"parry"  : -15,
	"force"  : 100,
	"lvl"  : 20,
	"dodge"  : 5,
	"skill_name" : "������ɽ",
	"damage_type" : "����"
]),
([	"action" : "$N̤�ϼ�����һʽ����������������ȭ��һ��б�������µ����Ϻ�������",
	"damage" : 50,
	"parry"  : 0,
	"force"  : 110,
	"lvl"  : 30,
	"dodge"  : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����������һʽ����ս��Ұ����˫ȭһǰһ������ƿ�֮��������$n��$l",
	"damage" : 60,
	"parry"  : -10,
	"force"  : 130,
	"lvl"  : 38,
	"dodge"  : -5,
	"skill_name" : "��ս��Ұ",
	"damage_type" : "����"
]),
([	"action" : "$N�����ϲ��۽�$n��һʽ��˫��������˫ȭһ��һ�Ҵ���$n������̫��Ѩ",
	"damage" : 80,
	"parry"  : -20,
	"force"  : 130,
	"lvl"  : 46,
	"dodge"  : 5,
	"skill_name" : "˫����",
	"damage_type" : "����"
]),
([	"action" : "$NĿ¶�׹⣬һʽ��������ʳ��������ɽ�ͻ�������˫ȭ����$n",
	"damage" : 100,
	"parry"  : -10,
	"force"  : 150,
	"lvl"  : 54,
	"dodge"  : 0,
	"skill_name" : "������ʳ",
	"damage_type" : "����"
]),
([	"action" : "$N��ȫ���������߸�Ծ��һʽ��������������˫ȭ�����������$n",
	"damage" : 120,
	"parry"  : -15,
	"force"  : 170,
	"lvl"  : 60,
	"dodge"  : 10,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }      

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail("��������ȭȭ������֡�\n");
    if ((int)me->query_skill("banruo-changong", 1) < 10 && (int)me->query_skill("wuxiang-shengong", 1) < 10)
       return notify_fail("����ڹ���򲻹����޷�ѧ������ȭ��\n");
    if ((int)me->query("max_neili") < 50)
       return notify_fail("�������̫�����޷���������ȭ��\n");
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
    level   = (int) me->query_skill("shaolin-quan",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("�������������������ȭ��\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( me->query_skill("shaolin-quan",1) > 80 
	&& me->query_temp("leiting")
	&& random(me->query("str"))>random(victim->query("str"))
	&& me->query("neili")>50)
	{
		victim->receive_wound("qi", 50 + (me->query_skill("shaolin-quan",1)) / 2 );
		me->add("neili",-50);
		return HIR "$Nȭ�������ֻ������������һ�����죬����$n���Ϸ����Ĺ����������\n" NOR;
	}
	else if ( me->query_skill("shaolin-quan",1) > 160
	&& random(me->query("str")*me->query("combat_exp"))>random(victim->query("str")*victim->query("combat_exp"))
	&& random(me->query_skill("shaolin-quan",1))>130
	&& me->query("neili")>50)
	{
		victim->add("douzhi",-( 1 + random(me->query_skill("shaolin-quan",1)/10)));
		me->add("neili",-50);
		return HIW "$n��$N�������ƣ���������־��Щ�½��ˡ�\n" NOR;
	}
}