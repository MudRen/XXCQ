// Condition: shengdu_poison.c ����״̬
// Created by Zeus 1999.5.11
// Modified by Zeus 1999.6.9
// 
// 

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration < 1 )  {
                tell_object(me, GRN "�������ǰ�ľ��ﲻ���������������ϵ�Ҳ������ʹ��\n"+CYN+"���еġ��������Ѿ��������ˡ�\n" NOR );
                return 0;
        }

        if( !living(me) ) {
                message("vision", RED + me->name() + "������С�������\n"NOR, environment(me), me);
        } else {
                tell_object(me, YEL "��о�����ǰ�����о���ͻȻ������������  �������������������������������š�\n"+RED+"���еġ������������ˡ�\n" NOR );
                message("vision", BLU + me->name() + "������΢΢�Ĳ��������������۾���������ȥ���Ŷ��䡣\n"NOR,environment(me), me);
        }

        me->receive_wound("qi",random(50-me->query_con()));
        me->receive_wound("jingli",random(50 - me->query_con()));

        me->start_busy(3);

        me->apply_condition("shengdu_poison", duration - 1);

        if ( (int)me->query_temp("powerup") ) {
               me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
               me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
               me->delete_temp("powerup");  }

        if( duration < 1 )  {
                tell_object(me, GRN "�������ǰ�ľ��ﲻ���������������ϵ�Ҳ������ʹ��\n"+CYN+"���еġ��������Ѿ��������ˡ�\n" NOR );
                return 0;
        }

        return CND_CONTINUE;
}
