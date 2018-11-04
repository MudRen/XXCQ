//
// huoyan-dao.c ���浶
// Designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ��һ�С���ľȡ�𡹣�����ת��˫����ǰƽƽ����$n",
        "skill_name" : "��ľȡ��",
        "force" : 100,
        "lvl" : 0,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�ף�ڻ��桹�������絶��бб����$n��$l",
        "skill_name" : "ף�ڻ���",
        "force" : 150,
        "lvl" : 10,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�����ޱߡ���˫��һ�ģ�һ�����������й���$n��$l",
        "skill_name" : "����ޱ�",
        "force" : 200,
        "lvl" : 20,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С������ֻء���˫�ֺ�ʮ����ͷ����$n",
        "skill_name" : "�����ֻ�",
        "force" : 250,
        "lvl" : 30,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�˫�����桹��˫��һ�������������湥��$n��$l",
        "skill_name" : "˫������",
        "force" : 300,
        "lvl" : 40,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���ɽ�𺣡���˫������б�ģ���ʱ��ǧ������������˷�����$n",
        "skill_name" : "��ɽ��",
        "force" : 350,
        "lvl" : 60,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С��׷��ȡ�����ۻ��գ�����������ֱ��$n��$l",
        "skill_name" : "�׷���",
        "force" : 400,
        "lvl" : 80,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�������������˫��΢��������ǰ�죬һ���ھ�����ɽ�����㹥��$n",
        "skill_name" : "��������",
        "force" : 500,
        "lvl" : 100,
        "damage" : 100,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����浶������֡�\n");

	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("wuxiang-shengong", 1) < 30)
		return notify_fail("��������񹦻��̫ǳ��\n");

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
		  level   = (int) me->query_skill("huoyan-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����浶������֡�\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("������������������˻��浶��\n");
	me->receive_damage("qi", 20);
	return 1;
}


string perform_action_file(string action)
{
	return __DIR__"huoyan-dao/" + action;
}

