// jinchuang.c ��ҩ

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name(HIY"��ҩ"NOR, ({"jinchuang yao", "yao", "jin", "jinchuang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ֹѪ���ϺõĽ�ҩ����������(fu)���˿��ϵġ�\n");
		set("value", 2000);
	}
	setup();
}

int do_fu(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
	else {
		this_player()->receive_curing("qi", 30);
		message_vision("$NС������Ľ���ҩ�����˿��ϣ��˿����Ͽ������˲��١�\n", this_player());
		destruct(this_object());
		return 1;
	}
}