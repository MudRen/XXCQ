// shang.c ��̫ʦ

inherit F_DEALER;

void create()
{
	set_name("��̫ʦ", ({ "shang taishi", "shang", "taishi" }));
	set("title", "�ش����ϰ�");
	set("gender", "����");
	set("long", "�����Ǿ�������������ҽ��̫ʦ����˵�����ڹ���������ҽ��\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 200);
	set("max_qi", 200);
	set("jing", 200);
	set("max_jing", 200);
	set("shen_type", 1);

	set("combat_exp", 2000);
	set("attitude", "heroism");

	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);

	set("vendor_goods", ({
	}));

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
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
			sil->set("name", "ҩ��");
			sil->set("long", "���Ǵӱ����ش���ȡ����ҩ�ġ�");
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
