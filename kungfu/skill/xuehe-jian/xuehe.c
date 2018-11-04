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
                return notify_fail("��Ѫ�Ӿ���ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��Ѫ�Ӿ��������ý�����ʩչ��\n");

        if( (int)me->query_skill("xuehe-jian", 1) < 120 )
                return notify_fail("��ġ�Ѫ�ӽ�����������죬����ʹ�á�Ѫ�Ӿ�����\n");

        if( (int)me->query("neili") < 250  ) 
                return notify_fail("�������������\n");

        skill = me->query_skill("xuehe-jian");

        msg = HIG "$N����ͻ�䣬ʹ��Ѫ�ӽ����ľ�����"HIR"Ѫ�Ӿ�!\n"NOR;

        message_vision(msg, me, target);

        me->add("neili", -300);

        me->clean_up_enemy();
        ob = me->select_opponent();

        msg = RED"Ѫ"HIR"ϴ��ӣ�\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        msg = RED"Ѫ"HIY"���ɺӣ�\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        msg = RED"Ѫ"HIG"��������\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        msg = RED"Ѫ"HIB"�����죡\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
        msg = RED"Ѫ"HIW"�����죡\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);


        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

