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
	set_name(HIW"���ϰ�ҩ"NOR, ({"yunnan baiyao", "yao", "baiyao", "yunnan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ƿ");
		set("long", "����һƿ����Ϊ����ʥƷ�����ϰ�ҩ����������(fu)���˿��ϵġ�\n");
		set("value", 10000);
	}
	setup();
}

int do_fu(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�����ϰ�ҩ��\n");
	else {
		this_player()->receive_curing("qi", 100+random(50));
		message_vision("$NС������Ľ����ϰ�ҩ���ڸ����˿��ϣ��˿ڼ������漣��ĺ�ת�ˡ�\n", this_player());
		destruct(this_object());
		return 1;
	}
}