// version.c

inherit F_CLEAN_UP;

int main()
{
	write(__VERSION__+"\n");
	return 1;
}
int help(object)
{
  write(@HELP
ָ���ʽ : version
 
���ָ�����ʾ��ϷĿǰ���õ� MudOS driver �汾.
 
HELP
    );
    return 1;
}
 
