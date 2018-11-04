// poshan-dao.c ��ɽ��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N�ս�����$wһ�С�����һ��������$n��$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 20,
        "lvl"    : 0,
        "skill_name" : "����һ��", 
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ��������$wʹ������ħһ��������$n�ĺ�",
        "force" : 90,
        "dodge" : 80,
        "damage" : 50,
        "lvl"    : 20,
        "skill_name" : "��ħһ��",
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N�������е�$w��ʹ��������һ���������ֱ��$n",
        "force" : 90,
        "dodge" : 70,
        "damage" : 60,
        "lvl"    : 40,
        "skill_name" : "����һ��",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��������һ����������$w�������һ����˸����������$n",
        "force" : 200,
        "dodge" : 80,
        "damage" : 65,
        "lvl"    : 80,
        "skill_name" : "����һ��",
        "damage_type" : "����"
]),
([      "action" : "$N����ʹ������֮���塸�ƾ�һ����������$w�����һ������ǵصĿ���$n",
        "force" : 300,
        "dodge" : 90,
        "damage" : 90,
        "lvl"    : 100,
        "skill_name" : "���ƾ�һ����",
        "damage_type" : "����"
]),
([      "action" : HIY"$Nʹ����ɽ����֮���վ���[1;36m������һ����[0m,[1;33m����$w��������һ������$n[0m"NOR,
        "force" : 400,
        "dodge" : 100,
        "damage" : 350,
        "lvl"    : 150,
        "skill_name" : "HIY������һ����"NOR,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("��Ե�����Ϣ�Ļ�򲻹����޷�ѧ����ɽ��������\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������̫�����޷�������ɽ��������\n");
        if ((int)me->query("shen") < 10000)
        	return notify_fail("����ɽ����ʱҪ��ǻ����������ᷴ���亦��\n");
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
	level   = (int) me->query_skill("poshan-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�����������������ɽ��������\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������ɽ��������\n");
        me->receive_damage("qi", 15);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"poshan-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;
    if(me->query("douzhi")<1)
      return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
               if ( (( (int)victim->query("shen") - (int)me->query("shen") ) > 50000) && ( (int)me->query("shen") < 0 )  )
			{
				me->add("douzhi",-30);
				message_vision("$N��Ȼ�������еı�����Ȼ�ܵ��Է�����������������ʹ���ˡ�$N��־�½��ˣ�\n",me);              
				return 1;
			}
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return RED "ֻ��$nһ�������񣬱�$N�ĵ�����Ѫ���ɣ�\n"NOR;
        }
}


