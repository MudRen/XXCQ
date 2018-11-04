// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	int skill;

	skill=me->query_skill("wuxiang-shengong",1);

	if ((int)me->query_skill("wuxiang-shengong", 1) < 60)
		return notify_fail("�����������Ϊ��������\n");

	if (((int)me->query("kill")/1000)<1)
		return notify_fail("���ɱ�����㣬�޷��ˡ���ɱ����߶�־��");

	if ((int)me->query("neili") < 200 || (int)me->query("max_neili") < 300 )
		return notify_fail("�������������\n");

	if (me->query_temp("sha"))
		return notify_fail("��������꡸��ɱ�����ã�������û��̫���Ч����\n");

	message_vision(CYN"\n$N������ʮ�����������˴ȱ�Ϊ�����������ƣ�аħ�����������ɱֹɱ����\n"NOR, me);
	message_vision(HIY"˵����һ��ͷ�����һ������ɱ��ɱ����ɱ����������ʱ���Ƹ������ң����ӷܲ�����\n"NOR, me);

	me->add("douzhi", me->query("kill")/1000);
	me->set_temp("sha",1);
	me->add("neili", -(me->query("kill")/150));

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill/3);

	return 1;
}

void remove_effect(object me)
{
	if ( (int)me->query_temp("sha") ) 
	{
		me->delete_temp("sha");
	}
}
