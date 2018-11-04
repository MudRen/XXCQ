//huaibao-tianxia.c
//by mulan

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : HIY"$N����һչ������$n���ؾ���һ�ǡ��ڻ�͵��"NOR,
    "force" : 320,
    "dodge" : 10,
    "damage": 50,
    "lvl"   : 0,
    "skill_name" : "�ڻ�͵��" ,
    "damage_type" : "����"
]),
([  "action" : HIY"$N����һ����һ������$n�����ѣ����ǡ������߶�"NOR,
    "force" : 380,
    "dodge" : 20,
    "damage": 80,
    "lvl"   : 20,
    "skill_name" : "�����߶�" ,
    "damage_type" : "����"
]),
([  "action" : HIY"$N����һƮ����$n���һ�����������ǡ�������ɽ"NOR,
    "force" : 440,
    "dodge" : 30,
    "damage": 100,
    "lvl"   : 40,
    "skill_name" : "������ɽ" ,
    "damage_type" : "����"
]),
([  "action" : HIY"$N����һ�Σ�һ�Ƴ����ֱ��$n�����ţ����ǡ���������"NOR,
    "force" : 520,
    "dodge" : 40,
    "damage": 150,
    "lvl"   : 60,
    "skill_name" : "��������" ,
    "damage_type" : "����"
]),
([  "action" : HIY"$N����һ�����Ӹ����£���$n�������£����ǡ�������ɽ"NOR,
    "force" : 620,
    "dodge" : 50,
    "damage": 200,
    "lvl"   : 100,
    "skill_name" : "������ɽ" ,
    "damage_type" : "����"
]),
});

// int valid_enable(string usage) { return usage=="strike" ||  usage=="hand" || usage=="finger" || usage=="claw" || usage=="cuff"; }
int valid_enable(string usage) { return usage=="unarmed";}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����������񹦱�����֡�\n");
	if (me->query_str() < 40)
		return notify_fail("��ı���������������ϰ�⾪����ȭ���񹦡�\n");
        if ((int)me->query("max_neili") < 500)
            return notify_fail("�������̫�����޷������������񹦡�\n");
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
	level = (int) me->query_skill("huaibao-tianxia",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	int skill;
	skill = me->query_skill("huaibao-tianxia",1);
	if ((int)me->query("qi") < 200)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("���������������\n");
 //��Ϊ����ɽ��һ�� adx
 //    if( environment(me)->query("no_fight") )
 //        return notify_fail("�����������������ˡ�\n");
 //    if( environment(me)->query("sleep_room") )
 //        return notify_fail("������������ű�����Ϣ��\n");
        if(me->query("shen") < 10000)
		return notify_fail("�����������񹦿���Ҫ�����徫����С�\n");
 //��Ϊ����ɽ��һ�� adx
     me->receive_damage("qi", 10);
     me->add("neili", -10);
	tell_room(environment(me), 
HIY"ֻ��"+me->query("name")+"˫�����졢������࣬����������ת��˫��֮��ɢ��˿˿
���̣������Ľ����ϵ���Ҷ��С֦���������С����˫��һ�գ����������ģ�����ĺ�����\n"NOR);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return HIR "�˵�һ����$n����$N�Ļ�����������ÿ�����Ѫ��\n" NOR;
	}
}

string perform_action_file(string action)
{
    return __DIR__"huaibao-tianxia/" + action;
}
