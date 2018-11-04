// guanri-jianfa.c ���ս���

inherit SKILL;

mapping *action = ({
([      "name":   "�ճ�����",
        "action" : "$N��ǰ쫵�һ����һ�С��ճ����졹�����չɵ�����â���ַ���ֱ��$n��",
        "dodge" : 20,
        "damage" : 180,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N⧳Ծ��£�һ�С��������ա����ϳ���ʱ��ʱ�����������գ�����Ϧ�գ�һ��һ���䣬��Ȼ��ɱ������Ʋ��ɵ��ġ����ս�������",
        "dodge" : 20,
        "damage" : 160,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N�Ľ���Խ��Խ���ͣ�Խ��Խʢ�����ǹ��ս������������ա�����$n ��",
        "dodge" : 15,
        "damage" : 150,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "name":   "���ձ�ҫ",
        "action" : "$N�����߰˵������������������������ǹ⣬�������һ�С����ձ�ҫ��ֱȡ$n��$l",
        "dodge" : 15,
        "damage" : 200,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "name":   "������ɽ",
        "action" : "$N��������ʱ���ˣ�����һֱ���䣬$Nһֱ���ˣ��䲻���������ܣ����ɳ�ʮ��ߺ󣬱�����������ʹ��һ�С�������ɽ�������Ƽ������$n��$l",
        "dodge" : 25,
        "damage" : 180,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N����һ������ȴ��Ȼ���һ��������[��������]��һ���������۾�������������",
        "dodge" : 25,
        "damage" : 220,
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "name":   "�ճ��Ƽ�",
        "action" : "$N���е�$w����Ȼһ��������â�ֳ㣬����һ����Ȼ�����ң����һ��һ�������ǡ��ճ��Ƽ䡹",
        "dodge" : 15,
        "lvl" : 60,
        "damage" : 200,
        "damage_type" : "����"
]),
([      "name":   "�������",
        "action" : "$N����һ������һ�С�������⡹�Ǵ�������Ľ�â����ȫ���뽣����ȥ�����｣��������һ�㣬��������֮��磬�����׼$n ��",
        "dodge" : 35,
        "damage" : 250,
        "lvl" : 80,
        "damage_type" : "����"
]),
});

int valid_enable(string usage){return (usage== "sword") || (usage== "parry");}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ����������̫ǳ��\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("guanri-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 150)
                return notify_fail("����������������ս�����\n");
        me->receive_damage("qi", 50);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"guanri-jian/" + action;
}

