// alarm.c 1.0 congw
#include <ansi.h>
inherit F_CLEAN_UP;
int help();
void create() {seteuid(getuid());}
int main(object me, string arg)
{
string target, msg;
object obj;
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) 
		return help();
	obj = find_player(target);
	write(HIR "\n �㾯��" + obj->name(1) + "��\n \n" + 
		"      �������"+msg +"��ΪΥ������Ϸ��������˲���Ӱ�죬����ٷ���\n"+
		"      �����ص���ɽ����������죡\n \n" NOR);
	tell_object(obj, sprintf( HIR "\n %s�����㣺\n \n"+
		"      �������%s��ΪΥ������Ϸ��������˲���Ӱ�죬����ٷ���\n"+
		"      �����ص���ɽ����������죡\n \n" NOR,
	me->name(1), msg));
	return 1;
}

int help()
{
write(@HELP
ָ���ʽ��alarm <ĳ��> <ѶϢ>
����������ָ����κ��ˡ�
HELP
);
return 1;
}
