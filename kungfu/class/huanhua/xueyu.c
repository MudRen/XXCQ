// xueyu ��ѩ��
// By load

inherit NPC;
inherit F_MASTER;

void heal_ob();
void recover_ob();
#include <ansi.h>

void create()
{
	set_name("��ѩ��", ({"xiao xueyu", "xiao", "xueyu"}));
	set("gender", "Ů��");
	set("nickname", HIC"��ѩ����"NOR);
	set("age", 23);
	set("long", 
"����һ����Ц��Ů���ӣ���Ȼ����ȥ�������һ�����棬����ʵ��\n"
"��ѩ����������˫ȫ������������ü��\n"
"����佻�������������¥��СŮ����һֱ�����Ž�®������\n");
	set("attitude", "peaceful");
	set("str", 17);
	set("int", 23);
	set("con", 16);
	set("dex", 20);
	set("bac", 24);

	set("qi", 2200);
	set("max_qi", 2200);
	set("jingli", 1400);
	set("max_jingli", 1400);
	set("neili", 1600);
	set("max_neili", 1600);
	set("jiali", 50);
	
	set("combat_exp", 600000);
	set("shen", 20000);
	
	set_skill("force", 140);
	set_skill("jiuqu-xinfa", 140); 
	set_skill("strike", 140);
	set_skill("feixu-zhang", 140);
	set_skill("dodge", 160); 
	set_skill("huanhua-shenfa", 160); 
	set_skill("sword", 140); 
	set_skill("parry", 140); 
	set_skill("literate", 140); 
	set_skill("confu", 140);
	set_skill("huanhua-jian", 140); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jian");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 3, "����");

	setup();

	carry_object("/d/huanhua/npc/obj/shaqun")->wear();
	carry_object("/d/huanhua/npc/obj/ruanxiang")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance", 3);
	set("chat_msg", ({
		(: heal_ob :),
		"��ѩ��ͻȻ����һ��Ц����������֪���뵽��ʲô���¡�\n",
		"��ѩ��תͷ������һ�ۣ�ȴ�ƺ�û�п���һ�����ٴλع�ͷ����������\n",
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

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
	{
		command("look " + ob->query("id"));
		command("say �Ҵ���û�����㣬����Ϊʦ�����ǿ���Ц�ɡ�");
		command("giggle");
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

	if (ob->query("shen")<40000)
	{
		command("say ��ά�����������������ò������һ��������㡣");
		command("addoil " + ob->query("id"));
		return;
	}

	if (ob->query_int()<26)
	{
		command("shake " + ob->query("id"));
		command("say �㿴����һ��Ҳ���������ҿɲ�Ը����㣬�������˰ɡ�");
		return;
	}

	if (ob->query_skill("sword",1)< 80 || ob->query_skill("huanhua-jian",1) < 80)
	{
		command("say ����佻������Խ���Ϊ�������Ƿ�Ӧ���ڽ����������Щ�����أ�");
		return;
	}

	if (ob->query("gender")=="����")
	{
		command("say ��ֻ��Ů���ӣ���Ҫ��ʦ��ȥ���Ҷ��翪��ɡ�");
		return;
	}

	command("say �ðɣ���������ɣ������ҵĹ���ɲ����ҵĸ���Ǻ��ϡ�");
	command("recruit " + ob->query("id"));

	return;
}