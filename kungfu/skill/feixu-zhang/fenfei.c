// fenfei.c �����׷�
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target, ob;
        int i, num, skill, skill2, ap, dp,count;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = (int)me->query_skill("strike");
        skill2 = (int)me->query_skill("force");
        num = skill / 50;

        if( !me->is_fighting()|| !living(me) )
                return notify_fail("�������׷ɡ�ֻ����ս����ʹ�á�\n");

        if( (int)me->query("max_neili") < 600 )
                return notify_fail("���������Ϊ�������ߣ�\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("�����ڵ��������㣡\n");

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("����������ôʹ�������׷ɡ���\n");

        if(skill < 120 )
                return notify_fail("����Ʒ��������ң��޷�ʹ�á������׷ɡ���\n");

        if(skill2 < 90)
                return notify_fail("���ڹ�����Ϊ����������ʹ�á������׷ɡ�! \n");

        if( me->query_skill_mapped("strike") != "feixu-zhang") 
                return notify_fail("��û�м��������ƣ��޷�ʹ�á������׷ɡ���\n");
 
        msg = HIY "$N��Ȼ����һš��Խ�ڰ�գ�˫�ۼ��ӣ�˫�ƻ�ʮ�ơ����ơ�ǧ�ơ����ƣ�������������
�������׷ɡ�����$n��ȫ�����Ʒ�֮�С�\n\n"NOR;

        message_vision(msg, me, target);
 
        ap = ((me->query("combat_exp"))*(me->query_dex()));
        dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                me->add("neili",-300);
                msg = HIR "ͻȻ$N��ǧ�����ֺϳ�һ�ƣ��۽�$n����ߣ�����㹥�����У����Ǳ��޿ɱܣ����޿��ˣ�\n\n"NOR;
                message_vision(msg, me, target);
                count = me->query_dex();
                me->add_temp("dex", count * 2); 
                ob = me->select_opponent();
                for (i=0; i<num; i++)
                {
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                }
                me->add_temp("dex", (-1) * count * 2);  
                me->start_busy(random(4));
        }
        else if((random(me->query("combat_exp")))>(random(target->query("combat_exp"))))
        {
                me->add("neili",-300);
                msg = HIW "$n�߾�ȫ������Ȼ��ס��$N������ʵʵ���׷����ӵ�ǧ���ƵĹ��ƣ�����ȴ�˲��Ͻ����ˣ�\n\n"NOR;
                message_vision(msg, me, target);
                target->start_busy(num/2+random(num));
        }
        else
        {
                msg = HIG "ֻ��$n��ɫһ�ݣ�����Ӳ�ӣ�һ������ʱ���˳�սȦ���㿪��$N�����Ĺ��ƣ�\n\n"NOR;
                message_vision(msg, me, target);
                me->add("neili",-100);
                me->start_busy(3);
        }

        return 1;
}
