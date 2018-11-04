// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if(me->ban_say()) return 0;
	if (!arg) {
		write("���������ﲻ֪����˵Щʲô��\n");
		message("sound", me->name() + "�������ﲻ֪����˵Щʲô��\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	write( CYN "��˵����" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "˵����" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help ()
{
	write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
	);
	return 1;
}
