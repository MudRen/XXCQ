// wei.c Τ�ϰ� 

inherit F_DEALER;


void create()
{
	set_name("ΤѼë", ({ "wei yamao", "wei" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);
        set("nickname","һʱ���");
	set("gender", "����");
	set("age", 45);
	set("long",
		"��������߼�Ѫ�ϳơ���ѪѼë����ΤѼë��������ЩС��Ʒ����\n"
		"˵������һ�ָ߳���׭�̺���ġ������\n");
	set_skill("strike", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/gangdao",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
	object obj, sil;
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
			message_vision(obj->query("name")+"ת�˽�ȥ��һ�����һ����ƿ�����һ���������\n", who);
			message_vision(obj->query("name")+"Ц��Ц˵����������ǽ�®�Ļ������պá�\n", who);
			sil = new("/d/huanhua/npc/obj/huo");
			sil->set("name", "�ճ���Ʒ");
			sil->set("long", "���Ǵӱ����ӻ���ȡ�����ճ���Ʒ��");
			sil->move(who);
			who->set_temp("buygoods", "over");
  			destruct(ob);
//			command("drop dan");
			return 1;
		}
	}
	else
	{
		command("say ����������ʲô?");
		return 0;
	}
	
}
