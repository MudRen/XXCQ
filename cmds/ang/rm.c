// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;


int main(object me, string file)
{
	seteuid(geteuid(me));
    if (!file) return notify_fail("��Ҫɾ���Ǹ�����?\n");
	if( rm(resolve_path(me->query("cwd"), file)) )
		write("Ok.\n");
	else
		write("��û��ɾ�����������Ȩ����\n");
	return 1;
}

int help()
{
  write(@HELP
ָ���ʽ : rm <����>

��ָ�������(��)ɾ����Ȩ�޸ĵĵ�����
HELP
    );
    return 1;
}
