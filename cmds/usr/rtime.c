// rtime.c
inherit F_CLEAN_UP;
int main(object ,string arg)
{
	int i;

	if(!arg||sscanf(arg,"%d",i)!=1)
		i=1;
	write("������" + CHINESE_D->chinese_time(i,(string)localtime(time())) + "��\n");
	return 1;
}

int help()
{
     write(@HELP
ָ���ʽ: rtime

���ָ������(��)֪�����ڵ�ʵ��ʱ�䡣
���Դ�����1-6�Բ�ͬ�ĸ�ʽ��ʾ��

HELP
    );
    return 1;
}

