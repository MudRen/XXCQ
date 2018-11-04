// perform: wusheng.c 
// Created by Zeus 1999.5.11
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
        int meneili,meforce,tarneili,tarforce,qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();
        ob = me->query_temp("weapon");

        if( !me->is_fighting() || !living(me) )
                return notify_fail("������֮����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (!present("gubo", me))
                return notify_fail("������֮���������й������ʹ�á�\n");

        if( me->query_skill("shengdu",1) < 100)
                return notify_fail("��ġ��������ȼ�����, ����ʹ�á�����֮������\n");

        if( me->query("neili") < 100 )
                return notify_fail("��������������޷����á�����֮������\n");
 
        msg = HIC "$N�ӻ����ͳ�һ�����ࡣ\n��ֻ���������ȷ�������Ҳ���ǰ����������Ƕ��\n$Nֻ�����ࡢ�����������ѡ���˫��һ�����ǻ�ֱð��Ȼ����ȴ���������졣�����š��ž�����һ�����͡�������û��������\n"NOR;
        message_vision(msg, me, target);

        meneili = me->query("neili");
        meforce = me->query_skill("force",1);

        tarneili = target->query("neili");
        tarforce = target->query_skill("force",1);

        qi_wound = (meneili*meforce-tarneili*tarforce)/(target->query("con")*(meforce-tarforce));

        if( qi_wound>0 ) qi_wound = (-1)*qi_wound;

        if( ( meneili > tarneili ) || ( meforce > tarforce ) ){
                msg = HIR "\n$n����$N���࣬��æ�����˫�������Ǽ�ը����ǧ���ٰ�ʮ������⣬����˿��ϸ������⻹�����ȷ��껹�ܼ���������$n��\n"NOR;
                message_vision(msg, me, target);
                target->add("qi",qi_wound);
                target->add("eff_qi",qi_wound/4);
                target->apply_condition("shengdu_poison", random(me->query_skill("shengdu")/10) + 1 + me->query_condition("shengdu_poison"));
                report_status(target);

                if( me->query_skill("shengdu",1)>150 ){
                        msg = RED "\n$n����$N�ٴ����࣬��æ�����˫�������Ǽ�ը����ǧ���ٰ�ʮ������⣬����˿��ϸ������⻹�����ȷ��껹�ܼ���������$n��\n"NOR;
                        message_vision(msg, me, target);
                        target->add("qi",qi_wound);
                        target->add("eff_qi",qi_wound/4);
                        target->apply_condition("shengdu_poison", random(me->query_skill("shengdu")/10) + 1 + me->query_condition("shengdu_poison"));
                        report_status(target);
                }
                if( me->query_skill("shengdu",1)>175 ){
                        msg = MAG "\n$n����$N���������࣬��æ�����˫�������Ǽ�ը����ǧ���ٰ�ʮ������⣬����˿��ϸ������⻹�����ȷ��껹�ܼ���������$n��\n"NOR;
                        message_vision(msg, me, target);
                        target->add("qi",qi_wound);
                        target->add("eff_qi",qi_wound/4);
                        target->apply_condition("shengdu_poison", random(me->query_skill("shengdu")/10) + 1 + me->query_condition("shengdu_poison"));
                        report_status(target);
                }
                if(userp(me))
                        me->add("neili",-100);
        }
        else
        {
                msg = HIG "ֻ��$n���ҵ�������������ģ���ܣ�����$n���Ժ�ɹ���\n"NOR;
                message_vision(msg, me, target);
        }            

        me->start_busy(3);

        return 1;

}
