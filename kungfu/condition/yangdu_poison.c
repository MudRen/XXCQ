// yangdu_poison.c ��
// designed by lks


#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;
        if( !living(me) ) {
               message_vision("$N���������ʹ��غ���һ����\n", me);
        }
        else {
                tell_object(me, YEL "��Ȼ������֫���������е��������ˣ�\n" NOR );
               message_vision("$N����ɫͻȻ�Ұף�������ֳ�һ�㰵��ɫ���ÿֲ�Ŷ��\n"NOR, me);
        }
        me->receive_wound("qi",35 + random(10));
        me->receive_wound("jingli", 50);
        me->apply_condition("yangdu_poison", duration - 1);
        
       if( duration < 1 ) return 0;
       return CND_CONTINUE;
}
