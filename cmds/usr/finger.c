// finger.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob;
	
	if( !arg )
	{
		if( (int)me->query("jingli") < 50 )
			return notify_fail("��ľ������㡣\n");
		if( !wizardp(me) )
			me->receive_damage("jingli", 50);
		write( FINGER_D->finger_all() );
	} else 
	{
		ob=find_player(arg);
		if( (int)me->query("jingli") < 15 )
			return notify_fail("��ľ������㡣\n");
		if( !wizardp(me) )
			me->receive_damage("jingli", 15);
		write( FINGER_D->finger_user(arg) );
		if (ob&&me->visible(ob)&&(me!=ob))
		{
			if(!wizardp(me))
			{
				tell_object(ob,HIY"�㲻�ɵô���һ����ս...\n"NOR);
/*
				message("channel:chat", HIG +"�����ġ���....��...."+ 
					ob->query("name")+"����һ��������...��ˬ��.\n"NOR, users());
*/
			}
		}
	}
	return 1;
}

int help()
{
  write(@HELP
ָ���ʽ : finger [ʹ��������]
 
���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
 
see also : who
HELP
    );
    return 1;
}
 
