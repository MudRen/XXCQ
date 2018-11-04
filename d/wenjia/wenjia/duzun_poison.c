// Condition: duzun_poison.c Ω�Ҷ���״̬
// Created by Zeus 1999.5.11
// Modified by Zeus 1999.6.9
// 
// 

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        if( duration < 1 ) {
                tell_object(me, GRN "�������ǰ�ľ��ﲻ���������������ϵ�Ҳ������ʹ��\n"+CYN+"���еġ������µء�Ω�Ҷ����Ѿ��������ˡ�\n" NOR );
                return 0;
        }

        if( !living(me) )  message("vision", RED+me->name() + "������ҳ鴤��������һ�����¡�\n"NOR, environment(me), me);

        if(duration > 50 ) {
                tell_object(me, WHT "��о�����ǰ��ò԰�һƬ��"+HIB+"ȫ��Ƥ��ȴ����ںڲ�����ʹ�ý���ס���鴤������\n"+RED+"���еġ������µء�Ω�Ҷ��𡹷����ˡ�\n" NOR );
                message("vision",  HIB + me->name() + "��ȫ�����ںڣ����Ӿ��ҳ鴤��\n"NOR, environment(me), me);
                me->receive_wound("qi",100-me->query_con());
                me->receive_wound("jingli",200-me->query_con());
                me->start_busy(4);
        } else if (duration >30 ) {
                tell_object(me, CYN "��о�����ǰ�������һƬ��"+HIB+"ȫ��Ƥ��ȴ��û��ײ�����ʹ�ý���ס���鴤������\n"+RED+"���еġ������µء�Ω�Ҷ��𡹷����ˡ�\n" NOR );
                message("vision",  HIB + me->name() + "��ȫ���û��ף����Ӿ��ҳ鴤��\n"NOR, environment(me), me);
                me->receive_wound("qi",75-me->query_con());
                me->receive_wound("jingli",150-me->query_con());
                me->start_busy(3);
        } else if (duration >10 ) {
                tell_object(me, HIW "��о�����ǰ���ģ��һƬ��"+MAG+"ȫ��Ƥ��ȴ������ಢ����ʹ�ý���ס���鴤������\n"+RED+"���еġ������µء�Ω�Ҷ��𡹷����ˡ�\n" NOR );
                message("vision",  MAG + me->name() + "��ȫ�������࣬���Ӿ��ҳ鴤��\n"NOR, environment(me), me);
                me->receive_wound("qi",50-me->query_con());
                me->receive_wound("jingli",100-me->query_con());
                me->start_busy(2);
        } else {
                tell_object(me, YEL "��о�����ǰ����ζ���ȫ����ʹ�ý���ס���鴤������\n"+RED+"���еġ������µء�Ω�Ҷ��𡹷����ˡ�\n" NOR );
                message("vision",  BLK + me->name() + "�����Ӿ��ҳ鴤��\n"NOR, environment(me), me);
                me->receive_wound("qi",15 + random(10));
                me->receive_wound("jingli",10);
                me->start_busy(1);
        }

        me->apply_condition("duzun_poison", duration - 1);

        if ( (int)me->query_temp("powerup") ) {
               me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
               me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
               me->delete_temp("powerup");  }

        if( duration < 1 ) {
                tell_object(me, GRN "�������ǰ�ľ��ﲻ���������������ϵ�Ҳ������ʹ��\n"+CYN+"���еġ������µء�Ω�Ҷ����Ѿ��������ˡ�\n" NOR );
                return 0;
        }

        return CND_CONTINUE;
}
