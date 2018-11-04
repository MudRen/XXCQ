// ����һ�� shou.c
//Write by godzilla 11,14,99

#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, int a_amount, int d_amount);
int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);
        if(!me->query("lingwu_perform"))
                return notify_fail("�㻹û����������С�\n"); 
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������һ�ߡ�ֻ����ս����ʹ�á�\n");
       	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

    if( (int)me->query("int") < 25 )
		return notify_fail("�����潣�ؼ�����һ�������֡�,�����Բ����޷�ʹ�á�����һ�ߡ�!\n");
	if( (int)me->query("max_neili") < 1000  ) 
		return notify_fail("�������������\n");
	if( (int)me->query_temp("tyqj_shou") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");
	skill = me->query_skill("tianyu-qijian");;
    msg = HIY"$N�ὣһ�أ����纣��һ�ߣ�һ�����ε�����Χ����$N���ܣ�\n��������µ�һ������----"+BLINK+HIR"����һ��"+NOR+HIY+"������\n"NOR;
	message_vision(msg, me, target);
         me->add_temp("apply/parry", 50)
;
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("tyqj_shou", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 50,skill/3 :),20);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/parry", -a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("tyqj_shou");
	message_vision(HIY "$Nһ�����˹���ϣ����ܵĽ���Ҳ����ɢ�ˡ�\n"NOR,me);
}
