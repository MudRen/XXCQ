
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) ) {
	message("vision", me->name() + "ʹ���������һ����\n", environment(me), me);
	}
	else {
	tell_object(me, BLU "��Ȼ��е�һ������������е��嶾֮�������ˣ�\n" NOR );
	message("vision", BLU+me->name() + "����ɫͻȻһ��һ����������Ρ�\n" NOR ,
	environment(me), me);
	}
	me->receive_wound("qi",15 + random(10));
	me->receive_wound("jingli", 10);
	me->apply_condition("wudu_poison", duration - 1);
	if ( (int)me->query_temp("powerup") ) {
		me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
		me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
		me->delete_temp("powerup");
	}

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
