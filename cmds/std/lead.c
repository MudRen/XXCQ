// lead.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("ָ���ʽ��lead <ĳ��>|none��\n");

	if( arg=="none")
		if( me->query_temp("leader") ) {
			me->delete_temp("leader");
			write("�㲻�ٴ����κ����ж��ˡ�\n");
			return 1;
		} else {
			write("�����ڲ�û�д����κ��ˡ�\n");
			return 1;
		}

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("����û�� " + arg + "��\n");

	if( !userp(ob) )
		return notify_fail("����" + ob->name() + "�����ģ�������������ߵġ�\n");

	if( ob==me )
		return notify_fail("�����Լ���\n");

	if ( me->query_temp("leader") && me->query_temp("leader") != ob )
		tell_object(me->query_temp("leader"), me->query("name") + "�ı����⣬�������ٴ������ж��ˡ�\n");

	me->set_temp("leader",ob);
	message_vision("$N��$n˵�����������ɣ��Ҵ���ȥ����ȥ�ĵط�����\n", me, ob);
	tell_object(ob, "�����Ը�����" + HIG + me->query("name") + NOR + "�ж���������follow " + me->query("id") + "��\n");

	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : lead [<����>|none]
 
���ָ�������ܴ���ĳ�˻������ж���
������� lead none ��ֹͣ���졣
 
HELP
);
        return 1;
}
