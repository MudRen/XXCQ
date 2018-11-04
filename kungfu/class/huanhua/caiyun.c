// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;
void recover_ob();
#include <ansi.h>

void create()
{
	set_name("����", ({"cai yun", "cai", "yun"}));
	set("gender", "Ů��");
	set("age", 25);
	set("long", 
		"����佻������Ĵ���������Ư����һ����Ҳ��佻���ʮ��ᡱ֮һ��\n");
	set("attitude", "peaceful");
	set("title", "佻����ɵ��Ĵ����ӡ�"HIC"ʮ���"NOR);
	set("str", 16);
	set("int", 15);
	set("con", 20);
	set("dex", 24);
	set("bac", 25);

	set("qi", 1700);
	set("max_qi", 1700);
	set("jingli", 1100);
	set("max_jingli", 1100);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jiali", 10);
	
	set("combat_exp", 200000);
	set("shen", 1000);
	
	set_skill("force", 100);
	set_skill("jiuqu-xinfa", 100); 
	set_skill("strike", 110);
	set_skill("feixu-zhang", 110);
	set_skill("dodge", 120); 
	set_skill("huanhua-shenfa", 120); 
	set_skill("sword", 110); 
	set_skill("huanhua-jian", 110); 
	set_skill("parry", 100); 
	set_skill("confu", 100); 
	set_skill("literate", 110); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("sword", "huanhua-jian");
	map_skill("parry", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 4, "����");

	setup();

	carry_object("/d/huanhua/npc/obj/liangongfu")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mantian" :),
		(: perform_action, "sword.luanhong" :),
		(: perform_action, "strike.fenfei" :),
		(: recover_ob :)
	}) );
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

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
	{
		command("shake " + ob->query("id"));
		command("say ����ֻ������佻��ͱ����ӣ��㲻��佻����ӣ��Ҳ������㡣");
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
		command("say ����ͬ�����ӣ�����Ϊʦ�����Ǻ��ҿ���Ц�ɣ�");
		command("xixi");
		return;
	}

	if ( ob->query_skill("huanhua-jian",1) < 50
		||ob->query_skill("huanhua-shenfa",1) < 50
		||ob->query_skill("jiuqu-xinfa",1) < 50)
	{
		command("say 佻�������佻����������ķ�������佻�����������Ĺ������ˮƽ�ò�����");
		command("say ������һЩ�������Ұɡ�");
		return;
	}

	if (ob->query("gender")=="����")
	{
		command("say ��ֻ��Ů���ӣ���Ҫ��ʦ��ȥ���Ұ���ʦ�ְɡ�");
		return;
	}

	command("say ��Ȼ��Ĺ����Ѿ�����һ���ĸ��ף����Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));

	return;
}