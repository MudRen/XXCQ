// cat.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help();

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return notify_fail("����Ҫ��ʾ�Ǹ�����?\n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("û�����������\n");
	cat(file);
	return 1;
}

int help()
{
write(@HELP
ָ���ʽ : cat <����>

��ָ�������(��)ֱ�Ӷ�ȡĳ����֮��ʽ��
HELP
    );
    return 1;
}
