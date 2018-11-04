// wuxing-jian.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : BLU"$N�������׼$n������һ����λ�����Ƶģ�ÿһ��������������$n������"NOR,
        "force" : 60,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 50+random(100)/10,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : BLU"$NĿ���������ѱ���罣��ķ�����һ�������������磬��$n��Ϯ����"NOR,
        "force" : 70,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50+random(100)/5,
        "lvl" : 4,
        "damage_type" : "����"
]),
([      "action" : BLU"$N��ǧ��㽣�涼�����ˡ�ֻʣ��$w�����������׼��$n����ʱ���ѱܲ�����$w�����ʺ�"NOR,
        "force" : 80,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 80+random(100)/3,
        "lvl" : 9,
        "damage_type" : "����"
]),
([      "action" : BLU"$N��̧���֣�������һ�ڣ�����$n�Ľ��⣬����������ʱ��$N�����ֺ�Ȼ���������������$n�Ķ��ӡ�"NOR,
        "force" : 90,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 80+random(100)/2,
        "lvl" : 14,
        "damage_type" : "����"
]),
([      "action" : BLU"$N����ɫ���ˣ��˽�һ�ϣ���Ҫ�ɹ������������ʱ��$N�����ֶ���һ����!"NOR,
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 80+random(100),
        "lvl" : 19,
        "damage_type" : "����"
]),
([      "action" : BLU"$N��$w��ȴ����ǹ���ң����Ȼ�ֱ����$nֱ�̳�ȥ����ǧ����ã��ѵ��˺��ޱ仯��"NOR,
        "force" : 110,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 100+random(200)/5,
        "lvl" : 24,
        "damage_type" : "����"
]),
([      "action" : BLU"$N����ͻȻ�ֶ���һ������$w�����$wһ����$n��������֡�$n��ȫ�Ӳ��½��У�һֱ���ˡ�"NOR,
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 100+random(200)/2,
        "lvl" : 29,
        "damage_type" : "����"
]),
});


int valid_enable(string usage)
{ return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������������\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("wuxing-jian",1);
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
        if ((int)me->query("qi") < 100)
           return notify_fail("����������������ν�����\n");
        me->receive_damage("qi", 50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuxing-jian/" + action;
}
