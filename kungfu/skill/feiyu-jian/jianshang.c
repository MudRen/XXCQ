// jianshang.c ����

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("[����]ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("�����ϻ�û�н���\n");	
		
        if( (int)me->query_skill("feiyu-jian", 1) < 80 )
		return notify_fail("��ķ��㽣��������죬����ʹ�á����ˡ���\n");
	                        
        if( (int)me->query("neili", 1) < 200 )
		return notify_fail("����������̫��������ʹ�á����ˡ���\n");
		
		if ((int)this_player()->query("eff_qi") == 
                    (int)this_player()->query("max_qi"))
                return notify_fail("�����ںܽ���������Ҫʹ�á����ˡ���\n");	
	
	message_vision(
	HIY "$Nʹ�����㽣���е�һʽ�۽��ˣݣ����ý����Լ����˿��ϻ��˼��£�\n" NOR,
	               me);
	
	me->add("eff_qi", ((int)this_player()->query("max_qi")/10));
	me->add("neili", -200);
    me->add("qi", -((int)this_player()->query("max_qi")/10));
	if( (int)me->query("eff_qi") > (int)me->query("max_qi") ) me->set("eff_qi", (int)me->query("max_qi"));
    return 1;
}

