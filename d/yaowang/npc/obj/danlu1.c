// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(CYN"����¯"NOR, ({ "liandan lu", "liandan", "lu" }) );
        set_weight(300000);
        set_max_encumbrance(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͭ���ɵ�����¯��\n");
                set("value", 1000);
                set("no_get",1);
                set("amount",10);
		set("container",1);
        }
        setup();
}

void init()
{
       add_action("do_fang", "fang");
	add_action("do_lian", "liandan");
	add_action("do_ran", "ran");
}

int do_fang(string arg)
{
	object me, ob;
	me = this_player();

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
		&& (int)me->query_skill("healing",1)<60 ) {
		return notify_fail("�㻹����������������\n");
	}

	if(me->query("shen")<0) {
		return notify_fail("��Ӧ�������ߵ�������ȥ������\n");
	}

	if(!arg || !ob=present(arg, me))
		return notify_fail("��Ҫ��ʲô�Ž�����¯��\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ���أ�\n");

        message_vision(YEL"\n$N��һ"+ob->query("unit")+ob->query("name")
		+"�Ž�����¯��\n\n"NOR, me);

	destruct(ob);
	ob->move(this_object());
	return 1;
}

int do_lian(string arg)
{
        object ob1, ob2, ob3, ob4, ob5;
	object me, ob, obj;
	me=this_player();
	ob=this_object();

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
		&& me->query("party/level")<4 ) {
		return notify_fail("�㻹����������������\n");
	}

	if(me->query("shen")<0) {
		return notify_fail("��Ӧ�������ߵ�������ȥ������\n");
	}

        if( !arg && ((arg!="bigu wan") || (arg!="zaohua dan")) )
		return notify_fail("ָ���ʽ��liandan <��ҩID> \n"
		"        �������ĵ�ҩ�У� �̹���(bigu wan)\n"
		"                         �컯��(zaohua dan)\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ���أ�\n");

        if( !me->query_temp("liandan") )
                return notify_fail("��¯��û�е�ȼ����ô������\n");

	if( objectp(ob1=present("lu xue",ob))
		&& objectp(ob2=present("lu rong",ob))
		&& objectp(ob3=present("xiong dan",ob))
		&& objectp(ob4=present("xiong zhang",ob))
		&& objectp(ob5=present("she dan",ob)) ) {
                        destruct(ob1);
                        destruct(ob2);
                        destruct(ob3);
                        destruct(ob4);
                        destruct(ob5);
		if(arg=="bigu wan") { obj=new(__DIR__"biguwan"); }
		if(arg=="zaohua dan") { obj=new(__DIR__"zaohuadan"); }
	message_vision(HIR"$N���ϵ�¯��¯�ţ��߶�������ʼ������\n\n"NOR, me);
	message_vision(HIR"һ���¯���ڵĻ��潥��Ϩ��\n\n"NOR, me);
	message_vision(HIR"��ҩ�����ˡ�\n"NOR, me);
	message_vision(HIR"¯�𽥽�Ϩ���ˣ�\n"NOR, me);
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/2));
		obj->move(ob);
		me->delete_temp("liandan");
		return 1;
                }
	else
	return notify_fail("����ҩ�Ļ�û׼����ѽ��\n");
}

int do_ran(string arg)
{
	object me;
	me=this_player();

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
		|| me->query("party/level")<4
		|| me->query("shen")<0 ) {
		return notify_fail("������������Ķ�����\n");
	}

        if( me->query_temp("liandan") )
                return notify_fail("��¯�Ļ��Ѿ������ˣ��쿪ʼ�����ɣ�\n");

	me->set_temp("liandan",1);
	message_vision(HIR"$N�����������¯�ţ��ѵ�¯��ȼ��\n"NOR, this_player());
	return 1;
}
