// By ɽèadx @ CuteRabbit 9:32 99-6-21
// ����ϵͳ ֮ ��͢
// int do_kou1(string arg) ��9-7Ʒ��
// int do_kou2(string arg) ��6-2Ʒ��
// int do_chiguan(string arg) �ǹ�
// int do_sheng(string arg) ����ҵĹ���
// int do_jiang(string arg) ����ҵĹ���
// int do_diao(string arg) ��Ʒ���Ϲٿ��Ե�������
// int do_ling(string arg) ��Աÿ�������һ��нٺ
// int do_tongji(string arg) ͨ��ĳ��
// int do_tongji(string arg) ���ͨ��ĳ��
// int do_jina(string arg) �����Ĵ���������Ҫ��

int do_kou1(string arg)
{
	object me;
	int i, rank;

	me = this_player();
	i = me->query("weiguan");
	rank = me->query("bhrank");

	if(!id(arg)) {
		return notify_fail("�����������ߵͷ������\n");
	}

	message_vision("$N�����������������ؿ��˸���ͷ��\n", me);

	if( i>=50 && me->query("banghui")!="��͢" ) {
		me->set("banghui", "��͢");
		me->set("bhrank", 9);
		command("ok");
		command("say ��ȥ��������ĵ�һ��нٺ�ɣ�");
		return notify_fail(HIC"�������ǳ�͢�����ˣ�\n"NOR);
	}

	if( rank==9 && i>=250 && me->query("banghui")=="��͢" ) {
		me->set("bhrank", 8);
		command("ok");
		return notify_fail(HIC"��ϲ����ϲ���������ˣ�\n"NOR);
	}

	if( rank==8 && i>=1250 && me->query("banghui")=="��͢" ) {
		me->set("bhrank", 7);
		command("rumor "+me->name()+"������Ϊ�ٸ���Ʒ�ᶽඡ�����");
		command("ok");
		return notify_fail(HIC"��ϲ����ϲ���������ˣ�\n"NOR);
	}

	if( rank==7 && i>=50000 && me->query("banghui")=="��͢" ) {
		me->set("bhrank", 6);
		command("rumor "+me->name()+"�������ٸ���Ʒ�ܱ�ඡ�����");
		command("ok");
		return notify_fail(HIC"��ϲ����ϲ���������ˣ�\n"NOR);
	}

	if( rank==5 && rank==4 && me->query("banghui")=="��͢" ) {
		command("bow "+me->query("id"));
		command("say ��λ������˶���");
		return 1;
	}

	if( rank<=3 && me->query("banghui")=="��͢" ) {
		command("bow "+me->query("id"));
		command("say ���˺α���ˣ���ɱ�¹��ˣ�");
		return 1;
	}
	else
		command("pat "+me->query("id"));
		command("say �Ժ����Ҫ���ö�ߵͷ��");
		return 1;
}

int do_kou2(string arg)
{
	object me;
	int i, rank;

	me = this_player();
	i = me->query("weiguan");
	rank = me->query("bhrank");

	if(!id(arg)) {
		return notify_fail("�����������ߵͷ������\n");
	}

	message_vision("$N�����������������ؿ��˸���ͷ��\n", me);

	if( rank==6 && i>=200000 && me->query("banghui")=="��͢" ) {
		me->set("bhrank", 5);
		command("rumor "+me->name()+"������Ϊ������Ʒƫ��ඡ�����");
		command("ok");
		return notify_fail(HIC"��ϲ����ϲ���������ˣ�\n"NOR);
	}

	if( rank==5 && i>=800000 && me->query("banghui")=="��͢" ) {
		me->set("bhrank", 4);
		command("rumor "+me->name()+"������Ϊ������Ʒ����ඡ�����");
		command("ok");
		return notify_fail(HIC"��ϲ����ϲ���������ˣ�\n"NOR);
	}

	if( rank==4 && i>=2000000 && me->query("banghui")=="��͢" ) {
		me->set("bhrank", 3);
		command("rumor "+me->name()+"������Ϊ������Ʒ�Ͻ���ඡ�����");
		command("ok");
		return notify_fail(HIC"��ϲ����ϲ���������ˣ�\n"NOR);
	}

	if( rank==3 && i>=6000000 && me->query("banghui")=="��͢" ) {
		me->set("bhrank", 2);
		command("rumor "+me->name()+"���γ�͢��Ʒ�󽫾�ඡ�����");
		command("ok");
		return notify_fail(HIC"��ϲ����ϲ���������ˣ�\n"NOR);
	}

	if( rank==2 && i>=18000000 && me->query("banghui")=="��͢" ) {
		me->set("bhrank", 1);
		command("rumor "+me->name()+"���γ�͢һƷ��Ԫ˧ඡ�����");
		command("rumor gongxi");
		command("ok");
		return notify_fail(HIC"��ϲ����ϲ���������ˣ�\n"NOR);
	}

	if( rank==2 && me->query("banghui")=="��͢" ) {
		command("say ��λ������˶���");
		return 1;
	}

	if( rank==1 && me->query("banghui")=="��͢" ) {
		command("say ��������С�����ҵ������ҵ�����");
		return 1;
	}

	else
		command("nod "+me->query("id"));
		return 1;
}

