// �����

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
                                  
      int damage, jiali, attack, defense;
      object weapon;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target) )
           return notify_fail("������ڡ�ֻ����ս���жԶ���ʹ�á�\n");        
      
      if( (int)me->query_skill("dashou-yin",1) < 150 )
           return notify_fail("��Ĵ���ӡ������죬����ʹ�á�����ڡ���\n");
      
      if( (int)me->query_skill("strike",1) < 150 )
           return notify_fail("��Ļ����ַ�������죬����ʹ�á�����ڡ���\n");

      if( (int)me->query_skill("wuxiang-shengong",1) < 120 )
           return notify_fail("��������񹦵ȼ�����������ʹ�á�����ڡ���\n");  
      
      if( (int)me->query_str() < 35 )
           return notify_fail("��ı�������ǿ������ʹ�á�����ڡ���\n");
      
      if( (int)me->query("max_neili") < 1200 )
           return notify_fail("�������̫��������ʹ�á�����ڡ���\n");
      
      if( (int)me->query("neili") < 800 )
           return notify_fail("�������̫���ˣ��޷�ʹ�ó�������ڡ���\n");   
       
      if( (int)target->query_condition("dashouyin"))
           return notify_fail("�Է��������С�����ڡ������ˣ�\n");   
      
      if (objectp(weapon = me->query_temp("weapon")))
           return notify_fail("�㲻��ʹ��������\n");
      jiali = me->query("jiali")+1;
      attack = me->query("combat_exp")/1000;
      attack += me->query_skill("strike",1);
      attack += me->query("neili")/5;
      defense = target->query("combat_exp")/1000;
      defense += target->query_skill("dodge",1);
      defense += target->query("neili")/7;
      attack = (attack+random(attack+1))/2;
      
      damage = me->query_skill("dashou-yin", 1)/40 * jiali;
      if(damage > 1500) damage = 1500;
      
      message_vision(HIR"\n$NͻȻ˫�۹ǽ�һ���죬���������������ƣ�������ɽ��������ھ���$n��ȥ\n����һʽ���š�����ڡ���\n"NOR,me,target);
 
      if( attack > defense ) { 
         message_vision(HIY"ֻ��һ���ƺ�,$n���ؿ�����$Nһ�ƣ�һ����Ѫ��$n�������˳��������ܼ������ˡ�\n"NOR,me, target);
         tell_object(target, RED"��ֻ���û����ؿڹ���һ���ʹ���������˲��壡\n"NOR);
         target->apply_condition("dashouyin", 3);
         target->receive_damage("qi", damage,  me); 
         target->receive_wound("qi", damage/4, me);
         me->add("neili", -jiali);
        }
       else
         {
           message_vision(HIW"$n��������æԾ�����ɣ����ҵĶ����$N����һ��\n"NOR,me, target);
         }
      me->add("neili", -200);
      me->start_busy(1);
      return 1;
}


