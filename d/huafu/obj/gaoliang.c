// gaoliang.c

inherit ITEM;

void create()
{
	set_name("����", ({"gaoliang"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ������������Ҫĥ��(mo)��Ȼ�����۽���(ban)��\n");
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 5);
		set("food_supply", 15);
	}
}

void init()
{
	add_action("do_mo","mo");
        add_action("do_bann","ban");
}

int do_mo(string arg)
{
	object me;
	me=this_player();
	
        if ( (arg!="����") && (arg!="gaoliang") )
		return 0;
	me->set_temp("do-mo",1);
                        me->add("jingli",-5);
	message_vision("$N������ĥ���˷�ĩ״��\n",me);
        destruct(this_object());
	return 1;
}
  
/*
int do_bann(string arg)
{
	object me;
	object ob2;
	object ob;
	me=this_player();
	
        if ( (arg!="���") && (arg!="mianfen") )
		return 0;
	if ( !ob2=present("mianfen",me) )
		return notify_fail("��Ҫ�Ѹ��������ֶ�������һ��\n");
	if ( !me->query_temp("do-mo") )
		return notify_fail("�㻹û�Ѹ���ĥ���ء�\n");
	message_vision("$N��ĥ��ĸ�������۲�����һ�𣬽�����ȡ�\n",me);
	ob=new("/d/huafu/obj/gaoliangfan");
	ob->move(me);
	me->delete_temp("do-mo");
                        me->add("jingli",-5);
	destruct(this_object());
	destruct(ob2);
	return 1;
}
*/
