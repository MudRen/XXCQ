// liekong-zhao.c �ѿ�צ
// ƽ��damage:120 ƽ��force:90 ƽ��dodge:5 ƽ��parry:-5
// �ѿ�צ���ص����������ϴ��мܽ��ѣ���ܽ��ף��ȼ���ʱ������Ч��
// By Load

inherit SKILL;

mapping *action = ({
([      "action" : "$NĿ¶�׹⣬�Ų��������ұۼ��죬��Ȼ���Ƴ��˳���һʽ�����������ֳ�צֱ̽$n�ĺ���",
        "damage" : 60,
        "parry"  : -5,
        "force"  : 50,
        "lvl"  : 0,
        "limb"  : "����",
        "dodge"  : 10,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : "$N̤��һ����һʽ�����ء������ַ·���һ�����У�ֱ��$n�����أ����ֺ��أ�����һ�з���",
        "damage" : 70,
        "parry"  : 5,
        "force"  : 60,
        "lvl"  : 12,
        "limb"  : "����",
        "dodge"  : -5,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�۽�$n���ԣ�һʽ�����󡹣����ֳ�צ��$n�����������ȥ�����ֽ�����һ���ĳ�",
        "damage" : 90,
        "parry"  : -5,
        "force"  : 70,
        "lvl"  : 24,
        "limb"  : "����",
        "dodge"  : 10,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : "$N���־���һ�С��۱ۡ�����צ��ɨ�Ƶ�$ņ���������ұ���������Ҷ���",
        "damage" : 100,
        "parry"  : -15,
        "force"  : 80,
        "lvl"  : 36,
        "limb"  : "���",
        "dodge"  : 0,
        "skill_name" : "�۱�",
        "damage_type" : "����"
]),
([      "action" : "$N�ƺ�һ����˫�ֳ�צ����������һʽ����ǡ���һǰһ�󣬳�$n��$l���˳�ȥ",
        "damage" : 120,
        "parry"  : 0,
        "force"  : 100,
        "lvl"  : 48,
        "dodge"  : 10,
        "skill_name" : "���",
        "damage_type" : "����"
]),
([      "action" : "$N�������һʽ�����ġ���˫צ�������磬Я˺���ѷ�֮��ץ��$n��$l",
        "damage" : 140,
        "parry"  : 5,
        "force"  : 110,
        "lvl"  : 60,
        "dodge"  : 5,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : "$N�����Ц������һʽ��˺�졹��˫צһ������������ƺ�Ҫ˺�����и����赲�Ķ���",
        "damage" : 180,
        "parry"  : -5,
        "force"  : 120,
        "lvl"  : 75,
        "dodge"  : 5,
        "skill_name" : "˺��",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�������ɰ�����˫��һչ��������գ�˫צ���Ŵ̶���Х���ѿա����£�$n��ʱ������ɫ",
        "damage" : 200,
        "parry"  : -20,
        "force"  : 130,
        "lvl"  : 90,
        "dodge"  : 5,
        "skill_name" : "�ѿ�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "claw") || (usage == "parry"); }

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
        if ((int)me->query_skill("xuantian-xinfa", 1) < 25)
                return notify_fail("��������ķ���򲻹���\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��ϰ�ѿ�צ���ܳ�������\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������ѿ�צ��\n");
        if ((int)me->query("jingli") < 40)
                return notify_fail("�㾫�����ƣ�ͣ��޷���ϰ�ѿ�צ��\n");
        me->add("neili", -10);
        me->add("jingli",-25);
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
                level   = (int) me->query_skill("liekong-zhao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
        return __DIR__"liekong-zhao/" + action;
}

