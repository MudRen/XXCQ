// fenfei.c ���컨��
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int skill, skill2, ap, dp,qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("sword");
        skill2 = me->query_skill("force");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��������ʹ����ô��ʹ�����컨�꡹��\n");

        if((string)weapon->query("name") == "����")
                return notify_fail("ɵ�ϣ�������ô�Ƶ��飿\n");

        if( !me->is_fighting()|| !living(me) )
                return notify_fail("�����컨�꡹ֻ����ս����ʹ�á�\n");

        if( (int)me->query("max_neili") < 600 )
                return notify_fail("���������Ϊ�������ߣ�\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("�����ڵ��������㣡\n");

        if( skill < 120)
                return notify_fail("��佻���������Ϊ����������ʹ�á����컨�꡹! \n");

        if( skill2 < 90)
                return notify_fail("������ķ�����Ϊ����������ʹ�á����컨�꡹! \n");

        if( me->query_skill_mapped("sword") != "huanhua-jian") 
                return notify_fail("��û�м���佻��������޷�ʹ�á����컨�꡹��\n");
 
        if (skill<270 || weapon->query("endure")<130)
        {
                msg = HIY "$N��Ȼ���������������������ὣ����ʱ�������ѣ����硸���컨�꡹��������Ƭ��$n�����ȥ��\n\n"NOR;
                message_vision(msg, me, target);
                ob = me->query_temp("weapon");
        if( (string)weapon->query("id")!="changge")
                destruct(ob);
 
                ap = ((me->query("combat_exp"))*(me->query_dex()));
                dp = ((target->query("combat_exp"))*(target->query_dex()))/2;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = HIR "$nһ������������������Ƭ��ȻǶ����$n�����ϣ�$n�ҽ�һ��������¶����Ϊʹ��ı��顣\n\n"NOR;
                        message_vision(msg, me, target);
                        qi_wound = 100 + skill + random(skill*2);

                        if(qi_wound > target->query("qi")) qi_wound = (target->query("qi") + 1);
                        target->add("qi", -qi_wound);
                        target->add("eff_qi", -(qi_wound/4));
                        COMBAT_D->report_status(target, 0);
                        me->start_busy(1+random(2));
                        me->add("neili",-250);
                }
                else
                {
                        msg = HIG "ֻ��$n���ҵ�������һ��ؼ��ɳ��죬���������������Ľ�Ƭ��\n\n"NOR;
                        message_vision(msg, me, target);
                        me->start_busy(3);
                        me->add("neili",-100);
                }

                call_out("perform_qiao", 10, me);
                return 1;
        }
        else if(skill<270 && weapon->query("endure")>=130)
        {
                msg = HIW "$N��Ȼ���������������һ���Ҫʩչ佻�����������֮һ�ġ����컨�ꡱ��ȴ���Ϲ�����
�㣬��Ȼû����������$w��\n" NOR;
                msg += HIR "$n��Ҫ������ͻȻ���ֻ����ѵã���ʱ������������\n\n";
                message_vision(msg, me, target);
                me->add("neili",-50);
                me->start_busy(1+random(2));
        }
        else
        {
                msg = WHT "$NͻȻ���������������"+weapon->query("name")+WHT"�����罣â���£�����һ�񣬾�Ȼʹ����佻�����
��֮�����컨�ꡱ����㽣â����$n��\n\n" NOR;
                message_vision(msg, me, target);

                ap = ((me->query("combat_exp"))*(me->query_dex()));
                dp = ((target->query("combat_exp"))*(target->query_dex()))/2;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = HIR "$nһ�����������������âǡ��������Ƭ������$n�����ϣ�$n�ҽ�һ������
��¶����Ϊʹ��ı��顣\n\n"NOR;
                        message_vision(msg, me, target);
                        qi_wound = 100 + skill + random(skill*2);

                        if(qi_wound > target->query("qi")) qi_wound = (target->query("qi") + 1);
                        target->add("qi", -qi_wound);
                        target->add("eff_qi", -(qi_wound/4));
                        COMBAT_D->report_status(target, 0);
                        me->start_busy(1 + random(2));
                        me->add("neili",-200);
                }
                else
                {
                        msg = HIG "ֻ��$n���ҵ�������һ��ؼ��ɳ��죬���������������Ľ�â��\n\n"NOR;
                        message_vision(msg, me, target);
                        me->start_busy(2);
                        me->add("neili",-100);
                }

                return 1;
        }

        return 1;
}
int perform_qiao(object me)
{
        object weapon, target;
        target = me->select_opponent();
        if(me->is_fighting() && living(target) && living(me) && (!objectp(weapon = me->query_temp("weapon"))))
        {
                object qiao;
                string msg;
                int count;
                qiao = new("/d/huanhua/npc/obj/qiao");
                qiao->move(me);
                qiao->wield();
                count = me->query_dex();
                me->add_temp("dex", count * 3); 
                count = me->query_str();
                me->add_temp("str", count * 2); 
                msg = HIY "\n$NͻȻ�����Ͻ������õ����У���ʽͻȻ���٣�����㹥�����У���ͻȻ�ı仯��$nĿ�ɿڴ���\n\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->delete_temp("dex", count * 3);
                me->delete_temp("str", count * 2);
        }
        return 1;
}
