inherit ITEM;

int do_sweep();

void create()
{
        set_name("��ɨ��", ({ "saozhou", "zhu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
}

void init()
{
	add_action("do_sweep", "sao");
	add_action("do_sweep", "sweep");
}

int do_sweep()
{
	object where,me;
	int *num;
	me = this_player();
	where = environment(me);
	if ((where->query("jobname"))==(me->query("jobname")))
	{
		if (num[where->query("jobnumber")]=1)
		{
			message_vision("asdasdasdasd", me);
		}
		else
		{
			message_vision("aaaaaaaaaaaaaaa\n", me);
			num[where->query("jobnumber")]=1;
		}
		return 1;
	}
	else
	{
		message_vision("aaaaaadfffffffff\n", me);
		return 1;
	}
}