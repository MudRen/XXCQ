// heal.c

#include <ansi.h>

int exert(object me, object target)
{
           int damage,time;
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if ((int)me->query_skill("yiqiguan-riyue", 1) < 15)
                return notify_fail("���һ����������Ϊ��������\n");
        if( (int)me->query("neili") < 50  || (int)me->query("max_neili") < 50 )
                return notify_fail("�������������\n");

              if(me->query("eff_qi")>=me->query("max_qi"))
                     return notify_fail("�㲻��Ҫ���ˡ�\n");
        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        if (me->query("yiqiguan-riyue")==1) {
        write( HIG "�����𡰴����������񹦣�����һ���࣬һ��ס�\n" NOR);
        damage=10 + (int)me->query_skill("force")/4;
        time=3;
        }
        if (me->query("yiqiguan-riyue")==2) {
        write( WHT "�����𡰵Ƿ��켫���񹦣�ȫ������һ�Ű���\n" NOR);
        damage=10 + (int)me->query_skill("force")/3;
        time=2;
        }
        if (!(me->query("yiqiguan-riyue"))) {
        write( YEL "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
        damage=10 + (int)me->query_skill("force")/5;
        time=4;
        }

        message("vision",
                HIW + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
                environment(me), me);
        me->receive_curing("qi",damage);
        me->add("neili", -50);
        me->set("jiali", 0);
      me->start_busy(time);

        return 1;
}


