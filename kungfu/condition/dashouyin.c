//update by phoenix
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
      if( duration < 1 )
      return 0;
      tell_object(me, HIR"ͻȻ��о��ؿ���ʹ�쳣���ղű�����ڴ��е��߹Ǵ�����Ҫ�ѿ����Ƶģ���ѪҲ�ӿ������˳�����\n"NOR);
      tell_room(environment(me), HIR + me->name()+"ͻȻ�۵�һ���³�����Ѫ��,�����������˲��ᣡ\n" NOR,({ me }));
      me->receive_damage("qi", 300);
      me->receive_wound("qi", 100);
      me->apply_condition("dashouyin", duration - 1);
      if( duration == 1 )
        {
            if( 2 >=random(8))
           {
              me->unconcious();
              return 0;
           }
        }
   return CND_CONTINUE;
} 

