// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem

inherit F_DEALER;

void create()
{
	set_name("�߼�Ѫ", ({"gao jixue", "gao", "jixue"}));
	set("title", "Ǯׯ�ϰ�");
	set("nickname", "������");
	set("gender", "����");
	set("long",
		"��������ΤѼë�ϳơ���ѪѼë���ĸ߼�Ѫ�����Ǿ�������������\n"
		"�����Ǯׯ�����ھ��ǵ�����֮һ����Ȼ�Ǹ����ˣ����ƺ�Ҳ��Щ\n"
		"��������ӡ�\n");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	"�߼�Ѫ������˵�����������Ѿ����ϰ������ʷ���ھ��ǿ���˵�ǵ�һ�ҡ�\n",
	}));

	set_skill("strike", 100);
	set_skill("dodge", 100);
	set_skill("parry",100);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();
	add_money("gold", 10);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}

void enough_rest()
{
	delete_temp("busy");
}

int do_check()
{
	int total = (int)this_player()->query("balance");
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("���ڱ��̺�û�д�Ǯ��\n");
	}
	write("�߼�Ѫ���ĸ����㣺���ڱ��̺Ź�����" + 
		MONEY_D->money_str(total) + "\n");

	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
		return notify_fail("�����ʽ��convert|duihuan <����> <���ҵ�λ> to <�»��ҵ�λ>\n");
	}

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
	{
		return notify_fail("����һ���ʲô��\n");
	}
	if (!from_ob)
	{
		return notify_fail("������û�д�����Ǯ��\n");
	}
	if (amount < 1)
	{
		return notify_fail("�����׬����\n");
	}
	if ((int)from_ob->query_amount() < amount)
	{
		return notify_fail("�����" + from_ob->query("name") + "������\n");
	}
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	{
		return notify_fail("����������ֵǮ��\n");
	}

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	{
		return notify_fail("��Щ" + from_ob->query("name") + "��������\n");
	}

	// allowed to convert now
	set_temp("busy", 1);	

	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/clone/money/" + to);
		to_ob->set_amount(amount * bv1 * 10 / (bv2 * 10));
		to_ob->move(me);
	}
	else
		to_ob->add_amount(amount * bv1 * 10 / (bv2 * 10));
	
	message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 * 10 / (bv2 * 10)), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

//	from_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

	return 1;
}

int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob, me;

	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("�����ʽ��deposit:cun <����> <���ҵ�λ>\n");
	}

	what_ob = present(what + "_money", me);
	if (!what_ob)
	{
		return notify_fail("������û�д�����Ǯ��\n");
	}
	if (amount < 1)
	{
		return notify_fail("��������" + what_ob->query("name") + "��\n");
	}
	if ((int)what_ob->query_amount() < amount)
	{
		return notify_fail("�����" + what_ob->query("name") + "������\n");
	}
	if( (int)me->query("balance") > 2000000 )
	{
		me->set("balance",2000000);
		return notify_fail("����ǰ��Ķ���200���ƽ��Ǯ���ٸ�û����.\n");
	}
	if( ( (int)me->query("balance") + (int)what_ob->query("base_value")*amount ) >2000000  )
	{	
		return notify_fail("���ܹ�ֻ�ܴ�200���ƽ�! ��check�������Ѿ����˶����˰ɡ� \n");
	}
	set_temp("busy", 1);	

	me->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);
	message_vision(sprintf("$N�ó�%s%s%s����������š�\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}

int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me;

	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");
	}
	if (amount < 1)
	{
		return notify_fail("����ȡ������Ǯ��\n");
	}
	if (file_size("/clone/money/" + what + ".c") < 0)
	{
		return notify_fail("����ȡ��ʲôǮ��\n");
	}
	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
	{
		return notify_fail("����Ǯ����Ȣ��\n");
	}

	set_temp("busy", 1);	

	me->add("balance",  -v);
	MONEY_D->pay_player(me, v = v * 10 / 10);
	
	message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)),
		me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}

int accept_object(object who, object ob)
{
	object obj, sil;
	int i;
	obj = this_object();

	if ((string)ob->query("id") == "dan") 
	{
		if ((string)who->query_temp("goods") != obj->query("name"))
		{
			message_vision("$N�ѵ��ӵݸ�"+obj->query("name")+"���顣\n", who);
			command("? "+who->query("id"));
			command("say ���"+ob->query("name")+"�������������ѽ��");
			command("say �㻹�ǵ���ĵط�ȥ���Ұɡ�");
			command("give dan to "+who->query("id"));
			return 1;
		}
		else if (!(string)who->query_temp("buygoods") || (string)who->query_temp("buygoods") != "begin")
		{
			message_vision("$N�ѵ��ӵݸ�"+obj->query("name")+"���顣\n", who);
			command("? "+who->query("id"));
			command("say ����Ȼ����������ģ����ǡ�������Ų������İɡ�");
			command("say ���ŵ��������������ˣ�ʡ�ù˿�����ʧ��лл���ˡ�");
  			destruct(ob);
			return 1;
		}
		else
		{
			message_vision("$N�ѵ��ӵݸ�"+obj->query("name")+"���顣\n", who);
			command("say ̫���ˣ�̫���ˣ����������ˣ�");
			message_vision(obj->query("name")+"�ù�һ�������˵��ϻ������£�Ȼ������������\n", who);
			message_vision(obj->query("name")+"ת�˽�ȥ��һ���ó�����һ�������ĺ����\n", who);
			message_vision(obj->query("name")+"Ц��Ц˵����������ǽ�®��Ǯ�����պá�\n", who);
			sil = new("/d/huanhua/npc/obj/huo");
			sil->set("name", "����");
			sil->set("long", "���Ǵӱ���Ǯׯȡ���Ĺ�Ǯ��");
			sil->move(who);
			who->set_temp("buygoods", "over");
  			destruct(ob);
			return 1;
		}
	}
	else
	{
		command("say ����������ʲô?");
		return 0;
	}
	
}
