#include <ansi.h>
inherit SKILL;
mapping *action = ({
([	"action":		"$N˫���������裬һ�С������롹��$wֱ��$n���ظ�Ҫ��",
	"dodge":		-10,
	"damage":		200,
	"lvl" : 0,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N���λζ���һ�С������롹������$w��һ�����ߣ���$n�ʺ��ȥ",
	"dodge":		-20,
	"damage":		300,
	"lvl" : 60,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N��ָ΢�ţ�һ�С���Ѫ�롹������$w���ð���$nȫ��ȥ",
	"dodge":		-40,
	"damage":		400,
 	"lvl" : 90,
	"skill_name" : "��Ѫ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N���һ����һ�С�����롹��$w�û�����Ŀ����������$n",
	"dodge":		-50,
	"damage":		500,
	"lvl" : 100,
	"skill_name" : "�����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N��һԾ��һ�С������롹��$w�����������磬����$nȫ��",
	"dodge":		-60,
	"damage":		600,
 	"lvl" : 110,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N˫Ŀ��â������һ�С���Ѫ�롹������$wȫ�����ַɳ�����ɽ���������$nȫ��",
	"dodge":		-60,
	"damage":		700,
	"lvl" : 120,
	"skill_name":  "��Ѫ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N������Х��һ�С������롹��$w��Ȼ����һ��ǿ�Ҿ��磬ɨ��$n",
	"dodge":		-70,
	"damage":		800,
	"lvl" : 130,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N����ɱ��ͻȻ��ʢ��һ�С�ɱ���롹��$w�ɻȰ����$nȫ��",
	"dodge":		100,
	"damage":		900,
	"lvl" : 200,
	"skill_name" : "ɱ����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
});
int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }
int valid_learn(object me)
{
	object weapon;
     if((int)me->query("max_neili")<200)
         return notify_fail("�����������������Ѫ���롣\n");
     if((int)me->query_skill("huaxue-dafa",1)<100)
         return notify_fail("��Ļ�Ѫ�󷨻��̫ǳ��\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "throwing" )
		return notify_fail("�����ϲ�û�а�������ô����\n");
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
	level   = (int) me->query_skill("huaxue-shenzhen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("���������������Ѫ���롣\n");
       me->receive_damage("qi",20);
	return 1;
}
string perform_action_file(string action)
{
	if ( this_player()->query_skill("huaxue-shenzhen", 1) >= 50 )
		return __DIR__"huaxue-shenzhen/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (me->query_skill("huaxue-shenzhen", 1) >= 100) {
                 victim->receive_wound("qi",(damage_bonus-100));
                 victim->receive_wound("jingli",(damage_bonus-100)/3);
            if (!(victim->query_condition("hx_poison")))
          victim->apply_condition("hx_poison", me->query_skill("huaxue-shenzhen",1)/10);
            return HIR"��ڤ�������һ��ǿ�ҵ���ת��������һ������$n�����ڡ�ֻ����$nʹ��ĺ���һ����\n"NOR;
	}
}

