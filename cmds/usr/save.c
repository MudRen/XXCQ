// save.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	object link_ob;

	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
	{
		if(!objectp(me->query_temp("link_ob1")))
			return notify_fail(HIY"��δ���������߽��룬���ܴ洢��\n"NOR);
		else
		{
			write("���ñ������������\n");
			link_ob=me->query_temp("link_ob1");
			me->set_temp("link_ob",link_ob);
		}
	}

	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		write(HIY"�����´����߽���ʱ��������￪ʼ��\n"NOR);
	}

	if( (int)link_ob->save() && (int)me->save() ) {
        write(HIY"����������ϡ�\n"NOR);
		return 1;
	} else {
		write("����ʧ�ܡ�\n");
		return 0;
	}
}

int help()
{
	write(@HELP
ָ���ʽ��save

��������ܶ��Ľ����������
HELP
	);
	return 1;
}
