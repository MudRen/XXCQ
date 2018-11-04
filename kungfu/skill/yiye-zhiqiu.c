// yiye-zhiqiu.c -һҶ֪��
// designed by lks

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	"action" : "$N������ɽ��һʽ�������Ҷ����˫ȭ���ƶ���������$n��$l",
	"force" : 180,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "�����Ҷ",
	"damage_type" : "����"
]),
([	"action" : "$N�������أ�����������һʽ��һҶ��������������$n�Ƴ�",
	"force" : 200,
	"dodge" : 5,
	"damage": 10,
	"lvl" : 20,
	"skill_name" : "һҶ����",
        "damage_type" : "����"
]),
([	"action" : "$N�������飬����������ޣ�һʽ��ҶҶ���项����$n�޿ɶ���",
	"force" : 230,
	"dodge" : 15,
	"damage": 10,
	"lvl" : 30,
	"skill_name" : "ҶҶ����",
        "damage_type" : "����"
]),
([	"action" : "$N����Ծ��һʽ��Ҷ��������˫ȭ���ջ��£��Ʋ��ɵ�",
	"force" : 270,
	"dodge" : 5,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "Ҷ����",
        "damage_type" : "����"
]),
([	"action" : "$N����һ����һʽ��Ҷ�����꡹����ȭ���¶��ϣ�����$n",
	"force" : 320,
	"dodge" : 10,
	"damage": 15,
	"lvl" : 50,
	"skill_name" : "Ҷ������",
        "damage_type" : "����"
]),
([	"action" : "$N����һת��һʽ����ҶƮƮ��������$n����ǰ���",
	"force" : 380,
	"dodge" : 25,
	"damage": 25,
	"lvl" : 68,
	"skill_name" : "��ҶƮƮ",
        "damage_type" : "����"
]),
([	"action" : "$N���λ�λ������ȭ����һʽ�����ɨҶ��������˷�����ȭӰ",
	"force" : 450,
	"dodge" : 15,
	"damage": 35,
	"lvl" : 95,
	"skill_name" : "���ɨҶ",
        "damage_type" : "����"
]),
([	"action" : "$N��Хһ������ǰ̤��һ����˫ȭ�й�ֱ����һʽ��һҶ֪�����Ȼ����$n��ǰ��",
	"force" : 530,
	"dodge" : 20,
	"damage": 50,
	"lvl" : 120,
	"skill_name" : "һҶ֪��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
         mapping myfam;
         myfam=(mapping)me->query("family");

          if ( (myfam) && (myfam["family_name"]!="���ζ���") )
                    return notify_fail("�Բ��𣬴����ѧ���⴫�ġ�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һҶ֪�������֡�\n");
       if ((int)me->query("shen") < 0)
            return notify_fail("һҶ֪�ﲻ�ܱ�������Ϊ��������\n");
        if ((int)me->query_skill("cuff", 1) < 30)
		return notify_fail("���ȭ����򲻹����޷�ѧһҶ֪�\n");
        if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���һҶ֪�\n");
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
	level   = (int) me->query_skill("yiye-zhiqiu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("�������������һҶ֪�\n");
        me->receive_damage("qi", 15);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiye-zhiqiu/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object obb;
	if( damage_bonus < 100 ) return 0;
	if (!(obb = present("yeziye", this_player())) )  return 0;
        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return WHT "���������꡹һ������һ���׹����ȭ����������Ȼ��$nѪð���ɣ���$N��Ҷ���ˣ�\n" NOR;
        }
}
