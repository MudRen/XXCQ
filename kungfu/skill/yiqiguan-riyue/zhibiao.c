// made by lks
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int exert(object me)
{
        string msg;
        object target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("yiqiguan-riyue",1);

        if( !(me->is_fighting() ))
                return notify_fail("��ָ�ڡ�ֻ����ս�������ڶ������ϡ�\n");
 
        if( skill < 50)
                return notify_fail("���һ�������²�������, ����ʹ�á�ָ�ڡ���\n");

        if( me->query("neili") < 150 )
                return notify_fail("��������������޷����á�ָ�ڡ���\n");
 
        if (me->query("yiqiguan-riyue")==1) {
        msg = HIY "$NĬ�ˡ������������񹦣�������ָ��һʽ��ָ�ڡ���ֱ��$n��\n�����������ȱ������������������Ԩ������Ѫ�ʡ���Ѩ��\n";
        ap = me->query_skill("force") + skill;
        }
          else if (me->query("yiqiguan-riyue")==2) {
        msg = HIY "$NĬ�ˡ��Ƿ��켫���񹦣�������ָ��һʽ��ָ�ڡ���ֱ��$n��\n�����������ȱ������������������Ԩ������Ѫ�ʡ���Ѩ��\n";
        ap = (me->query_skill("force") + skill)*3/2;
        }
            else  {
        msg = HIY "$NĬ����Ϣ��������ָ��һʽ��ָ�ڡ���ֱ��$n��\n�����������ȱ������������������Ԩ������Ѫ�ʡ���Ѩ��\n";
        ap = (me->query_skill("force") + skill)/2;
        }
 
        dp = target->query_skill("force") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-100);
                  msg += "$N��ָ�ڡ�����Ŀ��, $n��ʱ���õ�����һ���ʹ��\n";
                msg += "ȫ��������й������\n" NOR;

                neili_wound = ap + random(skill);
                if(neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");

                qi_wound = neili_wound / 5;
                if(qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");

                target->add("neili", -neili_wound);
                target->add("qi", -qi_wound);
                target->add("eff_qi", -qi_wound);
                target->start_busy(2);
                me->start_busy(random(2));
        }
        else
        {
                if(userp(me))
                        me->add("neili",-80);
                 msg += "����$n˲�䷴Ӧ��������Ų��Ծ�����������ش���\n"NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}

