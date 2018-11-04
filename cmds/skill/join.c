// join.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;
	mapping party;

	if (me->is_busy())
		return notify_fail("��������æ���������顣\n");

	if( !arg ) 
		return notify_fail("ָ���ʽ��join | jiaru [cancel]|<����>\n");

	if( arg=="cancel" ) {
		old_app = me->query_temp("pending/party");
		if( !objectp(old_app) )
			return notify_fail("�����ڲ�û��ϣ���κ���Ϊ����������˼��\n");
		write("��ı����ⲻ�����" + old_app->name() + "�����İ����ˡ�\n");
		me->delete_temp("pending/party");
		return 1;
	}

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("��ϣ���������������������𣿣�\n");

	if( !living(ob) ) 
		return notify_fail("�㻹���Ȱ�" + ob->name() + "Ū������̸������ɵ��°ɡ�\n");

	if( ob==me ) 
		return notify_fail("���Լ���֯�����ˣ�\n");

	if( userp(ob))
		return notify_fail("��Բ�������������ﲻ�ܰ����Ϊʦ��\n");

	if( me->is_join_of(ob)) {
		return notify_fail("���Ѿ�������������ˡ�\n");
	}

	if( !mapp( ob->query("party") ) )
		return notify_fail(ob->name() + "�������κΰ��ɣ���ȻҲû����������롣\n");

	if( (object)ob->query_temp("pending/party") == me )
	{
		if( (string)me->query("party/party_name") != (string)ob->query("party/party_name") )
		{
			message_vision(
				"$N����������ǰ�İ��ɣ���Ͷ��$n�����İ��ɣ���\n\n"
				"$N������$n��ߣ���������������ԸΪ" + (string)ob->query("party/party_name")
				+ "����Ч����\n\n",me, ob);
		}
		else
			message_vision(
				"$N��������$n���������ɡ�\n\n"
				"$N������$n��ߣ���������������ԸΪ" + (string)ob->query("party/party_name")
				+ "����Ч����\n\n",me, ob);
		ob->recruit_party(me,ob->query("rank"));
		ob->delete_temp("pending/party");

		party = me->query("party");
		printf(HIY"��ϲ����Ϊ%s��%s��\n"NOR, 
			me->query("party/party_name"),
			me->query("party/rank"));
		return 1;
	
	} else {
		old_app = me->query_temp("pending/party");
		if( ob==old_app )
			return notify_fail("�������" + ob->name() + "���������ɣ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_app) ) {
			write("��ı����ⲻ�����" + old_app->name() + "�������ˡ�\n");
		}

		message_vision("$N��$nһ���ֵ��������ɷ�Ϊ���������������\n", me, ob);
		me->set_temp("pending/party", ob );
		ob->attempt_join(me);
		return 1;
	}
}


int help(object me)
{
        write(@HELP
ָ���ʽ : apprentice|bai [cancel]|<����>
 
���ָ���������ĳ��Ϊʦ������Է�Ҳ��ӦҪ����Ϊͽ�Ļ����ͻ�������
��ʦ֮�񣬷���Ҫ�ȵ��Է��� recruit ָ������Ϊ���Ӳ�����ʽ��ʦ��

��ע�����Ѿ�����ʦ�����ֱ���ʦ��Ͷ��������£���ʦ���������������
������������²���Ϊ��ʦ����

��������ʦ��ʹ�����ָ�������ʦ���밲��

Ŀǰ��MUD���ܰ����Ϊʦ��
 
��ο����ָ�� expell��recruit
HELP
        );
        return 1;
}
