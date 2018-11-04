// state.c

#include <ansi.h>

inherit F_CLEAN_UP;
int help();
int main(object me, string arg)
{
	if(!arg) return help();
	if( strlen(arg) > 24 )
		return notify_fail("���״̬Ҫ��ô���������������\n");
	if(arg=="cancel")
	{
		me->delete_temp("state");
		write("״̬�ѱ������\n");
		return 1;
	}
	me->set_temp("state", arg);
	write("����״̬Ϊ��<"+arg+">\n");
	return 1;
}
int help()
{
	write(@HELP
ָ���ʽ : state <״̬����> | cancel
	�����Լ���״̬��
	���� state ��BUG��,��ô����look you��ʱ�������ֺ�ͻ���ʾ"<��BUG��>"��
	����cancelȡ��״̬��ʾ��
HELP
	);
	return 1;
}
