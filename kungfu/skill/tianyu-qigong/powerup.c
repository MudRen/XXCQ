// powerup.c


#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

int exert(object me, object target)
{
	
	if( target != me )
        return notify_fail("��ֻ�ܶ��Լ���Ч��\n");
        if( (int)me->query("neili") < 1000  )
        return notify_fail("�������������\n");
        if((int)me->query("max_neili") < 1500  )
        return notify_fail("�������������\n");
        if( me->query_skill("tianyu-qigong",1)<180)
        return notify_fail("�������湦�������죬�����þŻ����յľ��С�\n");
        if( (int)me->query_temp("powerup") )
        return notify_fail("���Ѿ����˹����ˡ�\n");
        if(me->query("family/family_name")!="������")
        return notify_fail("�㲻��ʹ�þŻ����ա�\n");
        if(me->is_fighting())
        {
        	me->add("neili", -300);
                message_vision(HIR "$N΢һ��������Ż����յ�������һ����������ȫ��\n" NOR, me);
               me->add_temp("str", 10);
                me->set_temp("powerup", 1);
                me->add_temp("num", 1);
                remove_call_out("number_2");
                call_out("number_2",6,me);
                return 1;
        }
        else
        {
        	return notify_fail("�Ż�����ֻ����ս����ʹ�á�\n");
        }	
       
}
int number_2()
{
	object me=this_player();
	int i=(int)me->query_temp("num");
	if(i>9)
	{
		remove_call_out("end_powerup");        
        	call_out("end_powerup",1,me,i);
        	return 1;
        }	
        if(me->is_fighting())
        {
        	message_vision(HIR "ֻ��$Nȫ�����žž���죬��"HIC+chinese_number((int)me->query_temp("num"))+HIR"���Ż����յ���������ɽ������������ӿ�˹�ȥ��\n" NOR, me);
               me->add_temp("str", 10);
        	me->add_temp("num", 1);
	        call_out("number_2",6,me);
	        return 1;
	 }
	 else
	 {
	    
        	call_out("end_powerup",1,me,i);
        	return 1;
         }	       
}
void end_powerup(object me,int i)
{
    int m=i*10;	
              me->add_temp("str", -m);
    me->delete_temp("num");
    me->delete_temp("powerup");
    tell_object(me, HIR"��������湦--�Ż�����������ϣ������Ľ������ջص��\n"NOR);
}

