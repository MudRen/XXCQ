// ��ʯ��� gong.c
//Write by godzilla 99.11.10

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target )
        target = offensive_target(me);
        if(!me->query("lingwu_perform"))
                return notify_fail("�㻹û����������С�\n");
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("����ʯ��١�ֻ����ս����ʹ�á�\n");
        if( (int)me->query("int") < 25 )
                return notify_fail("�����潣�ؼ�����һ�������֣������Բ�������ʹ����ʯ��٣�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 1200 )
                return notify_fail("�������������㣬ʹ������ʯ��٣�\n");     
        if( (int)me->query("neili") < 200 )
                return notify_fail("�������������㣬ʹ������ʯ��٣�\n");
        if( me->query_temp("tianyu_qijian") )
                return notify_fail("���ʹ�꡸�����潣���ľ��У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
        msg = HIW "\n$N����֮�����ʲ�����һ������Χ�ƽ�����δ���������Ѳ����������µ�һ����\n----��"+BLINK+HIR+"��ʯ���"+NOR+HIW+"����Ȼ���֣����������������ְ��ֱ��$n��ȥ��\n"NOR;        
        me->set_temp("tianyu_qijian", 1);
         if (random((int)me->query("combat_exp")) > random(target->query("combat_exp") ) )
        {                     
                damage = (int)me->query_skill("tianyu-qijian", 1); 
                damage = damage*2 + random(damage);
                msg += HIR"$p��$P��һ�й��ú��޻���֮����ֻ�����ꡱ��һ����$p����Ѫ�ѽ���ȫ��\n" NOR;
                message_vision(msg,me,target);
                call_out("perform2",0, me,target);
                call_out("remove_effect",me->query_con()/2, me); 
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->start_busy(1);
                me->add("neili", -150);    
                } 
        else {
                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -100);
                msg +=HIY"$p��Ȼ�о���$P�����������ƣ����޿ɱ��⡣�������ϣ����˳�ȥ��\n"NOR;
                message_vision(msg, me, target);
                call_out("remove_effect", me->query_con()/6, me);
        }
        return 1;
}

int perform2(object me, object target)
{
        int damage;
        string msg;
        msg = HIW "\n$N����Ϊ�꣬�ڶ����Ѿ��̳��������죬����ʢ����һ����ʯ��٣�\n"NOR;
         if(me->query_int()>= random(50))
        {
            
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -300);
                damage = (int)me->query_skill("tianyu-qijian", 1);                
                damage = damage*5 + random(damage)*2;
                msg +=HIR"ֻ�����ꡱ��һ����$n�Ѿ�����ҡҡ��׹�ˣ�\n"NOR;
                message_vision(msg, me, target);
                damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                }
                else
                {
                msg +=HIY"$n�������������������ϣ��������˳�ȥ!\n"NOR;
                message_vision(msg, me, target);	
                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -100);
                }	
       return 1;
}

void remove_effect(object me)
{
        if (!me) 
        return;
        me->delete_temp("tianyu_qijian");
        tell_object(me, HIR"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á������潣���ľ����ˡ�\n"NOR); 
}
