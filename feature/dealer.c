// dealer.c ����
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands

#include <dbase.h>
#include <ansi.h>
inherit NPC;

void setup()
{
	set("no_get",1);
	set("no_get_from",1);
	::setup();
}

int is_dealer()//��CHAR_D�︴��dealer��ʬ��ʱ�����øú����ж��Ƿ�Ҫ�������ϵĶ�����ʬ����
{
	return 1;
}

string is_vendor_good(string arg)
{
	string *goods;
	int i;

	if (arrayp(goods = query("vendor_goods"))) 
		for (i = 0; i < sizeof(goods); i++) 
			if (goods[i]->id(arg))
				return goods[i];
	return "";
}

int do_value(string arg)
{
	object ob;
	int value;

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô�ļۣ�\n");
	
	if (ob->query("money_id"))
		return notify_fail("��û�ù�Ǯ����\n");

	if (userp(ob))
		ob->set("value", ob->query("per") * 500);

	value = ob->query("value");
	if (value < 1)
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else 
		write(ob->query("name") + "ֵ" + 
		MONEY_D->price_str(value * 70 / 100) + "��\n");
	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô��\n");

	if (ob->query("money_id"))
		return notify_fail("��������Ǯ������\n");

	if (stringp(ob->query("no_drop"))||ob->query("no_pawn")||ob->query("nopawn"))
		return notify_fail("����������������\n");

	if (ob->query("item_origin"))
		return notify_fail("�����ǲ������ġ�\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("������ò��ã�\n");

	if (ob->query("food_supply"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
	
	if (ob->query("shaolin"))
		return notify_fail("С��ֻ��һ���Դ����ɲ��������������\n");
	
	if(sizeof(all_inventory(this_object()))>60)
		return notify_fail("С���Ѿ���60�������ˣ�û�취�չ���Ķ����ˣ�\nҪ��������������\n");

	if (userp(ob))
	{
		ob->set("value", ob->query("per") * 500);
		CHANNEL_D->do_channel(ob, "rumor",
			sprintf("%s��ĳ�˹����ˡ�", ob->name(1)));
	}
	else
	if((ob->query("enpawn")==0)//���������Բ�Ϊ0��˵�����ǿ������ģ�
		&&(
			ob->query("hunmi")!=0||living(ob)
			||ob->query_temp("block_msg/all")==1
		)
	)
		return notify_fail("��������ǻ��ѽ������ô����湻�����ˣ�\n");
	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else {
		message_vision("$N������һ" + ob->query("unit") + 
		ob->query("name") + "��$n��\n", this_player(), this_object());
		MONEY_D->pay_player(this_player(), value * 70 / 100);
		if ( userp(ob))
		{
			ob->move("/d/sroom/storage");
			ob->set("startroom","/d/sroom/storage");
			ob->set("jackyboy/selled",1);
		}
		else if (value < 50)
			destruct(ob);
		else
			ob->move(this_object());
	}
	return 1;
}

int do_list()
{
	string *goods,str;
	object *inv,ob;
	mapping tmp;
	int i,j;
	inv = all_inventory(this_object());

	if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
		return notify_fail("Ŀǰû�п������Ķ�����\n");
	tmp=([]);
	printf("�������%s����������Ʒ��\n", query("name"));
	for(i=0;i<sizeof(inv);i++)
	{
		str=replace_string(base_name(inv[i]),"/","\\");
		if(undefinedp(tmp[str]))
			tmp[str]=1;
		else
			tmp[str]++;
	}
	goods=keys(tmp);
	for(i=0;i<sizeof(keys(tmp));i++)
	{
		j=tmp[goods];
		str=replace_string(goods[i],"\\","/");
		ob=new(str);
		if(!objectp(ob))
			continue;
		if (!ob->query("equipped") && !ob->query("money_id"))
		printf("%d%s%30-s��%s\n", j, ob->query("unit"),ob->short(),
		MONEY_D->price_str(ob->query("value") * 6 / 5));
	}
	if (arrayp(goods = query("vendor_goods")))
		for (i = 0; i < sizeof(goods); i++)
			printf("%30-s��%s\n", goods[i]->short(),
			MONEY_D->price_str(goods[i]->query("value")));
	return 1;
}	

int do_buy(string arg)
{
	int val_factor;
	string ob_file;
	object ob;
	if (!arg)
		return notify_fail("������ʲô�� \n");
	else if (!(ob = present(arg, this_object())))
		if ((ob_file = is_vendor_good(arg)) == "")
			return notify_fail("������ʲô�� \n");

	if (!ob) {
		ob = new(ob_file);
		val_factor = 10;
	}
	else {
		if (ob->query("equipped"))
			return notify_fail("������ʲô�� \n");
		val_factor = 12;
	}

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	
	switch (MONEY_D->player_pay(this_player(), ob->query("value") *  val_factor / 10)) {
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
