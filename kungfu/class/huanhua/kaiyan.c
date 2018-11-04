// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void heal_ob();
void recover_ob();

void create()
{
	set_name("������", ({"xiao kaiyan", "xiao", "kaiyan"}));
	set("gender", "����");
	set("age", 26);
	set("long", 
"����һ���ǳ�Ӣ���������ˣ�һ���Դ�����������¶��һ˿������Ц�ݡ�\n"
"����佻�������������¥�Ĵ��ӡ�����֮ǿֱ׷�丸��\n");
	set("attitude", "peaceful");
	set("str", 15);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("bac", 25);

	set("qi", 2600);
	set("max_qi", 2600);
	set("jingli", 1800);
	set("max_jingli", 1800);
	set("neili", 2100);
	set("max_neili", 2100);
	set("jiali", 50);
	
	set("combat_exp", 800000);
	set("score", 20000);
	
	set_skill("force", 150);
	set_skill("jiuqu-xinfa", 150); 
	set_skill("strike", 150);
	set_skill("feixu-zhang", 150);
	set_skill("dodge", 150); 
	set_skill("huanhua-shenfa", 150); 
	set_skill("sword", 170); 
	set_skill("parry", 150); 
	set_skill("literate", 150); 
	set_skill("huanhua-jian", 170); 
	set_skill("confu", 120); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jian");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 3, "����");

	setup();

	carry_object("/d/huanhua/npc/obj/jinpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance", 3);
	set("chat_msg", ({
		(: heal_ob :),
		"������ͻȻ������üͷ���ƺ��뵽��ʲô�Ѱ�����顣\n",
		"����������̾�˿���������֪�������ô���ˡ���\n",
	}));

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mantian" :),
		(: perform_action, "sword.luanhong" :),
		(: perform_action, "strike.fenfei" :),
		(: recover_ob :)
	}) );
}

void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	string title;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	title = ob->query("title");

	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
	{
		command("say " + RANK_D->query_respect(ob) +"������佻�����������������ʦ�ִӺ�˵���أ�");
		return;
	}

	if ((int)ob->query("shen") <= (-100))
	{
		command("say ����Ϊ佻�����ȴ���������壬����ħ������佻��ݲ����㣡");
		command("kaichu "+ob->query("id"));
		return;
	}

	if ( ob_fam["generation"] == my_fam["generation"] )
	{
		command("say ������ͬ�����ӣ��д��д赹�ǿ��ԣ���ʦȴ���ҵ���");
		return;
	}

	if (ob->query("shen")<50000)
	{
		command("say ��ά�����������������ò������һ��������㡣");
		command("addoil " + ob->query("id"));
		return;
	}

          if (ob->query_bac()<20)
	{
		command("shake " + ob->query("id"));
		command("say �ҿ����������������д�ɣ��Ҳ������㡣");
		return;
	}

	if (ob->query_skill("sword",1)< 90 || ob->query_skill("huanhua-jian",1) < 90)
	{
		command("say ����佻������Խ���Ϊ�������Ƿ�Ӧ���ڽ����������Щ�����أ�");
		return;
	}

	command("say �ðɣ�" + RANK_D->query_respect(ob) +"��Ȼ����Ϊʦ������Ŭ��������������Ϊ���������һ��������");
	command("recruit " + ob->query("id"));

	return;
}
