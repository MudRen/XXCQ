    // ge.c ��Ѫȭ<��ɽ��ţ>
    // god

#include <ansi.h>

    inherit F_SSERVER;
    int perform(object me, object target)
    {
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
          return notify_fail("<��ɽ��ţ>ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
          return notify_fail("�������ֲ���ʹ��<��ɽ��ţ>��\n");

        if( (int)me->query_skill("yiqiguan-riyue", 1) < 100 )
          return notify_fail("���һ�������²����ߣ��������������˵С�\n");

        if( (int)me->query_skill("feixue-quan", 1) < 100 )
          return notify_fail("��ķ�Ѫȭ������죬����ʹ��<��ɽ��ţ>��\n");
        
        if( (int)me->query("neili", 1) < 300 )
          return notify_fail("����������̫��������ʹ��<��ɽ��ţ>��\n");

        msg = CYN "$NĬ���񹦣�ʹ��<��ɽ��ţ>����ͼ����������$n��\n"NOR;

             if (me->query_skill("force") >= random(target->query_skill("force")))
        {
                me->start_busy(1+random(2));

          damage = (int)me->query_skill("yiqiguan-riyue", 1);
          damage = damage/2 + random(damage);

          target->receive_damage("qi", damage/3*2);
          target->receive_wound("qi", damage/3);
          me->add("neili", -damage);

          if( damage < 20 ) msg += HIR"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
          else if( damage < 40 ) msg += HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
          else if( damage < 80 ) msg += RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
               if( damage > 80 ) msg += MAG"���$n��$N������һ����ǰһ�ڣ��������ɳ�ʮ������\n"NOR;

        } else
        {
          me->start_busy(1);
          msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
        }
        message_vision(msg, me, target);

        if(!target->is_fighting(me)) target->fight_ob(me);

        return 1;
    }

