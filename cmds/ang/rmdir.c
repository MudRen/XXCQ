// rmdir.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	string dir;

	if(!arg) return help();

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( rmdir(dir) )
		write("Ok.\n");
	else
		write("ɾ��ʧ�ܡ�\n");
	return 1;	
}

int help()
{
	write(@HELP
ָ���ʽ : rmdir <��Ŀ¼��>

ɾ��һ����Ŀ¼��
HELP
	);
	return 1;
}
