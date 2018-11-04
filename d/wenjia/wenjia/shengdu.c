// SKILL: shengdu.c ����
// Created by Zeus 1999.4.30
// Modified by Zeus 1999.6.8
// �޸��书������
// ԭ���书�����ˣ������ˡ�
 
inherit SKILL;

mapping *action = ({
([	"action" : "$N�������е����ã��á�������������һ����������������",
//	"parry_action" : "",
	"damage" : 10,
	"parry"  : 0,
	"force"  : 10,
	"lvl"  : 0,
	"dodge"  : 0,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N����ָһ������Ȼ�á��乬���������ˡ�ʮ���������",
//	"parry_action" : "",
	"damage" : 20,
	"parry"  : -10,
	"force"  : 20,
	"lvl"  : 15,
	"dodge"  : -10,
	"skill_name" : "ʮ�����",
        "damage_type" : "����"
]),
([	"action" : "$N�����еĹ���ƽ�ţ�������ָ�����������á��̡��������ġ���ɽ��ˮ����",
//	"parry_action" : "",
	"damage" : 40,
	"parry"  : -20,
	"force"  : 40,
	"lvl"  : 30,
	"dodge"  : -20,
	"skill_name" : "��ɽ��ˮ",
        "damage_type" : "����"
]),
([	"action" : "$N����ָ�ڹ��ٵ����ϲ�����һ����ƽɳ���㡹�����á��ǡ������������",
//	"parry_action" : "",
	"damage" : 40,
	"parry"  : -30,
	"force"  : 60,
	"lvl"  : 45,
	"dodge"  : -30,
	"skill_name" : "ƽɳ����",
        "damage_type" : "����"
]),
([      "action" : "ֻ����$N����ָ���ڹ����ϣ�Ҳû���������á��硹������ġ�����������",
//	"parry_action" : "",
	"damage" : 40,
	"parry"  : -40,
	"force"  : 80,
	"lvl"  : 60,
	"dodge"  : -40,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N�ӻ�������һ��������ȴ��û�����Ķ�������ʱһ���á����硹���ġ�����ʮ���ġ�����������",
//	"parry_action" : "",
	"damage" : 100,
	"parry"  : -60,
	"force"  : 80,
	"lvl"  : 100,
	"dodge"  : -50,
	"skill_name" : "����ʮ����",
        "damage_type" : "����"
]),
([	"action" : "$N�ӻ����ó�һ��$nû��������������ʵ$nҲ�޷�ȷ�����Ƿ�������ֻ���������������ң�$N�á��𡹵��������һ��ʧ���Ѿõġ�����ɢ����",
//	"parry_action" : "",
	"damage" : 120,
	"parry"  : -80,
	"force"  : 100,
	"lvl"  : 130,
	"dodge"  : -70,
	"skill_name" : "����ɢ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "lphand") || (usage == "parry");  }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("����������������Ѷ��ų�ȥ!\n");
        if ((int)me->query_skill("lphand", 1) < 50)
                return notify_fail("��ʩ���ַ�������������ʩ��!\n");
        if ((int)me->query_skill("zhixin", 1) < 50)
                return notify_fail("���¹�֪�¡���򲻹����ʩ���������Ķ�!\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("shengdu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("�����������á�ʩ���ַ���ʩ���ģ�����������!\n");
        if ((int)me->query("jingli") < 40)
        return notify_fail("Ъһ��ɣ��������ǲ�����Ч����!\n");
        me->add("jingli",-30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shengdu/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( me->query_skill("shengdu",1) > 50 )
                victim->apply_condition("shengdu_poison", random(me->query_skill("shengdu",1)/10) + 1 + victim->query_condition("shengdu_poison"));
}
