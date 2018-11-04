inherit ITEM;

void init();
void do_eat();

void create()
{
    set_name("������",({"longjing cha", "cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("long", "һ�������ڵ���衫����\n");
        set("unit", "��");
		set("value", 10);
        set("remaining", 3);
        set("drink_supply", 25);
	}
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{
	int recover;
	recover = 5;

	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( (int)this_player()->query("water")
	   >= (int)this_player()->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
	this_player()->add("water", (int)query("drink_supply"));


	if( this_player()->is_fighting() ) this_player()->start_busy(2);
	add("remaining", -1);
	if ( query("remaining") )
	{
        message_vision("$N���������� ��������ζ��Ʒ�˼��ڡ�\n"+
        "һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
	} else 
	{ 
        message_vision("$N��ʣ�µĲ�һ��������\n"+
        "һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
		destruct(this_object());
	}
	return 1;
}
