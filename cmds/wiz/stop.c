// stop.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !me->is_fighting() )
		return notify_fail("�����ڲ�û����ս����\n");
	me->remove_all_killer();
	message_vision("$N����ʦ������ֹͣ���ⳡ�򶷡�\n", me);
	return 1;
}

int help(object me)
{
   write(@HELP
ָ���ʽ: stop

����ֹͣ��������(��)�йص�ս����
HELP
   );
   return 1;
}
