// SKILL: bupangguan.c ���ֲ��Թ�
// Created by Zeus 1999.5.11
// Modified by Zeus 1999.5.11
// 
// 
inherit SKILL;

mapping *action = ({
([	"action" : "$N������ǰ�ͳ壬˫�ּ�����ʹ��һ�С�������Ϊ����",
//	"parry_action" : "",
	"damage" : 50,
	"parry"  : 10,
	"force"  : 20,
	"lvl"  : 0,
	"dodge"  : 20,
	"skill_name" : "������Ϊ",
        "damage_type" : "����"
]),
([	"action" : "$N��������һ���ε��Ķ�����ʹ�����ε���������������ǰ���塣",
//	"parry_action" : "",
	"damage" : 50,
	"parry"  : 10,
	"force"  : 20,
	"lvl"  : 20,
	"dodge"  : 20,
	"skill_name" : "�ε�����",
        "damage_type" : "����"
]),
([	"action" : "$N���ӵĹ���ͻȻ������������ǰ�ĳ����ƣ�����һ�С��򱧲�ƽ����",
//	"parry_action" : "",
	"damage" : 50,
	"parry"  : 10,
	"force"  : 20,
	"lvl"  : 40,
	"dodge"  : 20,
	"skill_name" : "�򱧲�ƽ",
        "damage_type" : "����"
]),
([	"action" : "$N��˫����˸����⣬һ�С����۲��Թۡ�ʹ�������ƶ�ʱ����������",
//	"parry_action" : "",
	"damage" : 70,
	"parry"  : 30,
	"force"  : 40,
	"lvl"  : 60,
	"dodge"  : 50,
	"skill_name" : "���۲��Թ�",
        "damage_type" : "����"
]),
([	"action" : "$N������֮�е�����ת��$n��˫���ĳ�������������һ�С��������Ϲۡ���",
//	"parry_action" : "",
	"damage" : 70,
	"parry"  : 30,
	"force"  : 40,
	"lvl"  : 80,
	"dodge"  : 50,
	"skill_name" : "�������Ϲ�",
        "damage_type" : "����"
]),
([	"action" : "$N�����Ӹ�Ҫ���£�ͻȻ����ʹ��������Ҫ�ȡ���˫����$n��ȥ��",
//	"parry_action" : "",
	"damage" : 70,
	"parry"  : 30,
	"force"  : 40,
	"lvl"  : 100,
	"dodge"  : 50,
	"skill_name" : "����Ҫ��",
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
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("zhixin", 1) < 20)
                return notify_fail("��ġ��¹�֪�¡���򲻹���\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("duzi-du",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��ϰ�����ֲ��Թۡ����ܳ�������\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("��̫���ˣ�����Ъһ�������ɡ���\n");
	me->add("qi",-30);
        return 1;
}
