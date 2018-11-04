// huashan-jianfa.c ��ɽ����

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С����Ƴ�ᶡ�������$w����$n��$l",
	"lian"  :"$Nʹ��һ�С����Ƴ�ᶡ�������$w������ȥ......",
    "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
	"damage" : 20,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ�����з����ǡ���$w��˸����������$n��$l",
	"lian"  :"$Nʹ�����з����ǡ���$w��˸����������ǰ��......",
    "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
	"damage" : 25,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����������$w���϶��»���һ���󻡣���$n������ȥ",
    "lian"  :"$N����һ�С�����������$w���϶��»���һ����......",
    "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
	"damage" : 30,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ����һ��������$wʹ�����׺���ա�ֱ��$n��$l",
	"lian"  :"$N��ǰ����һ��������$wʹ�����׺���ա�......",
    "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
	"damage" : 35,
	"damage_type" : "����"
]),
([      "action" : "$N���е�$wһ�Σ�ʹ��������ӭ�͡�ֱ��$n��$l",
		"lian"  :"$N���е�$wһ�Σ�ʹ��������ӭ�͡�......",
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage" : 50,
        "damage_type" : "����"
]),
});



int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
		
if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("��Ļ�ɽ�ڹ����̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 20)
		return notify_fail("��ľ���������\n");
	me->add("jingli",-20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huashan-jianfa/" + action;
}
