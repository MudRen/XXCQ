// hubo.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	string msg;
	int count;

    if( me->is_busy() )
        return notify_fail("��Ķ�����û����ɣ�����ʹ�á�˫�ֻ���֮������\n");
    if (!me->query_skill("hubo",1))
       return notify_fail("�㲻�ᡸ˫�ֻ���֮������\n");
    if( !me->is_fighting() )
        return notify_fail("��˫�ֻ���֮����ֻ����ս����ʹ�á�\n");

    if( (int)me->query("jing") < 70 ) return notify_fail("��ľ�������\n");
//    if( (int)me->query("neili") < 70 )
//        return notify_fail("�������������\n");

    msg = HIY "$Nƽ�ľ�������̨������ʹ����˫�ֻ���֮������˫��ͬʱ���У�\n" NOR;

    message_vision(msg, me);
    count = (40 - (int)me->query("int")) / 5 + (int)me->query_skill("hubo") / 20 ;
    if( count < 1 ) count = 1 ;
    if ( count > 7 ) count = 7 ;
	while( count-- ) {
		object ob;

	me->clean_up_enemy();
	ob = me->select_opponent();
        if(!ob || (environment(ob) != environment(me))) 
        {
            message_vision(CYN "$NͻȻ����һ�ң��Ѳ��ܼ���˫�ֻ�����\n" NOR, me);
			break;
        }
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	}

    return 1;
}

int help()
{
        write(@HELP
ָ���ʽ : hubo
 
���ָ����������ڶԵ�ʱʹ��˫�ֻ���֮��,���ٳ��С�
 
HELP
    );
    return 1;
}
