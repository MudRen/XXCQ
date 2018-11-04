// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string callname;
	object *t;
	int i;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

	callname = RANK_D->query_rude(obj);
        t = me->query_team();
	if(sizeof(t) <=1)
	return notify_fail("�����ڲ�û�вμ��κζ�������ֻ��һ���ˡ�(use kill)\n");
	if( userp(obj) )
		return notify_fail("������ɲ����Ըĵ������۹ѵĶ�ϰ��\n");
	for(i=0;i<sizeof(t);i++)
	if( t[i])
	if( environment(me) != environment(t[i]))
		return notify_fail("��Ա�����ڳ���(use kill)\n");		
	message_vision("\n$N����$n�ȵ�����" 
		+ callname + "�����ղ��������������ǻ��\n\n", me, obj);
        for(i=0;i<sizeof(t);i++)
	{
	if(t[i]){
		t[i]->set_temp("ttarget",obj->query("id"));
		t[i]->kill_ob(obj);
		obj->kill_ob(t[i]);
		}
	}
	return 1;
}
int help()
{
  write(@HELP
ָ���ʽ : teamkill <����>
 
���ָ������Ķ�����������һ��������ý��������ж�Ա����֣�
���������õ�����Ķ�Ա����ɱ�����У�
�������ָ��: team,fight,kill

HELP
    );
    return 1;
}
 
