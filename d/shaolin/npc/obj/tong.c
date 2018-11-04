// liangong-fu.c

inherit ITEM;
#include <ansi.h>

int do_fill(string);
int do_dao(string);

void create()
{
	set_name(YEL"ˮͰ"NOR, ({ "shui tong", "tong" }));
	set("long", "һ��������ˮ(fill water)��ˮͰ��������ˮ��(dao water)��ˮ���\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "��");
		set("no_drop", "�ӵ����ǻᰤ��ģ��������˰ɡ�\n");
	}
	setup();
}

void init()
{
	add_action("do_fill", "fill");
	add_action("do_dao", "dao");
}

int do_fill(string arg)
{
	object ob, me;
	me = this_player();
	ob = this_object();

	if (!arg || arg != "water")
		return notify_fail("��Ҫװʲô��\n");

	if (!environment(me)->query("sljob"))
	{
		return notify_fail("����ط�û��ˮ����ô��ˮ��\n");
	}

	else if ( this_player()->is_busy() )
	{
		return notify_fail("����һ��������û����ɡ�\n");
	}

	else if (ob->query("job"))
	{
		return notify_fail("ˮͰ���Ѿ�������ˮ����\n");
	}

	else
	{
		message_vision(CYN"$N��ˮͰ�ŵ�Ϫ�д�����ˮ��\n"NOR, me);
		if (random(100)>5)
		{
			ob->set("job",1);
			ob->set("long","һ��������ˮ��ˮͰ��\n");
			if (me->query_temp("job") == 1)
				me->set_temp("job", 2);
			return 1;
		}
		else
		{
			message_vision(CYN"��ѽ��$Nһ����С��û��վס��ˤ��һ����ͷ��Ͱ��Ȼ��ˮƯ���ˡ�\n"NOR, me);
			me->set_temp("job",3);
			destruct(ob);
			return 1;
		}
	}
	return 1;
}

int do_dao(string arg)
{
	object ob, me;
	me = this_player();
	ob = this_object();

	if (!arg || arg != "water")
		return notify_fail("��Ҫ��ʲô��\n");

	else if (!ob->query("job"))
		return notify_fail("Ͱ��ûˮ�㵹ʲô��\n");

	else if (!environment(me)->query("sljob2"))
		return notify_fail("����ط�û�иף���Ҫ��ˮ�������\n");

	else if ( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");

	message_vision(HIW"$N��ˮͰ���ˮ����һ��������ˮ���Ȼ���Ͱ����һ�ߡ�\n"NOR, me);

	if (me->query_temp("job", 2))
	{
		message_vision("����˲��������˹������������ˡ�\n", me);
		me->add("potential", 50+random(50));
		me->add("combat_exp", 80+random(70));
		me->delete_temp("job");
	}

	destruct(ob);
	return 1;
}