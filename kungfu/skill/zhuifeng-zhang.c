// ׷����
// bye jfeng ����
inherit SKILL;
mapping *action = ({
([  "action" : "$Nʹһ��[���������ٻ���],��̬������������ɨץ��$n",
    "force" : 150,
    "lvl" : 10,
    "skill_name" : "���������ٻ���",
    "damage_type" : "����"
]),
([  "action" : "$N����һ�䣬���Ƴ�һ��[���粻�����Ź�],����$n��$l",
    "force" : 250,
    "lvl" : 50,
    "skill_name" : "���粻�����Ź�",
    "damage_type" : "����"
]),
([  "action" : "$N��̤һ������̤һ������һ��[��������ԭ���],����$n��$l",
    "force" : 350,
    "lvl" : 100,
    "skill_name" : "��������ԭ���",
    "damage_type" : "����"
]),
([  "action" : "$N�������������[������罥����],����$n��$l",
    "force" : 400,
    "lvl" : 150,
    "skill_name" : "������罥����",
    "damage_type" : "����"
]),
([  "action" : "$N���˼�������Ȼ���Ȱ��ת��$n�����˫�������������һʽ[̤��׷����Ʈ��]",
    "force" : 500,
    "lvl" : 300,
    "skill_name" : "̤��׷����Ʈ��",
    "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="leiting-zhi"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("ѧ׷���Ʊ�����֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�ѧ׷���ơ�\n");
    if (me->query_skill("strike", 1) <=me->query_skill("zhuifeng-zhang", 1))
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
    level   = (int) me->query_skill("zhuifeng-zhang",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��׷���Ʊ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������׷���ơ�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"zhuifeng-zhang/" + action;
}
