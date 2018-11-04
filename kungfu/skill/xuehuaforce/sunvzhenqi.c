//god
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("��ֻ������Ů�����������Լ���ս������\n");

        if( (int)me->query("neili") < 200  ) 
                return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -200);
        me->receive_damage("qi", 0);

        message_vision(
        HIW "$Nһ��ŭ�ȣ�������Ů����������$N�������ƣ�����һ����\n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->add_temp("apply/parry", skill/3);
        me->add_temp("apply/sword", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/6);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/parry", - amount);
        me->add_temp("apply/sword", - amount);
        me->delete_temp("powerup");
        tell_object(me, "�����Ů����������ϣ��������ջص��\n");}
}

