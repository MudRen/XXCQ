// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void recover_ob();
void away();

void create()
{
	set_name("������Ա", ({"zuyuan"}));
	set("gender", "����");
	set("age", 26);
	set("long", 
		"����һ���ǳ�Ӣ���������ˣ�һ���Դ�����������¶��һ˿������Ц�ݡ�\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 40);

	set("qi", 1200);
	set("max_qi", 1200);
	set("jingli", 600);
	set("max_jingli", 600);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	
	set("combat_exp", 700000);
	set("score", 20000);
	
	set_skill("force", 140);
	set_skill("jiuqu-xinfa", 140); 
	set_skill("strike", 130);
	set_skill("feixu-zhang", 130);
	set_skill("cuff",120);
	set_skill("tiexian-quan",120);
	set_skill("dodge", 150); 
	set_skill("huanhua-shenfa", 150); 
	set_skill("sword", 150); 
	set_skill("parry", 130); 
	set_skill("literate", 120); 
	set_skill("huanhua-jian", 150); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("cuff", "tiexian-quan");
	map_skill("parry", "huanhua-jian");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	prepare_skill("cuff", "tiexian-quan");
	
	create_family("佻�����", 5, "����");

	setup();

	carry_object(__DIR__"obj/jinpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance", 20);
	set("chat_msg", ({
		(: away :),
	}));

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mantian" :),
		(: perform_action, "strike.fenfei" :),
		(: perform_action, "cuff.chong" :),
		(: recover_ob :)
	}) );

}

void recover_ob()
{
	command("yun recover");
	return;
}

void away()
{
	if( living(this_object()) )
	{
		message_vision("������Ա����ææ���߿��ˡ�\n", this_object());
		destruct(this_object());
	}
	return;
}