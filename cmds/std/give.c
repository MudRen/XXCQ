// give.c
#include <ansi.h>
//modify by jackyboy @cctx 98/12/29 for quest type "Ѱ" & "��"
#define CMDS_NICK "/cmds/usr/nick"
inherit F_CLEAN_UP;

int do_give(object, object, object);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
		if( obj->query("no_drop") )
			return notify_fail("�����������������ˡ�\n");
         if( who->query("env/no_accept"))
                 return notify_fail("�Է����ڲ����ܱ��˵�������\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else {
				obj->set_amount((int)obj->query_amount() + amount);
				return 0;
			}
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	if( obj->query("no_drop") )
		return notify_fail("�����������������ˡ�\n");
	if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("�Է��������������Ķ�����\n");
	if( who->query("env/no_accept"))
		return notify_fail("�Է����ڲ����ܱ��˵�������\n");
	//��Ϊ���ִ��벻�淶������accept_object�ｫobj destruct���������Ӵ˾�
	if(!objectp(obj))
		return notify_fail("��Ʒ�����ߴ��벻�淶("+base_name(who)+".c)����ת����ʦ��\n");
	//�����ֵǮ���ҶԷ�������������ٸ���Ʒ
	if( !userp(who)&&!obj->value() ) {
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
		destruct(obj);
		me->save();
		return 1;
	} 
	//����ɹ��ݽ���Ʒ����ʾ�����Ϣ
	if( obj->move(who) )
	{
		message_vision("$N�ó�һ" + obj->query("unit") + obj->name() + "��$n��\n", me, who);
		me->save();
		return 1;
	}
	else 
	//������ɹ����ж϶Է��Ƿ�����ң�������ʾ�޷�give��������ʾ����ȥ�ˣ������ٸ���Ʒ
	//���ڴ���npc���س��ص��������������ǱȽ���Ҫ����Ʒ�Ļ����ܻ�������⣬ֻ�п�д��Ʒ��
	//��ʦ���ע��Щ�ˡ�
	if(!userp(who))
	{
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
		//��Ϊ�Է�������ң����Կ����������������
		if((who->query_max_encumbrance()+2*obj->weight() )>0)//��ֹ���
			who->set_max_encumbrance(who->query_max_encumbrance()+2*obj->weight());
		if(!obj->move(who))
		{
			if(userp(obj))
			{
				message_vision("$Nһ����û���ȣ�$n����������\n",who,obj);
				obj->move(environment(who));
			}
			else
				destruct(obj);
		}
		return 1;
	}
	else
	{
		return notify_fail("�Է��Ѿ��޷������������Ʒ�ˣ�\n");
	}
}
int help()
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.
 
HELP
    );
    return 1;
}
