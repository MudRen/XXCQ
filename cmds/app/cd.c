// cd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir;

	seteuid(geteuid(this_player(1)));
	//add by jackyboy 98/12/10
	//��ֹ���ɶ���Ŀ¼���ļ�����ʾ������

	if( !arg )
		arg = user_path(me->query("id"));
	dir = resolve_path(me->query("cwd"), arg);
	if(file_size(dir)!=-2) return notify_fail("û�����Ŀ¼��\n");
	if(dir[strlen(dir)-1]!='/') dir += "/";
	write("�ı䵱ǰĿ¼Ϊ��"+dir+"\n");
	me->set("cwd", dir);
	return 1;	
}

int help()
{
	write(@HELP
ָ���ʽ : cd <��Ŀ¼��>, cd .. , and cd

��Ŀǰ�ο���Ŀ¼����ָ������Ŀ¼��ص���һ��Ŀ¼; ���ֱ�ӻص��Լ�����Ŀ¼��
HELP
	);
	return 1;
}
