// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	me->delete_temp("block_msg/all");
	write(CLR);
	write("\n���ֹ��ĵ����㣺������Σ���ץס�����´�С��ѽ��\n");
message("channel:chat", HIC"�����塿"+me->name(1)+"��������ش���Ļ�������ϰ���������ʧ���ݰ������ġ�\n"NOR,users());
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: bossgone  

���ָ������(���)���ϰ��ߺ�ָ���������Ϸ��

�й�ָ�boss
HELP
    );
    return 1;
}
