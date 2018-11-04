// perform: weiwo.c 
// Created by Zeus 1999.6.8
// Modified by Zeus 1999.7.22
// 
// 
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int meneili,meforce,tarneili,tarforce,i;

        me->clean_up_enemy();
        target = me->select_opponent();
        ob = me->query_temp("weapon");

        if( !me->is_fighting() || !living(me) )
                return notify_fail("�������µء�Ω�Ҷ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if( me->query_skill("duzun",1) < 70)
                return notify_fail("��ġ�Ω�Ҷ��𡹵ȼ�����, ����ʹ�á������µء�Ω�Ҷ��𡹣�\n");

        if( me->query("neili") < 50 )
                return notify_fail("��������������޷����á������µء�Ω�Ҷ��𡹣�\n");

        meneili = me->query("neili");
        meforce = me->query_skill("force",1);

        tarneili = target->query("neili");
        tarforce = target->query_skill("force",1);

        me->add_temp("apply/attack",meneili/10);
        target->add_temp("apply/defence",tarneili/10);

        for (i=1;i<=7;i++) {
                if( me->query_skill("duzun",1) >= 95+i*15 && (meneili-50)>0 && me->query("neili")>0 ){
                       msg = MAG "\n$N�����˫�ּ�������ʮ��ҪѨ���������ܼ��ޡ�˫�ֶ���΢΢��ɫ����$n�ĳ�һ��Ũ��\n"NOR;
                       
                       message_vision(msg, me, target);
                       me->add("neili",-50);
                       meneili=meneili-50;
                       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                }
        }

        if(userp(me))
        me->start_busy(3);

        target->apply_condition("duzun_poison", random(me->query_skill("duzun",1)/10) + 1 + target->query_condition("duzun_poison"));
        me->add_temp("apply/attack",-meneili/10);
        target->add_temp("apply/defence",-tarneili/10);

        return 1;

}
