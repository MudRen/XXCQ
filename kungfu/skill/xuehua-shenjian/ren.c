#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,ob;
        int skill;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ѩ��������ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ѩ�������������ý�����ʩչ��\n");

        if( (int)me->query_skill("xuehua-shenjian", 1) < 120 )
                return notify_fail("��ġ�ѩ��������������죬����ʹ�á�ѩ����������\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("�������������\n");

        skill = me->query_skill("xuehua-shenjian");

        msg = HIW "$N������Ů�����������������ﵽ���ý�����߾����˽���һ,$Nʹ���˾��춯�ص�"MAG"ѩ������!\n"NOR;

        message_vision(msg, me, target);

        me->add("neili", -300);

        me->clean_up_enemy();
        ob = me->select_opponent();

        msg = RED"�������\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
        msg = HIW"��������\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
        msg = BLU"�׶�����\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
        msg = HIM"�˽���һ\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
        
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

