// Condition: feixing_poison.c ���ֶ�״̬
// Created by Zeus 1999.4.30
// Modified by Zeus 1999.6.9
// 
// 

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration < 1 ) {
                tell_object(me, GRN "�������ǰ�ľ��ﲻ���������������ϵ�Ҳ������ʹ��\n"+CYN+"���еġ�����֮�����Ѿ��������ˡ�\n" NOR );
                return 0;
        }

        if( !living(me) ) {
                message("vision", me->name() + "���������ʹ��غ���һ����\n", environment(me), me);
        } else {
                tell_object(me, HIB "�������ǰ�ľ������ڻζ���ԭ����վ��վ���ȡ�\n"+RED+"���еġ�����֮���������ˣ�\n" NOR );
                message("vision", HIB + me->name() + "���ӻ�����ȥ���ƺ�վ���ȡ�\n",environment(me), me);
        }

        me->receive_wound("qi", random(75 - me->query_dex()));
        me->receive_wound("jingli", random(75 - me->query_dex()));
        me->start_busy(3);

        me->apply_condition("feixing_poison", duration - 1);

        if ( (int)me->query_temp("powerup") ) {
                me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
                me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
                me->delete_temp("powerup");
        }

        if( duration < 1 ) {
                tell_object(me, GRN "�������ǰ�ľ��ﲻ���������������ϵ�Ҳ������ʹ��\n"+CYN+"���еġ������µء�Ω�Ҷ����Ѿ��������ˡ�\n" NOR );
                return 0;
        }

        return CND_CONTINUE;
}
