// �¼ҵ���
// bye jfeng ����
inherit SKILL;
mapping *action = ({
([  "action":"\n$Nʹһʽ[���ϸ����������$w�ó�һ���׹����$n��$l",
    "force" : 140,
    "lvl" : 20,
    "skill_name" : "���ϸ��",
    "damage_type":  "����"
]),
([  "action":"$N��������Ծ��һʽ�����¸߹ҡ���������ˮ��һкǧ�����$nȫ��",
    "force" : 240,
    "lvl" : 80,
    "skill_name" : "���¸߹�",
    "damage_type":  "����"
]),
([  "action":"\n$Nһʽ[������ͷ��,����$wңҡָ��$n��$l",
    "force" : 300,
    "lvl" : 120,
    "skill_name" : "������ͷ",
    "damage_type":  "����"
]),
([  "action":"\n$N����$wбָ����,һʽ���������⡹����׼$n��$lбб����",
    "force" : 400,
    "lvl" : 180,
    "skill_name" : "��������",
    "damage_type":  "����"
]),
([  "action":"$N����$w�й�ֱ����һʽ��������ˮ����������Ϣ�ض�׼$n��$l����һ��",
    "force" : 420,
    "lvl" : 230,
    "skill_name" : "������ˮ",
    "damage_type":  "����"
]),
([  "action":"\n$N����һ���εض���һʽ������ͬ�ԡ���$w�ó������Ӱ����$n����Χס",
    "force" : 500,
    "lvl" : 280,
    "skill_name" : "����ͬ��",
    "damage_type":  "����"
]),
([  "action" : "$Nļ��ʹһ�С���ɽ��Ҷ����һƬ��������$nȫ��",
    "force" : 700,
    "lvl" : 380,
    "skill_name" : "��ɽ��Ҷ",
    "damage_type":  "����"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("zhixin", 1) < 50)
        return notify_fail("����¹�֪�»��̫ǳ��\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("��Ļ����ڹ����̫ǳ��\n");
    if (me->query_skill("blade", 1) <=me->query_skill("wenjia-daofa", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("wenjia-daofa",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("��������������¼ҵ�����\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"wenjia-daofa/" + action;
}
