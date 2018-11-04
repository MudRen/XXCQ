// NPC ���
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���", ({ "huo ji", "huo", "ji" }) );
	set("title", HIB"ҩ����"NOR+YEL"����"NOR);
	set("gender", "����" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");

	set("no_clean_up", 1);
	setup();
        add_money("silver", 5);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob = this_player();

	add_action("do_sell", "����");
	add_action("do_sell", "jishou");
	add_action("do_buy", "buy");
	add_action("do_list", "list");

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int greeting(object ob)
{
	if((string)ob->query("party/party_name")==HIB"ҩ����"NOR) {
	command("say ��λ�ֵ����ˣ�����ҩƷ�ø��Ҽ�����(ָ���ʽ������ xxx)\n");
		return 1;}
	else {
	switch( random(4) ) {
		case 0:
			command("bow "+ob->query("id"));
			command("say "+RANK_D->query_respect(ob)
		+"���������ҩ���ȵ��Ӿ������Ƶĳ�ҩ��ҩЧ������\n");
			break;
		case 1:
			command("nod "+ob->query("id"));
			command("say "+RANK_D->query_respect(ob)
		+"���������ҩ���ȵ��Ӿ������Ƶĳ�ҩ��ҩЧ������\n");
			break;
		case 2:
			command("hi "+ob->query("id"));
			command("say "+RANK_D->query_respect(ob)
		+"���������ҩ���ȵ��Ӿ������Ƶĳ�ҩ��ҩЧ������\n");
			break;
		case 3:
			command("welcome "+ob->query("id"));
			command("say "+RANK_D->query_respect(ob)
		+"���������ҩ���ȵ��Ӿ������Ƶĳ�ҩ��ҩЧ������\n");
			break;
		}
	}
}

int do_sell(string arg)
{
	object ob;
	int i;
	int count;
	int value;
	object *inv;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ����ʲô������\n");

	if (!ob->query("yaowang"))
		return notify_fail("�������������������ۣ�\n");

	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else {
		message_vision("$N�ó�һ" + ob->query("unit") + 
		ob->query("name") + "��$n���ۡ�\n", this_player(), this_object());
		MONEY_D->pay_player(this_player(), value * 90 / 100);
		if ( userp(ob))
		{
			ob->move("/d/city/cangku");
                        ob->set("startroom","/d/city/cangku");
			ob->set_temp("selled");
			ob->save();
		}
		else if (value < 50)
			destruct(ob);
		else
		{
			inv = all_inventory(this_object());
			count=0;
			for (i = 0; i < sizeof(inv); i++)
			{
				if (inv[i]->short()==ob->short())
					count++;
			}
			if (count<500)
				ob->move(this_object());
			else
				destruct(ob);
		}
	}
	return 1;
}

int do_list()
{
	string *goods;
	object *inv;
        object *inv1;
        int *count;
	int i;
	int j;

	inv = all_inventory(this_object());

	if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
		return notify_fail("Ŀǰ����û�ж������ۡ�\n");
	for (i = 0; i < sizeof(inv); i++) 
	{
		if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
		{
			if (!arrayp(inv1))
			{
				inv1=({inv[i]});
				count=({1});
			}
			else
			{
				for (j = 0; j < sizeof(inv1); j++)
					if (inv[i]->short()==inv1[j]->short())
						break;
				if (j == sizeof(inv1))
				{
					inv1+=({inv[i]});
					count+=({1});
				}
				else
					count[j]+=1;
			}
		}
	}
	
	printf("%s���ڼ��۳�����Ʒ��\n", query("name"));

	for (i = 0; i < sizeof(inv1); i++) 
		printf("%30-s��������%3-i %s\n", inv1[i]->short(),
		count[i],
		MONEY_D->price_str(inv1[i]->query("value") ));
	if (arrayp(goods = query("vendor_goods")))
		for (i = 0; i < sizeof(goods); i++)
			printf("%30-s��%s\n", goods[i]->short(),
			MONEY_D->price_str(goods[i]->query("value")));
	return 1;
}	

int do_buy(string arg)
{
	string ob_file;
	object ob;

	if (!arg)
		return notify_fail("������ʲô�� \n");

	if (!(ob = present(arg, this_object())))
			return notify_fail("������ʲô�� \n");

	if (!ob) {
		ob = new(ob_file);
	}
	else {
		if (ob->query("equipped"))
			return notify_fail("������ʲô�� \n");
	}

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	
	switch (MONEY_D->player_pay(this_player(), ob->query("value"))) {
	case 0:
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
        	set_temp("busy", 1);
		message_vision("$N��$n����������һ" + ob->query("unit") + 
		ob->query("name") + "��\n", this_player(), this_object());
		ob->move(this_player());

	}
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

	return 1;
}

void enough_rest()
{
        delete_temp("busy");
}
