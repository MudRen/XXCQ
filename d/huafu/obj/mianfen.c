// mianfen.c

inherit ITEM;

void create()
{
	set_name("���", ({"mianfen"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�Ű׻�������ۡ�\n");
		set("unit", "��");
		set("value", 40);
	}
}

void init()
{
         add_action("do_bann","ban");
}

int do_bann(string arg)
{
        object me;
        object ob;
        me=this_player();
        if ( (arg!="���") && (arg!="mianfen") )
                return 0;
        if ( !ob=present("mianfen",me) )
                return notify_fail("��Ҫ�Ѹ��������ֶ�������һ��\n");
        if ( !me->query_temp("do-mo") )
                return notify_fail("�㻹û�Ѹ���ĥ���ء�\n");
        message_vision("$N��ĥ��ĸ�������۲�����һ�𣬽�����ȡ�\n",me);
        ob=new("/d/huafu/obj/gaoliangfan");
        ob->move(me);
        me->delete_temp("do-mo");
                        me->add("jingli",-10);
        destruct(this_object());
        return 1;
}

