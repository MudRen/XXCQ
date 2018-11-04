// youyu-quan.c ����ȭ
// modified by Atlus 1999.7.23
//

inherit SKILL;

mapping *action = ({
([  "action" : "$N����һ������ȭ��΢��������ȭ����ʹ������Ŀ���项����$n��$l",

        "damage" : 15,
        "parry"  : 5,
        "force"  : 20,
        "lvl"  : 0,
        "dodge"  : 5,
        "skill_name" : "��Ŀ����",
        "damage_type" : "����"
]),
([  "action" : "$N��ȭ����������$n��æ�мܣ�����$N��ȭ�������У���ȭһ��[��������]����$n��$l",
        
        "damage" : 25,
        "parry"  : 5,
        "force"  : 25,
        "lvl"  : 15,
        "dodge"  : 5,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nʹ��һ�С��ຣ���ġ�����ȭ���һ�£�������ȭ��������$n��$l",
        "damage" : 35,
        "parry"  : 0,
        "force"  : 35,
        "lvl"  : 30,
        "dodge"  : 0,
        "skill_name" : "�ຣ����",
        "damage_type" : "����"
]),

([  "action" : 
"$N˫ȭһ��ʹ�����ನδ�ˡ�����׼$n��$l����������ȭ",
        "damage" : 50,
        "parry"  : -5,
        "force"  : 45,
        "lvl"  : 45,
        "dodge"  : 0,
        "skill_name" : "�ನδ��",
        "damage_type" : "����"
]),

([  "action" : 
"$Nʹ��һ��[���θ���]����ȭ������ȭ�����Ի���֮����$n��ȥ",
        "damage" : 65,
        "parry"  : -5,
        "force"  : 65,
        "lvl"  : 60,
        "dodge"  : -5,
        "skill_name" : "���θ���",
        "damage_type" : "����"
]),

([      "action":               
"$N����һ�ݣ�ʹ��һ�С������콵����˫ȭ���϶��£�����$n��$l",
        "damage" : 85,
        "parry"  : -10,
        "force"  : 75,
        "lvl"  : 75,
        "dodge"  : -10,
        "skill_name" : "�����콵",
        "damage_type" : "����"
]),
        
([      "action":
"$Nʹ��һ��[��������]��ͻȻ�ӳ�һȭ������������ǰ���ٴ��һȭ�������������������һȭ����ȭ����һ�����$n��$l",
        "damage" : 120,
        "parry"  : -10,
        "force"  : 90,
        "lvl"  : 100,
        "dodge"  : -10,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "cuff") || (usage == "parry"); }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("cuff", 1) < 20)
		return notify_fail("��Ļ���ȭ��̫���ˡ�\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))

       return notify_fail("������ȭ��ʱ������֡�\n");


	if ((int)me->query("jingli") < 50)
		return notify_fail("�㾫��״̬̫���ˣ�����Ъһ�������ɡ���\n");
	me->add("jingli",-25);
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("youyu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
	return __DIR__"youyu-quan/" + action;
}


