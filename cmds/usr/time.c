// time.c

inherit F_CLEAN_UP;

int main()
{
	write("������" + NATURE_D->game_time() + "��\n");
	return 1;
}

int help()
{
     write(@HELP
ָ���ʽ: time

���ָ������(��)֪�����ڵ�ʱ����

HELP
    );
    return 1;
}
