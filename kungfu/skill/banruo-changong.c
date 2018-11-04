// banruo-changong.c ���� ��������
// dts@xkx, cleansword@xkx

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	if ( (int)me->query_skill("buddha", 1) < 200 && (int)me->query_skill("buddha", 1) <= (int)me->query_skill("banruo-changong", 1))
		return notify_fail("��������ķ����򲻹����޷���������İ���������\n");

	if ( (int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�������������\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

void skill_improved(object me)
{
	switch (me->query_skill("banruo-changong",1))
	{
		case 60:
		{
			if (me->query("banruo-changong") < 1)
			{
				message_vision(HIR "$N��ϥ���£�˫�ƺ�ʮ��ͷ���Ѿ�������һƬ���顣\n" NOR, me);
				tell_object(me, HIR "\nͻȻһ����Ϣ�Ե���ܳ��������ֵ�Ұ��ֱ��ٻ��ȥ! \n" NOR);
				tell_object(me, HIR "�������֪�����������������Ѿ����˹ؼ���ʱ���ˣ�\n" NOR);
				tell_object(me, HIR "��Ŭ���Ŀ�������Ϣ������ͼͻ�����еľ��硭��\n\n" NOR);
				me->start_busy(25);
				call_out("over1", 20, me);
				break;
			}
			else break;
		}
		case 120:
		{
			if (me->query("banruo-changong") < 2)
			{
				message_vision(HIR "$N��ϥ���£�˫�ƺ�ʮ��ͷ���Ѿ�������һƬ���顣\n" NOR, me);
				tell_object(me, HIR "\nͻȻһ����Ϣ�Ե���ܳ��������ֵ�Ұ��ֱ��ٻ��ȥ! \n" NOR);
				tell_object(me, HIR "�������֪�����������������Ѿ����˹ؼ���ʱ���ˣ�\n" NOR);
				tell_object(me, HIR "��Ŭ���Ŀ�������Ϣ������ͼͻ�����еľ��硭��\n\n" NOR);
				me->start_busy(25);
				call_out("over2", 20, me);
				break;
			}
			else break;
		}
		case 180:
		{
			if (me->query("banruo-changong") < 3)
			{
				message_vision(HIR "$N��ϥ���£�˫�ƺ�ʮ��ͷ���Ѿ�������һƬ���顣\n" NOR, me);
				tell_object(me, HIR "\nͻȻһ����Ϣ�Ե���ܳ��������ֵ�Ұ��ֱ��ٻ��ȥ! \n" NOR);
				tell_object(me, HIR "�������֪�����������������Ѿ����˹ؼ���ʱ���ˣ�\n" NOR);
				tell_object(me, HIR "��Ŭ���Ŀ�������Ϣ������ͼͻ�����еľ��硭��\n\n" NOR);
				me->start_busy(25);
				call_out("over3", 20, me);
				break;
			}
			else break;
		}
	}
	return;
}

string exert_function_file(string func)
{
	return __DIR__"banruo-changong/" + func;
}

int over1(object me)
{
	if (random(100) < (90 * me->query("con") / 30))
	{
		tell_object(me, HIY "\n���˹��࿹���ã�ͻȻһ�������Ի��ĳ�ٻὫ�Ҵܵ���������������\n" NOR);
		tell_object(me, HIY "��е���һ��ǰ��δ�е��泩��һʱ���������������ľ��硭��\n\n" NOR);
		tell_object(me, HIG "��ϲ�㣡��İ��������Ѿ��ﵽ��С�����񹦵ľ��磡����\n" NOR);
		message_vision(HIG "$N������һ������վ�������������ظ���\n" NOR, me);
		me->add("max_neili",25);
		me->set("banruo-changong",1);
		return 1;
	}
	else
	{
		tell_object(me, HIB "\n���Ŭ��û��һ��Ч�����Ҵܵ�����������澭����������ʱ�е���ʹ�ƽ���\n" NOR);
		tell_object(me, HIB "��û��ͻ�ư��������Ĺؼ�����ʧ���ˣ�\n" NOR);
		tell_object(me, HIM "��İ������������½��ˣ�����\n\n" NOR);
		me->set_skill("banruo-changong",(int)me->query_skill("banruo-changong", 1) - 1);
		return 1;
	}
}

int over2(object me)
{
	if (random(100) < (75 * me->query("con") / 30))
	{
		tell_object(me, HIY "\n���˹��࿹���ã�ͻȻһ�������Ի��ĳ�ٻὫ�Ҵܵ���������������\n" NOR);
		tell_object(me, HIY "��е���һ��ǰ��δ�е��泩��һʱ���������������ľ��硭��\n\n" NOR);
		tell_object(me, HIG "��ϲ�㣡��İ��������Ѿ��ﵽ�˴�����񹦵ľ��磡����\n" NOR);
		message_vision(HIG "$N������һ������վ�������������ظ���\n" NOR, me);
		me->add("max_neili",25);
		me->set("banruo-changong",2);
		return 1;
	}
	else
	{
		tell_object(me, HIB "\n���Ŭ��û��һ��Ч�����Ҵܵ�����������澭����������ʱ�е���ʹ�ƽ���\n" NOR);
		tell_object(me, HIB "��û��ͻ�ư��������Ĺؼ�����ʧ���ˣ�\n" NOR);
		tell_object(me, HIM "��İ������������½��ˣ�����\n\n" NOR);
		me->set_skill("banruo-changong",(int)me->query_skill("banruo-changong", 1) - 1);
		return 1;
	}
}

int over3(object me)
{
	if (random(100) < (60 * me->query("con") / 30))
	{
		tell_object(me, HIY "\n���˹��࿹���ã�ͻȻһ�������Ի��ĳ�ٻὫ�Ҵܵ���������������\n" NOR);
		tell_object(me, HIY "��е���һ��ǰ��δ�е��泩��һʱ���������������ľ��硭��\n\n" NOR);
		tell_object(me, HIG "��ϲ�㣡��İ��������Ѿ��ﵽ����������񹦵ľ��磡����\n" NOR);
		message_vision(HIG "$N������һ������վ�������������ظ���\n" NOR, me);
		me->add("max_neili", 25);
		me->add("con", 1);
		me->set("banruo-changong",3);
		return 1;
	}
	else
	{
		tell_object(me, HIB "\n���Ŭ��û��һ��Ч�����Ҵܵ�����������澭����������ʱ�е���ʹ�ƽ���\n" NOR);
		tell_object(me, HIB "��û��ͻ�ư��������Ĺؼ�����ʧ���ˣ�\n" NOR);
		tell_object(me, HIM "��İ������������½��ˣ�����\n\n" NOR);
		me->set_skill("banruo-changong",(int)me->query_skill("banruo-changong", 1) - 1);
		return 1;
	}
}