// kuai.c �����羪�硹
// Write by godzilla 1999.11.5

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, num;

	if( !target ) target = offensive_target(me);
        if(!me->query("lingwu_perform"))
                return notify_fail("�㻹û����������С�\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����羪�硹ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 1000 )
                return notify_fail("�������������㣬ʹ���������羪�硹��\n");     	
    if( (int)me->query("int")<25)
	         return notify_fail("�����潣�ؼ�����һ�����򡱣����Բ����޷��á����羪�硹��\n");	
        if( me->query_temp("tianyu_qijian") )
                return notify_fail("���ʹ�꡸�����潣���ľ��У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
                
    msg = HIY"���ɣ����棬��������е�һ�����磬$Nһ����$n�̳���"+HIM+chinese_number((int)me->query_int()/10)+HIY"����\n��������µ�һ�Ŀ��С�"+BLINK+HIR+"���羪��"+NOR+HIY+"������\n"NOR;

	if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/20)
	{
		num = (int)me->query_int() / 10;
		msg += WHT"��δ�������ȵ�,$p��$P���˸����ֲ������������˲�Ͼ��\n" NOR;
		message_vision(msg, me, target);
		for(i = 0; i < num; i++)
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("tianyu_qijian",1);
		me->add("neili", -100);
		me->start_busy(1);
		call_out("remove_effect", (int)me->query_int()/2, me);
	}
	else
	{
		msg += WHT"����죬����$p�ϵ��Ȼ������ȷɳ����⣬ʹ$P�޷��̵���\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2);
	}
	
	return 1;
}
void remove_effect(object me)
{
        if (!me)
        return;
        me->delete_temp("tianyu_qijian");
        tell_object(me, HIR"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á������潣���ľ����ˡ�\n"NOR); 
}
