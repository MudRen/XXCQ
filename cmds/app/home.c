// home.c

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
	string msg;

	if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
		return notify_fail("��û���Լ��Ĺ����ҡ�\n");

	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
	me->move("/u/" + geteuid(me) + "/workroom.c");
	return 1;
}

int help()
{
  write(@HELP
ָ���ʽ : home

���ô�һָ���ֱ�ӻص��Լ��Ĺ����ҡ�
������� 'msg_home' ����趨, ���ڳ����˶��ῴ���Ǹ�ѶϢ.
HELP
    );
    return 1;
}
