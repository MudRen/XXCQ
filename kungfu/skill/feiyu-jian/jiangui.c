// jiangui.c
// from huanying.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
       object weapon;
       
    if( !target ) target = offensive_target(me);
 
       if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
          return notify_fail("��ʹ�õ���������,����ʹ��[����]��\n");

      if( !target || !me->is_fighting(target) )
      return notify_fail("������ֻ����ս���жԶ���ʹ�á�\n");

    if((int)me->query_skill("tianlongforce", 1) < 100 )
    
		return notify_fail("��Ľ���������������ң����ܺ���[����]��\n");       
    
	if (me->query_skill_mapped("force") != "tianlongforce")
    
				return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
    
	if ((int)me->query_skill("feiyu-jian", 1) < 120 )
    
		return notify_fail("��ķ��㽣���ȼ����������ܺ���[����]��\n");    
   
    if ( me->query_skill_mapped("sword") != "feiyu-jian"
        
		|| me->query_skill_mapped("dodge") != "fish-steps")
        
				return notify_fail("����������β�������Ϸ��㽣��,����ʹ��[����]��\n"); 
    
	if ((int)me->query("neili") < 360 )
           
		return notify_fail("�������������㣬���ܺ���[����]��\n");
       
	if ((int)me->query("max_neili") < 720 )
    
		return notify_fail("�������̫�������ܺ���[����]��\n");
    
	if ( (int)me->query_temp("ghost", 1) ) 
    
		return notify_fail("���Ѿ�ʹ����[����]�ˣ�\n");
    
    message_vision(HIY"$N����"+(string)weapon->query("name")+HIY"ԽʹԽ�죬ͻȻ���������г������������Ρ�������һʽ[����]!\n"NOR+
	               HIY"$n�������Ի󣬷ֲ����ĸ����棬�ĸ��Ǽ١�\n"NOR, me, target);
  
              target->start_busy(2+random(4));
    me->add("neili", -(int)me->query_skill("feiyu-jian", 1) *3);    
    me->set_temp("ghost", 1);
    call_out("gone",7);
    return 1;
}

int gone()
{
    object me=this_player();
    message_vision("�Ǹ�"HIY"����"NOR"��$N���Ի��˻Σ���ͻȻ��ʧ����Ӱ���٣�\n", me);
    me->delete_temp("ghost");
    return 1;
}
