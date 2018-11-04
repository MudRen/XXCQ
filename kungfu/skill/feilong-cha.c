     // feilong-cha.c -�����淨

#include <ansi.h>
inherit SKILL;

mapping *action = ({
  ([      "action" : "$N�ս�����$wһ�С�ҹ��̽��������$n��$l",
        "force" : 50,
        "dodge" : 40,
          "damage" : 60,
        "lvl"    : 0,
         "skill_name" : "ҹ��̽��", 
           "damage_type" : "����"
]),
  ([      "action" : "$N��ǰ����һ��������$wʹ���������㾦������$n�ĺ�",
        "force" : 90,
        "dodge" : 80,
      "damage" : 50,
        "lvl"    : 20,
         "skill_name" : "�����㾦",
           "damage_type" : "����"
]),
      ([      "action" : "ֻ��$N�������е�$w��ʹ����������ˮ�����������$n",
        "force" : 90,
        "dodge" : 70,
            "damage" : 90,
        "lvl"    : 40,
       "skill_name" : "������ˮ",
           "damage_type" : "����"
]),
  ([      "action" : "$Nʹ�������������������$w�������һ����˸����,����$n",
        "force" : 200,
        "dodge" : 80,
         "damage" : 105,
        "lvl"    : 80,
          "skill_name" : "�������",
          "damage_type" : "����"
]),
         ([      "action" : "$N����ʹ���淨֮���塸Ǳ�����졹������һ$w����$n",
        "force" : 300,
        "dodge" : 90,
                 "damage" : 110,
        "lvl"    : 100,
        "skill_name" : "��Ǳ�����졹",
          "damage_type" : "����"
]),
             ([      "action" : "$N����һ������ʹ���淨֮���С������ĺ������е�$w�緢ŭ�Ľ������� $n�� \n",
        "force" : 400,
        "dodge" : 100,
        "damage" : 350,
        "lvl"    : 150,
          "skill_name" : "HIY�������ĺ���"NOR,
             "damage_type" : "����"
]),
});


           int valid_enable(string usage) { return (usage == "fork") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 100)
                  return notify_fail("��Ե�����Ϣ�Ļ�򲻹����޷�ѧ�������淨����\n");
        if ((int)me->query("max_neili") < 300)
               return notify_fail("�������̫�����޷����������淨����\n");
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
     level   = (int) me->query_skill("feilong-cha",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "fork")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
               return notify_fail("��������������������淨����\n");
        if ((int)me->query("neili") < 50)
                 return notify_fail("��������������������淨����\n");
        me->receive_damage("qi", 15);
        return 1;
}
string perform_action_file(string action)
{
              return __DIR__"feilong-cha/" + action;
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
                  return RED "ֻ��$nһ�������񣬱�$N��$w�̵�Ѫ��ģ����\n"NOR;
        }
}


