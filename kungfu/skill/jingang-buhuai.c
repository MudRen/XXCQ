// jingang.c
// by mulan

#include <ansi.h>
//inherit SKILL;
inherit FORCE;

string *parry_msg = ({
    "$n������̬��Ȼ����Ȼ������һ����Լ�ĵ���ɫ�Ĺ��,��ȫ����ס\n",
    "$nǱ�˽�ղ�����,�������Ĺ�������ȴ�˺��֮�ǡ�\n",
    "$n���������д�,�Է��ı���ֻ���˼�Ƥ�⣬���ܻ����ǡ�\n",
    "$n����һ������,��ȫ��Ѩ����������ס,����ͭǽ����һ�㡣\n",
  });


int valid_enable(string usage) { return usage == "force" || usage=="parry"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("banruo-changong", 1) < 100)
       return notify_fail("��İ���������򲻹����޷�ѧ��ղ�������\n");
    if ((int)me->query("max_neili") < 1000)
       return notify_fail("�������̫�����޷�ѧ����������־�ѧ��\n");
    return 1;
}

int practice_skill(object me)
{
   return notify_fail("��ղ�����������һ��������������ϰ��\n");
}

string query_parry_msg(object weapon,object me,object victim)
{
   return parry_msg[random(sizeof(parry_msg))];
}
 
mixed hit_ob(object me, object victim, int damage_bonus,int factor)
{
   int damage;

   damage = 100 + random((int)me->query_skill("force",1)/2);

   if( !me->query_temp("weapon") && me->query("jiali")
   	&&
      random(me->query_skill("force",1)) > victim->query_skill("force",1)/2 )
   {
      
      victim->receive_damage( "qi", damage * 2 );
      victim->receive_wound( "qi", damage );
      victim->set("neili",victim->query("neili")/2);
      me->add("neili",damage);
      return "$n��$N������Ľ�ղ�����������Ԫ��!\n";
   }
}
