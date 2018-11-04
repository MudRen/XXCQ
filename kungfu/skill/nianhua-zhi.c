// nianhua-zhi.c -�黨ָ

inherit SKILL;

mapping *action = ({
([      "action" : "$N����̧�ۣ���ָ���˸���Ȧ��һʽ��ƿ�����⡹����$n��$l",
        "force" : 60,
        "dodge" : -5,
        "lvl" : 0,
        "skill_name" : "ƿ������",
        "damage_type" : "����"
]),
([      "action" : "$N�������У�һʽ����÷�������ָ��Ҹ������ָ��$n����ǰ",
        "force" : 70,
        "dodge" : -5,
        "lvl" : 0,
        "skill_name" : "��÷����",
        "damage_type" : "����"
]),
([      "action" : "$N����б�У����ְ��ƣ�����һʽ�������ʾơ�����$n��$l����",
        "force" : 90,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "�����ʾ�",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀ΢����һʽ��¶��б������˫�ֻû���ǧ�ٸ�ָӰ������$n��$l",
        "force" : 120,
        "dodge" : 5,
        "damage": 10,
        "lvl" : 9,
        "skill_name" : "¶��б��",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�����³��ء������ƻ�ס�������бָ���죬���Ƶ���$n��$l",
        "force" : 160,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 18,
        "skill_name" : "���³���",
        "damage_type" : "����"
]),
([      "action" : "$N˫��ƽ����ǰ��ʮָ�濪��һʽ��Ҷ����������ָ��$n�������Ѩ",
        "force" : 210,
        "dodge" : 20,
        "damage": 15,
        "lvl" : 27,
        "skill_name" : "Ҷ������",
        "damage_type" : "����"
]),
([      "action" : "$N˫�Ʒ��ɣ�һʽ�������𡹣�ָ�˱ų�����������������$n��ȫ��",
        "force" : 270,
        "dodge" : 25,
        "damage": 20,
        "lvl" : 36,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��������˪������ָ���У�һ����������ٱ�ĵ�����������$n��$l��ȥ",
        "force" : 340,
        "dodge" : 30,
        "damage": 30,
        "lvl" : 45,
        "skill_name" : "������˪",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��٤Ҷ΢Ц����˫��ʳָ���棬ָ�����һ�����������$n��$l",
        "force" : 420,
        "dodge" : 35,
        "damage": 40,
        "lvl" : 55,
        "skill_name" : "٤Ҷ΢Ц",
        "damage_type" : "����"
]),
([      "action" : "$N����������ǰ��һʽ�������黨��������ʳָ��סĴָ���������$nһ��",
        "force" : 510,
        "dodge" : 50,
        "damage": 10,
        "lvl" : 62,
        "skill_name" : "�����黨",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanhua-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���黨ָ������֡�\n");
        if ((int)me->query_skill("banruo-changong", 1) < 20)
                return notify_fail("��İ���������򲻹����޷�ѧ�黨ָ��\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����黨ָ��\n");
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
        level   = (int) me->query_skill("nianhua-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������黨ָ��\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"nianhua-zhi/" + action;
}
