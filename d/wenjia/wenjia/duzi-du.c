// SKILL: duzi-du.c ���ֶ�
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.6.8
// �޸�parry��dodge��ֵ
// ԭ���书�����ˣ����¿ˡ�������

inherit SKILL;

mapping *action = ({
([	"action" : "$N�������ʳָ�ڶ�ͷ�ϻ���һ�ᣬ���ǡ������ֵĵ�һ����һ�С��������߾���",
//	"parry_action" : "",
	"damage" : 20,
	"parry"  : -5,
	"force"  : 20,
	"lvl"  : 0,
	"dodge"  : -5,
	"skill_name" : "�������߾�",
        "damage_type" : "����"
]),
([	"action" : "$N���������ָ�����ϻ���һ�ᣬ���ǡ������ֵĵڶ�����һ�С���������ѩ��",
//	"parry_action" : "",
	"damage" : 30,
	"parry"  : -10,
	"force"  : 30,
	"lvl"  : 20,
	"dodge"  : -10,
	"skill_name" : "��������ѩ",
        "damage_type" : "�˺�"
]),
([	"action" : "$N�����������ָ�ڲ����ϻ���һ�ᣬ���ǡ������ֵĵ�������һ�С����������",
//	"parry_action" : "",
	"damage" : 40,
	"parry"  : -15,
	"force"  : 40,
	"lvl"  : 40,
	"dodge"  : -15,
	"skill_name" : "���������",
        "damage_type" : "����"
]),
([	"action" : "$N�������βָ����ǰ����һ�������ǡ������ֵĵ��Ļ���һ�С�����Īƾ����",
//	"parry_action" : "",
	"damage" : 50,
	"parry"  : -20,
	"force"  : 50,
	"lvl"  : 60,
	"dodge"  : -20,
	"skill_name" : "����Īƾ��",
        "damage_type" : "����"
]),
([	"action" : "$N�������ĸָ�ڸ������Ȼ���һ������һ�ᣬ���ǡ������ֵĵ��廮��һ�С��޶����ɷ�",
//	"parry_action" : "",
	"damage" : 60,
	"parry"  : -25,
	"force"  : 50,
	"lvl"  : 80,
	"dodge"  : -25,
	"skill_name" : "�޶����ɷ�",
        "damage_type" : "����"
]),
([	"action" : "$N�������ʳָ�ڿ������Ȼ���һ�ᣬ��һ��������һ�ᣬ���ǡ������ֵĵ�������һ�С�������ġ�",
//	"parry_action" : "",
	"damage" : 60,
	"parry"  : -25,
	"force"  : 50,
	"lvl"  : 80,
	"dodge"  : -25,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$N���������ָ�ڿ����л���һ�ᣬ���ǡ������ֵĵ��߻���һ�С����֡�",
//	"parry_action" : "",
	"damage" : 80,
	"parry"  : -35,
	"force"  : 70,
	"lvl"  : 120,
	"dodge"  : -35,
	"skill_name" : "����",
        "damage_type" : "����"
]),
([	"action" : "$N�����������ָ�ڿ����е���һ�£����ǡ������ֵĵڰ˻���һ�С����ֶ���",
//	"parry_action" : "",
	"damage" : 100,
	"parry"  : -50,
	"force"  : 80,
	"lvl"  : 140,
	"dodge"  : -70,
	"skill_name" : "���ֶ�",
        "damage_type" : "����"
]),
([	"action" : "$N�������βָ�������ĵ���һ�㣬���ǡ������ֵĵھŻ���һ�С�����",
//	"parry_action" : "",
	"damage" : 120,
	"parry"  : -80,
	"force"  : 90,
	"lvl"  : 160,
	"dodge"  : -90,
	"skill_name" : "��",
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
        if ((int)me->query_skill("lphand", 1) < 50)
                return notify_fail("��ġ�ʩ���ַ�������������!\n");
        if ((int)me->query_skill("zhixin", 1) < 50)
                return notify_fail("���¹�֪�¡��ȼ�����ʱ�����߻���ħ�ġ�\n");
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
                return notify_fail("�����ֶ�����ʩ���ģ�����ʹ��������!\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("������ϰ�Ϳ���ˡ�\n");
        me->add("qi",-30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"duzi-du/" + action;
}

