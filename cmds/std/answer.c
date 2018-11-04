// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

	if( !arg || arg=="" )
		return notify_fail("��Ҫ�ش�ʲô��\n");

	if( !stringp(target = me->query_temp("ask_you")) )
		return notify_fail("�ղ�û��������ѯ�ʡ�\n");

        if (me->ban_say())
                return 0;

	obj = find_player(target);
	if( !obj )
		return notify_fail("�ղ�����ѯ�ʵ��������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");

        if( environment(obj) != environment(me) )
                return notify_fail("�ղ�����ѯ�ʵ������ڲ��������ˡ�\n");

	message_vision("$N�ش�$n����" + arg + "��\n" NOR, me, obj);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��reply <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
	);
	return 1;
}
