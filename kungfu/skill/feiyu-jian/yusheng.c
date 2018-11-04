//SKILL PERFORM yusheng.c �ٺ�����
//Modified by Atlus by 1999.10.9

#include <ansi.h>
 
inherit F_SSERVER;

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
	if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
	if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
	if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
	if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
	if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
	if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
	if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

varargs void report_status(object ob)
{
	message_vision( "( $N" + status_msg(
		(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
		+ " )\n", ob);
}

int perform(object me)
{
	string msg;
	object weapon, target;
	object ob;
	int skill, skill2, skill3;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = (me->query_skill("feiyu-jian",1)+(me->query_skill("sword",1))/2);
	skill2 = (me->query_skill("tianlongforce",1)+(me->query_skill("force",1))/2);
    skill3 = (me->query_skill("fish-steps",1)+(me->query_skill("dodge",1))/2);

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("�����ϻ�û�н���\n");

	if( !me->is_fighting()|| !living(me) )
	    	return notify_fail("���ٺ�������ֻ����ս����ʹ�á�\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ�������ߣ�\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�����ڵ��������㣡\n");

	if( skill < 150)
		return notify_fail("�㽣������Ϊ����������ʹ�á��ٺ�������! \n");

	if( skill2 < 120)
		return notify_fail("���ڹ���Ϊ����������ʹ�á��ٺ�������! \n");
   
	if( skill3 < 120)
		return notify_fail("���Ṧ��Ϊ����������ʹ�á��ٺ�������! \n");

	if( me->query_skill_mapped("sword") != "feiyu-jian") 
		return notify_fail("��ķ��㽣����û׼���ã��޷�ʹ�á��ٺ���������\n");
	
 
	msg = HIY"$N����Խ�𣬺�Х��ת���ţ�����"+(string)weapon->query("name")+HIY"����������â��������ʢ�����ǹ�����ǰ���еĹ�â����Х�Ź���$n��\n\n"NOR;
	message_vision(msg, me, target);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("neili", -300);
	me->start_busy(random(2));

	if(!ob->is_fighting(me)) ob->fight_ob(me);
		return 1;
}
