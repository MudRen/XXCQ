// shipo.c
// made by lks
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
         string msg;
        	
        if( !me->is_fighting() )
                return notify_fail("��ʯ���쾪��ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

          if( (int)me->query_skill("poshan-dao",1) < 80 )
                return notify_fail("�����ɽ������򲻹����޷�ʹ�á�ʯ���쾪����\n");

         if( (int)me->query_skill("force",1) < 100 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á�ʯ���쾪����\n");

        msg = HIM "$N"HIC"����ֹˮ������֮��ʹ����"HIR"��ʯ���쾪����\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();
        msg = HIR"ʯ�־���\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIY"���־���\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIC"���־���\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIW"���־���\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
          
        if (me->query_skill_mapped("force")=="bairen-shengong")
        {
               message_vision(HIR"$Nֻ��һ������������������ֱ�����ŵ����ȷ�����\n"NOR,ob);
               ob->add("qi",(-1)*(me->query_skill("bairen-shengong",1)));
               ob->add("douzhi",-random(6));
               message_vision(CYN"$N�Ķ�־�½��ˣ�����\n"NOR,ob);
        }

        me->add("neili", -300);
        if( me->is_fighting() ) 
            me->start_busy(2+random(2));

        return 1;
}

