// jinchuang.c ��ҩ

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	add_action("do_eat", "chi");
}

void create()
{
	set_name(HIM"��Ѫ��"NOR, ({"huoxue dan", "dan", "huoxue"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������ƵĻ�Ѫ�����澭���硢��Ѫ�����кܺõ�Ч����\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ���û�Ѫ����\n");

	else {
		this_player()->receive_curing("qi", 30+random(30));
		message_vision("$N�ó�һ�Ż�Ѫ����һ������������ȥ����ɫ��ʱ����������һЩ��\n", this_player());
		destruct(this_object());
		return 1;
	}
}