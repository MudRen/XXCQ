// recruit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	mapping party;
	ob = present(arg, environment(me));

	if (userp(me)) return notify_fail("���������ʱ�������Ϊ���������\n");

	if((ob->query("party")) && ((string)me->query("party/party_name") != (string)ob->query("party/party_name") ))
	{
		message_vision(
			"$N����������ǰ�İ��ɣ���Ͷ��$n�����İ��ɣ���\n\n"
			"$N������$n��ߣ���������������ԸΪ" + (string)ob->query("party/party_name")
			+ "����Ч����\n\n",ob, me);
		me->set("score", 0);
		if (me->query("combat_exp") > 10000)
			me->add("betrayer", 1);
	} else
		message_vision(
			"$N��������$n���������ɡ�\n\n"
			"$N������$n��ߣ���������������ԸΪ" + (string)me->query("party/party_name")
			+ "����Ч����\n\n",ob, me);
	me->recruit_party(ob,me->query("rank"));
	ob->delete_temp("pending/party");

	party = ob->query("party");
	tell_object(ob,HIY"��ϲ����Ϊ"+ob->query("party/party_name")+"��"+ob->query("party/rank")+"��\n"NOR); 

		return 1;
	
}


int help(object me)
{
        write(@HELP
ָ���ʽ : recruit|shou [cancel]|<����>
 
���ָ����������ĳ��Ϊ����, ����Է�Ҳ��ӦҪ����Ϊʦ�Ļ�.
 
See Also:	apprentice
HELP
        );
        return 1;
}
