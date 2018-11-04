// perform: feixing.c ����֮��
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.6.8
// 
// 
 
#include <ansi.h>
 
inherit F_SSERVER;

string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
        if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
        if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
        if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
        if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
        if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

varargs void report_status(object ob)
{
        message_vision( "( $N" + status_msg(
                (int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
                + " )\n", ob);
}

int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int objxiandex,objdex,objdodge;
        int myxiancon,mycon,myforce;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( !me->is_fighting() || !living(me) )
                return notify_fail("������֮����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("������֮��������ͽ��ʹ�á�\n");

        if( me->query_skill("duzi-du") < 100)
                return notify_fail("��ġ����ֶ����ȼ�����, ����ʹ�á�����֮������\n");

        if( me->query("neili") < 200 )
                return notify_fail("��������������޷����á�����֮������\n");
 
        objxiandex=target->query("dex");
        objdex=target->query_dex();
        objdodge=target->query_skill("dodge",1);

        myxiancon=me->query("con");
        mycon=me->query_con();
        myforce=target->query_skill("force",1);

        msg = HIC "\n$N�������ʳָ����ǰд��һ�����ġ������֣�Ȼ��˫��һ��ǡ������־�Ȼ��$p��ȥ��\n"NOR;
        message_vision(msg, me, target);

        if ( objxiandex <= 20 && me->query("neili")>50 ) { 
                msg = HIB "$nŬ��������һ�����ǡ������ֵ�һ�ǻ���������$n��$n����ɫѸ�ٱ�ڣ�\n"NOR;
                message_vision(msg, me, target);
                me->add("neili",-50);
                target->add("qi",-objxiandex*myxiancon);
                target->add("eff_qi",-objxiandex*myxiancon);
                target->apply_condition("feixing_poison", random(me->query_skill("duzi-du")/10) + 1 + me->query_condition("feixing_poison"));
                report_status(target);

                if ( objdex <=30 && me->query("neili")>50 ) {
                        msg = HIM "���ţ�$n�������һ�����ǡ������־�Ȼ����$n�ɹ�������������������ǰ��\n"NOR;
                        message_vision(msg, me, target);
                        me->add("neili",-50);
                        target->add("qi",-objdex*mycon);
                        target->add("eff_qi",-objdex*mycon);
                        target->apply_condition("feixing_poison", random(me->query_skill("duzi-du")/10) + 1 + me->query_condition("feixing_poison"));
                        report_status(target);

                        if ( objdodge <= 150 && me->query("neili")>50 ) {
                                msg = RED "���$nŬ��������һ�����ǡ������־�Ȼ��ȫ����$n�����ϡ�\n"NOR;
                                message_vision(msg, me, target);
                                me->add("neili",-50);
                                target->add("qi",-objdodge*myforce/10);
                                target->add("eff_qi",-objdodge*myforce/10);
                                target->apply_condition("feixing_poison", random(me->query_skill("duzi-du")/10) + 1 + me->query_condition("feixing_poison"));
                                report_status(target);
                        }
                }
        }
        else {
                msg = GRN "$n����һԾ���������ǡ������ֵķ���·�ߣ����ɵ�����һ�ԡ�\n\n"NOR;
                message_vision(msg, me, target);
                me->start_busy(random(6));
                me->add("neili",-50);
        }

        return 1;

}
