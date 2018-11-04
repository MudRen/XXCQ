
#include <ansi.h>
inherit SKILL;
void throw_weapon(object,object,object,int);

mapping *action = ({
  ([
    "action":
"$N��"HIY"$w"NOR"ƽ���𣬽�һ��أ�ȫ������������𣬳���$n���˹�ȥ!",
    "damage":      100,
    "dodge":      -20,
    "parry":      -10,
    "damage_type": "����",
    "name":      "���羪��",
    "lvl" :        10,
    ]),
  ([
    "action":
"$NһԾ�����ڿ��и߾�"HIY"$w"NOR"�����һ������׼$n��$l��ȥ��",
    "damage":   150,
    "dodge":   -20,
    "parry":   -20,
    "damage_type":   "����",
    "name":     "�������",
    "lvl" :        20,
    ]),
  ([
    "action":
"$N��"HIY"$w"NOR"���������ģ�ͻȻһ�ţ�ֻ����һ�ɾ�������$n��Х��ȥ!",
    "damage":   200,
    "dodge":       -10,
    "parry":       -10,
    "damage_type":   "����",
    "name":     "��������",
    "lvl" :        40,
    ]),
  ([
    "action":
"$N�������е�"HIY"$w"NOR"����$n�ĸ�����ȥ��\nȴͻȻ��"HIY"$w"NOR"һ�ᣬ���$n�������ڹ���!",
    "damage":   250,
    "dodge":       -20,
    "parry":   10,
    "damage_type":   "����",
    "name":     "��������",
    "lvl" :        60,
    ]),
  ([
    "action":
"ֻ��$N���Ű���ͼ�μ��ߣ�����һ�ų���������$n�����ߣ�\nȻ���ս�"HIY"$w"NOR"��׼$n��$l��ȥ!",
    "damage":   300,
    "dodge":   10,
    "parry":   -10,
    "damage_type":   "����",
    "name":     "����̻�",
    "lvl" :        80,
    ]),
  ([
    "action":
"$n��������������һ����$N���ֱ�һ�ɣ�������һ��\n��$n�ľ����д���Ȼ������"HIY"$w"NOR"��׼$n�ķ���ä���͵ش�ȥ!",
    "damage":       500,
    "dodge":       -10,
    "parry":       -10,
    "damage_type":  "����",
    "name":       "��������",
    "lvl" :         100,
    ]),
});
 
int valid_learn(object me)
{
        object ob;
  
        if(me->query_skill("arrow",1) < 20)
                return notify_fail("��Ļ����������������졣\n");
        if( (int)me->query("max_neili") < 100 )
                return notify_fail("��������������Ӳ�������\n");
        if( (int)me->query_skill("yiqiguan-riyue",1) < 50 )
                return notify_fail("��Ա����ڹ��ķ�����Ĳ�����\n");
        if( !(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "arrow" )
                return notify_fail("�����޹�������������ѧ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("youren-arrow",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 50, level)];
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int valid_enable(string usage)
{
        return (usage=="arrow" || usage=="parry");
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
             ||      (string)weapon->query("skill_type") != "arrow" )
            return notify_fail("û�й����������\n");
        if( (int)me->query("qi") < 40 || (int)me->query("neili") < 10)
                return notify_fail("����������㣬�Ӳ�������\n");
        me->receive_damage("qi", 20);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"youren-arrow/" + action;
}

