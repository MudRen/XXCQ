// halt.c
// By netkill@cctx 98-9-13

#include <ansi.h>

int main(object me, string arg)
{
	if (me->is_fighting()) {
		me->remove_all_enemy();
		message_vision("$N�������һԾ������սȦ�����ˡ�\n", me); 
		if(me->query_temp("biwu")) 
		shout(WHT"���������š�"+me->name()+"��;�������䣡\n" NOR);
	}
	else if (!me->is_busy()) 
		return notify_fail("�����ڲ�æ��\n");
	else if ((int)me->query_temp("pending/exercise") != 0) {
		message_vision("$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
		me->interrupt_me();
	}
	else if ((int)me->query_temp("pending/respirate") != 0){
		message_vision("$N��������̨�����е�����֮�������³�������վ��������\n", me);
		me->interrupt_me();
	}
	me->interrupt_me();

	return 1;
}
	
