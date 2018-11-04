// zuida.c ������� [�������]

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount1);

int perform(object me)
{
	object weapon, target;
  	string msg;
	int count1, cnt, skill,ap ,dp;
	
	me->clean_up_enemy();
	target = me->select_opponent();

	if( !me->is_fighting() )
	    return notify_fail("���������ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_temp("zuida") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	if( (int)me->query_str() < 25 )
		return notify_fail("��ı���������Ŀǰ����ʹ�ô˾���! \n");

	if( me->query_skill_mapped("force") != "banruo-changong"
		&& me->query_skill_mapped("force") != "wuxiang-shengong") 
		return notify_fail("��û�м��������ڹ����޷�ʹ�á��������¡���\n");
	if( (int)me->query_skill("force") < 100)
		return notify_fail("��������ڹ���Ϊ����������ʹ�á��������¡���\n");

	if( (int)me->query_skill("club") < 120)
		return notify_fail("��Ĺ�����Ϊ����������ʹ�á��������¡�! \n");

	if( (int)me->query("neili") < 300 ||(int)me->query("max_neili") < 500 )
		return notify_fail("����������㣡\n");
	
	msg = HIY "ͻȻ$N����һ�䡸�������¡���˫Ŀ��죬���¼������ĺ��Ϻ��º�����ң�����ø��Ӳ���׽����\n" NOR;
	
   	message_vision(msg, me, target);
	skill = me->query_skill("zui-gun",1);
	cnt =(int)( (int)me->query_condition("drunk") / 30 );
	count1 = me->query("dex") * cnt;

	me->add_temp("dex", count1);
	me->set_temp("zuida", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count1 :), skill /6 );

	me->add("neili", -150);

	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp)
	{
		msg = HIW "$nֻ���Լ���ǰ�����$N��Ӱ�ӣ���Ȼ��֪��������������ˡ�\n" NOR;
		message_vision(msg, me, target);
		target->start_busy( 1 + (int)me->query_condition("drunk") / 30);
		me->add("neili", -150);
	}
	else
	{
		msg = HIC "$n��æԾ��һ������ϸ�۲�$N�Ĳ���������û�б�������æ���ҡ�\n" NOR;
		message_vision(msg, me, target);
	}
   	return 1;
}

void remove_effect(object me, int amount1)
{
	if ( (int)me->query_temp("zuida") ) 
	{
		me->add_temp("dex", -amount1);
		me->delete_temp("zuida");
		message_vision(HIY "$N��̬һ�գ�����Ҳ�ָ���������\n" NOR,me);
		me->start_busy(3);
	}
}