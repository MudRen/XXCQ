// xuehua-shenjian.c ѩ����
// by god

#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "name":         "��������",
                "action":       "$Nʹ��ѩ�������е�"+HIR"������������"NOR+"$N�ѷ·��������һ��",
                "dodge":        50,
                "parry" :       100,
                "force":        170,
        "damage" :  100,
                "damage_type":  "����"
        ]),
        ([      "name":         "�����ܲ�",
             "action":       "$Nʹ��ѩ�������е�"+HIW"�������ܲ���"NOR+"��$N��ʱ�˻�����",
                "dodge":        100,
                "parry" :       200,
                "force" :       200,
        "damage":   150,
                "damage_type":  "����"
        ]),
        ([      "name":         "��ȥ����",
                "action":       "$N�ٽ���ͷ�������������ޣ�$w����ңָ$n��ʹ��ѩ�������е�"+HIR"����ȥ���Ρ�"NOR,
                "dodge":        100,
                "parry" :       200,
                "force":        170,
        "damage" :  200,
                "damage_type":  "����"
        ]),
        ([      "name":         "��������",
                "action":       "$Nʹ��ѩ�������е�"+HIY"������������"NOR+"��������������ס$n��ʹ$n׹���˳�˯֮��",
                "dodge":        100,
                "parry" :       200,
                "force" :       200,
        "damage":   250,
                "damage_type":  "����"
        ]),
        ([      "name":         "����ͬ��",
                "action":       "$Nʹ��ѩ�������е�"+HIC"������ͬ�ԡ�"NOR+"�����Ų�æ��$N����һ�ᣬ����ס����������һ����������$n",
                "dodge":        100,
                "parry" :       200,
                "force" :       300,
                "damage":       250,
                "damage_type":  "����"
        ]),
        ([      "name":         "ѩ�����",
                "action":       "$Nֻ���������һ��׳�������ƣ�ʹ��ѩ�������е�"+MAG"��ѩ����㡹"NOR+"������$n",
                "dodge":        100,
                "parry" :       200,
                "force" :       350,
                "damage":       300,
                "damage_type":  "����"
        ]),
        ([      "name":         "ѩ��̫ɽ",
                "action":       "$n�о�������,����ǵص�ӿѹ����������ѩ�������еġ�ѩ��̫ɽ��",
                "dodge":        100,
                "parry" :       200,
                "force" :       400,
                "damage":       350,
                "damage_type":  "����"
        ]),
        ([      "name":         "��ӷɶ�",
                "action":       "$n��Ҫ�̳�����Ȼ�����Լ����Ρ����ǡ�ƮƮ���ɣ�����$Nһ��������"+CYN"����ӷɶݡ�"NOR,
                "dodge":        100,
                "parry" :       200,
                "force" :       400,
                "damage":       400,
                "damage_type":  "����"
        ]),
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 

int valid_learn(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("�������������\n");
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
    level   = (int) me->query_skill("xuehua-shenjian",1);
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
    if ((int)me->query("qi") < 40)
        return notify_fail("�������������ѩ��������\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"xuehua-shenjian/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        
        if( damage_bonus < 100 ) return 0;
        if (!(me->query("xuehuafore"))) return 0;
        if( random(damage_bonus/2) > victim->query_str() ) {        
        if (me->query("xuehuafore")==1) {
        victim->receive_wound("qi",damage_bonus/2 );
        msg= HIW "$n��ѩ���񽣵Ľ������ˡ�\n" NOR;
        }
        return msg;
        }
}

