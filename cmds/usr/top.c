// team.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *toplist;
	string str;
	int i,j;
	
	if(arg=="-p")
	{
		str="��Ŀǰ������"+me->query_tops()+"��\n";
		me->start_more(str);
		return 1;
	}
	
		toplist=COMPETE_D->get_tops();
		str=HIC "������Ӣ�����а�\n" NOR;
		str+="��������������������������������������������������������������������\n";
		for(i=0,j=sizeof(toplist);i<j;i++)
		{	str+="��"+chinese_number(i+1)+"����";
			str+=COMPETE_D->user_fight_info(toplist[i]);
					
		}
		str+="��������������������������������������������������������������������\n";
    me->start_more(str);
	return 1;
}

int help()
{
	write( @HELP
TOPָ���÷���
top ��ʾĿǰ�����а�
top -p��ʾ������μ��μӱ������Ϣ��
HELP
	);
	return 1;
}
