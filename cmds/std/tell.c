// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help();

void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	if(me->ban_say()) return 0;
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help();

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("���ڹ���������������Ļ�������\n");
	
	if (!wizardp(me) && (obj->query_temp("notell/"+me->query("id")) 
	     || obj->query_temp("notell_all")))
	return notify_fail(obj->query("name")+"������������Ļ���\n"); 	

        write( HIG "�����" + obj->name(1) + "��" + msg + "\n" NOR);
        tell_object(obj, sprintf( HIG "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)�����㣺%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s �����㣺%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help()
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����

�������ָ�reply
HELP
	);
	return 1;
}
