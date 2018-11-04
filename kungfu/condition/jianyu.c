// Modified by Find.

#include <condition.h>
#include <login.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->apply_condition("jianyu", duration - 1);
	if( !duration && base_name(environment(me))=="/d/sroom/jianyu")
	{
		message_vision("ֻ���ѵ�һ����$N������ץ���������������˳�ȥ������α������ˣ��ߣ���\n",me);
		me->move("/d/sroom/jianyu_men");
		me->set("startroom",START_ROOM);
		me->delete("no_get_from");
		return 0;
	}
	return CND_CONTINUE;
}
