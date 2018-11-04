// tui.c	5�ν�����������һ��	by winder

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	// ��ν����ı������弰��ֵ����ʼ������ս��λ�á�
	object target;
	int m_dis, no, distance;

	if( !( me->is_fighting() ) )
		return notify_fail("��û��ս��������Ҫ�˷���\n");

	if( me->query_temp("guarding") )
		return notify_fail("��Ŀ��ת���ض����Է��Ķ�����������һ˿������\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if( me->query_temp("tui") ) 
		return notify_fail("��ո��˹��ˡ�\n");

	if( me->query_temp("shang") ) 
		return notify_fail("��ո������ˡ�\n");

	me->clean_up_enemy();
	target = me->select_opponent();

	if ( !environment(me)->query("length") || environment(me)->query("length") <= 0 )
		if ( !environment(me)->query("piazza") )
			if ( !environment(me)->query("outdoors") )
				distance = 5;
			else
				distance = 7;
		else
			distance = 11;
	else
	{
		distance = environment(me)->query("length");
		if ( distance >= 20 )
			distance = 19;
		else	if ( intp(distance/2) )
				distance -= 1;
	}

	m_dis = me->query_temp("dis");

	if( !arg || arg == "1" )
		no = 1;
	else	if( arg == "2" )
			no = 2;
		else	if( arg == "3" )
				no = 3;
			else	if( arg == "4" )
					no = 4;
				else	return notify_fail("��Ҫ�˺󼸲���\n");

	if( ( distance - m_dis ) < no )
		return notify_fail("�����ľ��벻���ˡ�\n");

	if ( !arg || arg == "1" )
	{
		m_dis += 1;
		message_vision(HIR"\n$NͻȻ���һ�У������һ����\n"NOR, me);
	}
	else	if ( arg =="2" && random(10)>=2 )
		{
			m_dis += 2;
			message_vision(HIR"\n$NͻȻ���һ�У������������\n"NOR, me);
		}
		else	if ( arg =="3" && random(10)>=4 )
			{
				m_dis += 3;
				message_vision(HIR"\n$NͻȻ���һ�У������������\n"NOR, me);
			}
			else	if ( arg =="4" && random(10)>=6 )
				{
					m_dis += 4;
					message_vision(HIR"\n$NͻȻ���һ�У�������Ĳ���\n"NOR, me);
				}
				else
					message_vision(HIR"\n$NͻȻ���һ�У��������������������$n����������$Næ���м��޷��óѡ�\n"NOR, me, target);

	me->set_temp("dis", m_dis);
	me->start_busy(1);
	me->set_temp("tui",1);

	call_out("effect_tui", random(4), me);

	return 1;
}

int effect_tui(object me)
{
	me->delete_temp("tui");
	return 1;
}