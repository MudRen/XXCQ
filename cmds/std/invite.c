// invite.c

#include <ansi.h>
#include <net/dns.h>

//inherit F_CLEAN_UP;

void create() {seteuid(getuid());}

int main(object me, string arg)
{	object where;
	string target;
	object obj;
	if(me->query_temp("marks/����2")||me->query_temp("marks/����3")){
	if( !arg || sscanf(arg, "%s", target)!=1 ) return notify_fail("��Ҫ����ʲô�ˣ�\n");

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	write(HIG "������" + obj->name(1) + "�μ��������Ǵ��¥����ᡣ\n" NOR);
	tell_object(obj, sprintf( HIG "��ӵ�%s�����Ǵ��¥�����������\n" NOR,
		me->name(1)));
	where = environment(obj);
	obj->set_temp("marks/����",1);
	me->set_temp("marks/��",1);
	message("vision",obj->query("name")+"�ӵ�"+me->name(1)+"�����Ǵ��¥�����������\n",where,({obj}));
	obj->set_temp("reply", me->query("id"));
	return 1;
	}return 0;
}

