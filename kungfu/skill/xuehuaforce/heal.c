// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("������ս���������˹����ˣ�\n");

        if (me->is_busy())
                return notify_fail("����æ�������£���ô���ˣ�\n");

        if ((int)me->query_skill("xuehuaforce", 1) < 30)
                return notify_fail("��Ľ����������Ϊ���������������Լ������ˡ�\n");
        if( (int)me->query("neili") < 50 ) 
                return notify_fail("�������������\n");
        if ((int)me->query("eff_qi") > ((int)me->query("max_qi")-1))
                return notify_fail("�㲻��Ҫ���ˡ�\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
                return notify_fail("������̫�أ��޷��Լ�������������ȫ�������ˣ�\n");

        write( HIW "����������������죬�ˡ�ѩ���ķ�������Ů������\n" NOR);
        message("vision",
                HIY + me->name() + "��ϥ������Ĭ���񹦣�ͻȻ��Хһ�������������ɫ�������ƺ�������ࡣ\n" NOR,
                environment(me), me);

        me->receive_curing("qi", 20 + (int)me->query_skill("force")/5 );
        me->add("neili", -40);
        me->set("jiali", 0);

        return 1;
}

