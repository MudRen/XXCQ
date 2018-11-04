inherit ITEM;

#include <ansi.h>

void init()
{
        add_action("do_drink", "drink");
}

void create()
{
	set_name(HIC "������" NOR, ({"tang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
	        set("unit", "��");
		set("long", "����һ��ζ�������Ķ�������\n");
		set("value", 0);
		set("drink_remaining", 5);
		set("drink_supply", 30);
	}
	setup();
}

int do_drink(string arg)
{
	if ( !this_object()->id(arg) ) return 0;

	if ( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");

	if ( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	this_player()->add("water", (int)query("drink_supply"));

	if ( this_player()->is_fighting() ) 
		this_player()->start_busy(2);

	add("drink_remaining", -1);

	if ( query("drink_remaining") )
	{
   		message_vision("$N�������룬�����ĺ���һ��������\n", this_player());
	}
	else 
	{ 
	   	message_vision("$N�������룬�ȸ������һ��������\n", this_player());
		destruct(this_object());
	}

	return 1;
}
