// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
	me->receive_wound("qi", 10);
	me->receive_damage("jingli", 10);
	me->apply_condition("snake_poison", duration - 1);
	tell_object(me, HIG "���е��߶������ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
