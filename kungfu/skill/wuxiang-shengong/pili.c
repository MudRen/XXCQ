// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	int skill, count, d_count;

	count = me->query_str();
	d_count = me->query_dex();

	skill=me->query_skill("wuxiang-shengong",1);

	if ((int)me->query_skill("wuxiang-shengong", 1) < 120)
		return notify_fail("�����������Ϊ��������\n");

	if ((int)me->query("neili") < 500 || (int)me->query("max_neili") < 1000 )
		return notify_fail("�������������\n");

	if (me->query_temp("leiting"))
		return notify_fail("���Ѿ����ˡ�������������\n");

	message_vision(HIW"\n$N����һ������Ĭ�ˡ�������������ȫ��Ĺǽڡ�žž�����죬ɮ�º��ƴ󺣰�Ĺ��ڣ���Ծ�����ᡢ���ۡ����䡣\n"NOR, me);
	message_vision(HIY"��ʱ$N�������鶯�˲��٣����Ƹ�����������࣬������Щ�����мܡ�\n"NOR, me);

	me->add_temp("str", count * 3);	
	me->add_temp("dex", d_count);
	me->add("neili", -500);
	me->set_temp("leiting",1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*3, d_count :), skill/6);

	return 1;
}

void remove_effect(object me, int aamount, int damount)
{
	if ( (int)me->query_temp("leiting") ) 
	{
		me->add_temp("str", -aamount);
		me->add_temp("dex", -damount);
		me->delete_temp("leiting");
		tell_object(me, HIY "��ġ�����������������ϣ��������ջص��\n" NOR);
		me->start_busy(random(4));
	}
}
