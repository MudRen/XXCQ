// put.c

inherit F_CLEAN_UP;

int do_put(object, object, object);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("��Ҫ��˭ʲô������\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("����û������������\n");
	//JackyBoy�����container���Ի���is_container()���÷���1˵���������࣬���ԷŽ�ȥ��
	if( dest->query("container")==0&&!dest->is_container())
		return notify_fail("���ܷŶ�����"+dest->name()+"��ġ�\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if(!obj->query("no_drop"))
			return notify_fail("�������������뿪�㡣\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ���\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_put(me, obj2, dest);
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	if(obj==dest)
	{
		tell_object(me,"���ܰ�"+obj->name()+"�ŵ����Լ����棡\n");
		return 1;
	}
	if( obj->query("no_drop"))
	{
		tell_object(me,obj->name()+"�����뿪�㣡\n");
		return 1;
	}
	
	if( obj->move(dest) ) {
		message_vision( sprintf("$N��һ%s%s�Ž�%s��\n",
			obj->query("unit"), obj->name(), dest->name()),
			me );
		return 1;
	}
	else return 0;
}

int help()
{
write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}
