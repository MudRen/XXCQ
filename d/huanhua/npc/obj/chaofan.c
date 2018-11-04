// lurou.c ʲ������

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ʲ������", ({"chao fan", "fan"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����׷������������⳴�ɵ�ʲ�����������ȳ԰ɡ�\n");
		set("unit", "��");
		set("food_remaining", 5);
		set("food_supply", 30);
	}
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");
}

int do_eat(string arg)
{
	if ( !this_object()->id(arg) ) return 0;

	if ( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");

	if ( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
		return notify_fail("���Ѿ��Ե�̫���ˣ���Ҳ�Բ����ˡ�\n");

	this_player()->add("food", (int)query("food_supply"));

	if ( this_player()->is_fighting() ) 
		this_player()->start_busy(2);

	add("food_remaining", -1);

	if ( query("food_remaining") )
	{
   		message_vision("$N�������ӣ����̻��ʵĳ���������\n", this_player());
	}
	else 
	{ 
	   	message_vision("$N�������ӣ��������һ�ڷ��������죬һ������δ�������ӡ�\n", this_player());
		destruct(this_object());
	}

	return 1;
}
