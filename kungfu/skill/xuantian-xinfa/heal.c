// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if (me->is_busy())
                return notify_fail("����æ�������£���ô���ˣ�\n");

        if ((int)me->query_skill("jiuqu-xinfa", 1) < 25)
                return notify_fail("���������Ϊ��������\n");
        if( (int)me->query("neili") < 50 ) 
                return notify_fail("�������������\n");
        if ((int)me->query("eff_qi") > ((int)me->query("max_qi")-1))
                return notify_fail("�㲻��Ҫ���ˡ�\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("��ľ������𣬸����޷�����������������\n");

        write( HIW "����ϥ������������������������Ѩ����ͬʱ�������ķ���ͼ��ͨ����ľ�����\n" NOR);
        write( HIW "ͻȻһ������ͻ������Ѩ����ֱ����ͥ����е�һ��ů���ڵĸо�������Ҳ������ࡣ\n" NOR);
        message("vision",
                HIM + me->name() + "��ϥ������������������������Ѩ�������˰����㹦����ɫ�������ƺ�����Щ��\n" NOR,
                environment(me), me);

        me->receive_curing("qi", 10 + (int)me->query_skill("force")/4 );
        me->add("neili", -50);
        me->set("jiali", 0);

        return 1;
}
