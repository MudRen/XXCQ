
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        int neili_limit;
        
        neili_limit=(int)me->query_skill("force",1)*(int)me->query("con")+1;
        
        if ((int)me->query("max_neili")>neili_limit)
        {
                me->set("max_neili",neili_limit);
                tell_object(me, "���������Ϊ�Ѿ��ﵽ��ƿ����\n" NOR );              
        }
        else {
                me->set("max_neili",(int)me->query("max_neili")+(int)me->query_temp("neili_save")); 
                tell_object(me, "�������Ϣ�ֱ���ǰ���˽���������ȫ����ʹ���̣�\n" NOR );
        }
        message("vision", me->name() + "��ɫ���粻�������ǵ���ʲô������\n",environment(me), me);

        me->apply_condition("bairi_du", duration - 1);
        
        if( duration == 1 )
        {
                tell_object(me, HIB "��ҩ�����ڱ����ˣ����Ѿ��������ģ�\n" NOR );
              me->set("max_neili",(int)me->query_temp("neili_save"));
                me->die();
        }
       if (!duration) return 0;
       return 1;
}

