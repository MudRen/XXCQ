    //zhizhu_du
    //god
#include <ansi.h>
#include <login.h>

    int update_condition(object me, int duration)
    {
             object where=environment(this_player());
              object *obb;
              int i;
             if( duration < 1 )
             return 0;
            if( !living(me) ) {
                    message("vision", me->query("name") + "���������ʹ�༫�ˡ�\n", environment(me), me);
            }
            else {
                    tell_object(me, HIR "��Ȼһ���ʹ������ȫ���������̣�\n" NOR );
                    message("vision", me->name() + "ͻȻ�������ʹ����������Ҫ����\n",environment(me), me);
                obb=all_inventory(where);
            for(i=0; i<sizeof(obb); i++) {
            if (obb[i]->is_character() )
          {
            if (obb[i]==me)  continue;
            me->kill_ob(obb[i]);
         }
            }
            }
            me->receive_wound("qi",35 + random(30));
            me->receive_wound("jingli", 20);
            me->apply_condition("xisui_du", duration - 1);
            
            if( duration == 1 )
            {
                    tell_object(me, HIR "��ȫ�������ˣ�\n" NOR );
                    me->die();
                  return 0;
            }
             if (!duration) return 0;
           return 1;
    }

