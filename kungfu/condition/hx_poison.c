
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
            if( duration < 1 )      return 0;
        if( !living(me) ) {
                message("vision", me->name() + "���������ʹ��غ���һ����\n", environment(me), me);
        }
        else {
                tell_object(me, HIB "��Ȼһ����ʹ����ڤ����˳��ѪҺ������ƽ��ˣ�\n" NOR );
                message("vision", me->name() + "ͻȻ���������ǳ�ʹ������ӡ�\n",environment(me), me);
        }
        me->receive_wound("qi",15 + random(10));
        me->receive_wound("jingli", 10);
        me->apply_condition("hx_poison", duration - 1);
        
        if( duration == 1 )
        {
                tell_object(me, HIB "��ڤ�����Ѿ����������࣡\n" NOR );
                me->die();
              return 0;
        }
       if (!duration) return 0;
       return 1;
}