int do_chiguan(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("��Ҫ��˭�ǹ٣�\n");

	if(me->query("banghui")!="��͢")
		return notify_fail("������Ͳ��ǳ�͢��Ա��Ҫ��ʲô��\n");

	write("��ȷ�����Ҫ�ǹ���(Yy)(Nn)��\n");
	input_to("get_gift", me);
	return 1;
}

void get_gift(string yn, object me)
{
	if (yn[0] == 'y' || yn[0] == 'Y')
	{
		me->delete("banghui");
		me->delete("bhrank");
		me->delete("weiguan");
		command("sigh "+me->query("id"));
		command("say �ðɣ�"+me->name()+
		"��������Ҳ���ǳ�͢��Ա�ˣ�");
		command("rumor "+me->name()+"��ȥ�˳�͢��ְ��");
		command("rumor �غ���������ʹʧ���������������ç��");
	}
	else {
		command("say �ðɣ�"+me->name()+"����ͼ���Ϊ��͢Ч���ɣ�");
	}
}

int do_sheng(string arg)
{
	object ob, me;
	int i, inv;

	me = this_player();
	i = me->query("bhrank");

	if(me->query("banghui")!="��͢" || i>4)
		return notify_fail("��͢��ӡ��Ҳ��������������\n");

	if( !arg )
		return notify_fail("ָ���ʽ��sheng <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob)
		return notify_fail("����û����ˡ�\n");

	if (ob==me)
		return notify_fail("���Լ��Ĺ��Σ���������治��\n");

	inv = ob->query("bhrank");
	if(ob->query("banghui")=="��͢" && i>=inv)
		return notify_fail("�Է��Ĺ�ְ������ͣ�����ô���ԡ���\n");

	if(ob->query("banghui")!="��͢")
		return notify_fail("�Է����ǳ�͢��Ա��ô�����أ�\n");

	if( (i==4 && inv>8) || (i==3 && inv>6)
		|| (i==2 && inv>4) || (i==1 && inv>2) )
	{
		ob->add("bhrank", -1);
	        message_vision(YEL"$N�������$n����һ����\n"NOR, me, ob);
		command("rumor "+me->query("name")+"����"+
			ob->query("name")+"����һ����");
		return 1;
	}
	else
		return notify_fail("����Ȩ��ô����\n");
}

int do_jiang(string arg)
{
	object ob, me;
	int i, inv;

	me = this_player();
	i = me->query("bhrank");

	if(me->query("banghui")!="��͢" || i>4)
		return notify_fail("��͢��ӡ��Ҳ��������������\n");

	if( !arg )
		return notify_fail("ָ���ʽ��jiang <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob)
		return notify_fail("����û����ˡ�\n");

	if (ob==me)
		return notify_fail("��Ҫ���Լ��Ĺ��Σ��ǲ���ȥ�ǹ٣�\n");

	inv = ob->query("bhrank");
	if(ob->query("banghui")=="��͢" && i>=inv)
		return notify_fail("�Է��Ĺ�ְ������ͣ�����ô���ԡ���\n");

	if(ob->query("banghui")!="��͢")
		return notify_fail("�Է����ǳ�͢��Ա��ô��ְ�أ�\n");

	if( (i==4 && inv>=8) || (i==3 && inv>=6)
		|| (i==2 && inv>=4) || (i==1 && inv>=2) )
	{
		ob->add("bhrank", 1);
	        message_vision(YEL"$N���$n����һ����\n"NOR, me, ob);
		command("rumor "+me->query("name")+"��"
			+ob->query("name")+"����һ����");
		if(ob->query("bhrank")==10)
		{
			ob->delete("banghui");
			ob->delete("bhrank");
			message_vision(YEL"$N�����$n��\n"NOR, me, ob);
			command("rumor "+ob->query("name")+"��"
				+me->query("name")+"�����͢�ˣ�");
		}
		return 1;
	}
	else
		return notify_fail("����Ȩ��ô����\n");
}

int do_tongji(string arg)
{
	object ob, me;
	int i;

	me = this_player();
	i = me->query("bhrank");

	if(me->query("banghui")!="��͢" || i>2)
		return notify_fail("��Ҫ��������Ķ�����\n");

	if( !arg )
		return notify_fail("ָ���ʽ��tongji <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob)
		return notify_fail("����û����ˡ�\n");

	if (ob==me)
		return notify_fail("��Ҫͨ���Լ����󱿹ϣ�\n");

	if(ob->query("banghui")=="��͢")
		return notify_fail("����ͨ����͢��Ա��\n");

	if(ob->query("gender")=="����")
		return notify_fail("�������Էֱ���Ů������ץ������\n");

	if(!ob->query_condition("killer"))
	{
		ob->apply_condition("killer", 500);
	        message_vision(YEL"$N����ͨ��$n��\n"NOR, me, ob);
		command("rumor "+me->query("name")+"����ͨ��"
			+ob->query("name")+"�ˣ�");
		return 1;
	}
	else
		return notify_fail(ob->query("name")+"�Ѿ��ڱ�ͨ���ˣ�\n");
}

int do_untongji(string arg)
{
	object ob, me;
	int i;

	me = this_player();
	i = me->query("bhrank");

	if(me->query("banghui")!="��͢" || i>2)
		return notify_fail("��Ҫ��������Ķ�����\n");

	if( !arg )
		return notify_fail("ָ���ʽ��untongji <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob)
		return notify_fail("����û����ˡ�\n");

	if(ob->query_condition("killer"))
	{
		ob->apply_condition("killer", -500);
	        message_vision(YEL"$N������ͨ��$n��\n"NOR, me, ob);
		command("rumor "+me->query("name")+"������ͨ��"
			+ob->query("name")+"�ˣ�");
		return 1;
	}
	else
		return notify_fail(ob->query("name")+"û�б�ͨ������\n");
}

int do_diao(string arg)
{
	object me, bing, obj;
	int rank;

	me = this_player();
	rank = me->query("bhrank");
	obj = new("/d/changan/obj/lingjian");

	if(!arg || (arg != "bing")) {
		return notify_fail("��Ҫ��ʲô������\n");
	}

	if(me->query_temp("diaobing")==1 ||
		me->query_condition("diaobing") )
		return notify_fail("�������Ҫ��������ı���Ҫ������"+
			"��������ͬ�⣡\n����������ָ�Ӳ��ˣ���\n\n");

	if ( me->query("banghui")=="��͢" )
	{
		me->set_temp("diaobing", 1);
		me->apply_condition("diaobing", 1000);
		obj->move(me);

		switch(rank)
		{
			case 1: 
				command("bow "+me->query("id"));
				command("say �ǣ����ˣ������ú������");
				command("say �����ģ���"+me->query("name")+"Ԫ˧ȥ���£�");
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				return 1;
              		case 2: 
				command("bow "+me->query("id"));
				command("say �õĴ��ˣ������ú������");
				command("say �����ģ���"+me->query("name")+"�󽫾�ȥ���£�");
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				return 1;
              		case 3: 
				command("bow "+me->query("id"));
				command("say �У����ˣ������ú������");
				command("say �����ģ���"+me->query("name")+"�Ͻ���ȥ���£�");
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				return 1;
              		case 4: 
				command("say �����ģ���"+me->query("name")+"����ȥ���£�");
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				return 1;
		}
	}
	else
		command("pat "+me->query("id"));
		command("say ����Ȩ���ɾ��ӣ�");
		return 1;
}

int do_ling(string arg)
{
	object me;
	int rank, i, xinfeng;

	me = this_player();
	rank = me->query("bhrank");

	if(!arg||arg!="xinfeng")
		return command("say ����Ҫ��нٺ(xinfeng)��");

	if(me->query("banghui")!="��͢")
		return command("say "+me->name()+
		"������ʲôнٺ���죿");

	if(me->query_condition("xinfeng"))
		return command("say "+me->name()+
		"���Ѿ����нٺ�ˣ�ÿ��ŷ�һ��нٺ�أ�");

	i = me->query("mud_age")/5;
	xinfeng = me->query("wieguan") + i;

	me->apply_condition("xinfeng", 5760);
	me->add("balance", xinfeng);
	command("say �ðɣ�"+me->name()+
	"������нٺ��"+MONEY_D->price_str(xinfeng)+
	"��Ǯ�Ѿ�����Ǯׯ����ʻ��ˣ�");
	return 1;
}
