// Exert: heal.c 
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.6.9
// 
// 

#include <ansi.h>

int exert(object me, object target)
{
        if ((int)me->query_skill("zhixin", 1) < 20)
                return notify_fail("��ġ��¹�֪�¡���Ϊ��������\n");
                if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if ( (int)me->query("eff_qi") >= (int)me->query("max_qi"))
                return notify_fail("��û�����ˣ�����Ҫ���ˡ�\n");

        if ((int)me->query("neili") < 50 )
                        return notify_fail("��������������޷����ˡ�\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                        return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);

        message("vision",HIW + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,environment(me), me);

        me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );

        me->add("neili", -50);
        me->set("jiali", 0);

        me->start_busy(1);
        return 1;
}
