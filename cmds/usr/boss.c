// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	write(CLR);
	if(arg)
	{
		msg = read_file("/open/shit.txt");
		write(msg);
	}
	me->set_temp("block_msg/all",1);
message("channel:chat", HIW"�����塿"+me->name(1)+"�Ҵҹ�����Ļ����ͷ���ܡ��������ϰ����ˡ�\n"NOR,users());
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: boss <arg>

���ָ������(���)���ϰ����ǰһ����ʱ����Ļ�����е�
������������� <arg>������Ļ�����������������Ļ��
��ʾ��һЩ���¡����ͬʱ���㽫�ܲ����κ�������Ϸ��Ѷ
Ϣ��ֱ��������bossgoneָ�

�й�ָ�bossgone
HELP
    );
    return 1;
}