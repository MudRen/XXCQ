// bandage.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"������"NOR, ({ "hugu tie", "hugu", "tie" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������ƺ��ƵĻ���������Ϊ���л��Ƿۣ�������(tie)�ڻ�����ѪЧ���ܺá�\n");
		set("value", 1000);
	}
}

void init()
{
	add_action("do_tie", "tie");
}

int wear() { return 0; }

int do_tie(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ����������\n");

	else {
		message_vision("$N�ó�һ�������������������ϵ����࣬��ž����һ���ͽ���ҩ���������ϡ�\n", this_player());
		this_player()->apply_condition("hugutie", 20);
		destruct(this_object());
	}
}
