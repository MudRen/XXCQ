#include <ansi.h>

inherit SKILL;

mapping *action = ({
   (["skill_name" : "������·",
     "action":     "$N����ǰ��벽,����ǰ��,һʽ��������·��,����$w��ɨ��$n��$l",
     "dodge":   10,
     "force" : 300,
     "lvl" : 0,
     "damage_type":  "����"]),
   (["skill_name" : "����ȡ��",
     "action":     "$N�������,����$w˳��һ�С�����ȡ����,���¶���ն��$n��$l",
     "dodge":   20,
     "force" : 310,
     "lvl" : 10,
     "damage_type":  "����"]),
   (["skill_name" : "��������",
     "action":     "$Nһ�С��������ġ�,��$w����,�ڿ��л��˵��뻡,����ֱɨ��$n��$l",
     "dodge":   30,
     "force" : 320,
     "lvl" : 20,
     "damage_type":  "����"]),
   (["skill_name" : "��ճ���",
     "action":     "$N��һ���������ˡ���˫�־���$w,ǰ��һ��,һ�С���ճ��桻,���⼲��$n��$l",
     "dodge":   40,
     "force" : 345,
     "lvl" : 30,
     "damage_type":  "����"]),
   (["skill_name" : "�޺�ɨ��",
     "action":     "$N����һת,����һ��,��һ�С��޺�ɨ����,����һ��,��$n��$l��ȥ",
     "dodge":   40,
     "force" : 360,
     "lvl" : 40,
     "damage_type":  "����"]),
   (["skill_name" : "�����ն�",
     "action":     "$N����΢��,���󼲷�,һʽ�������նɡ�,�������¶��ϳ�$n��$l��ȥ",
     "dodge":   30,
     "force" : 380,
     "lvl" : 50,
     "damage_type":  "����"]),
   (["skill_name" : "�زص�î",
     "action":     "$N����Ծ������,$w��ջ��˸���,һ�С��زص�î��,���϶�������$n��$l",
     "dodge":   40,
     "force" : 400,
     "lvl" : 60,
     "damage_type":  "����"]),
   (["skill_name" : "��Ħ�ɽ�",
     "action":     "$N����һ��,ʹ������Ħ�ɽ���,����$w��׼$n��$lֱ�̹�ȥ",
     "dodge":   30,
     "force" : 430,
     "lvl" : 70,
     "damage_type":  "����"]),
});

int valid_enable(string usage){return usage=="sword" || usage=="parry";}

int valid_learn(object me)
{
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
    level   = (int) me->query_skill("chixin-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 35)
    return notify_fail("�������Ŀǰû�а취��ϰ���Ľ���\n");
    me->receive_damage("qi", 15);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"chixin-jian/" + action;
}


