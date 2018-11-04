// Condition: xiangshi_poison.c ��ʶ������״̬
// Created by Zeus 1999.4.30
// Modified by Zeus 1999.4.30
// 
// 

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;
        if( !living(me) ) {
                message("vision", me->name() + "���������ʹ��غ���һ����\n", environment(me), me);
        }
        else {
                tell_object(me, HIB "��Ȼ����ȫ��Ƥ������۷��һ��ʹ������ͻȻ�������ѣ����е���ʶ�����з����ˣ�\n" NOR );
                message("vision", me->name() + "������ͻȻ�������Σ����ظ�������������\n",environment(me), me);
        }
        me->receive_wound("qi",30 + random(10));
        me->receive_wound("jing", 10);
        me->apply_condition("xiangshi_poison", duration - 1);
        if ( (int)me->query_temp("powerup") ) 
           { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
	     me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
	     me->delete_temp("powerup");  }

       if( duration < 1 ) return 0;
       return CND_CONTINUE;
}
