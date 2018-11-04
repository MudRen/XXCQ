// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void recover_ob();

void create()
{
	set_name("����", ({"bai yun", "bai", "yun"}));
	set("gender", "����");
	set("age", 25);
	set("long", 
"����佻������Ĵ��������������һ����Ҳ��佻���ʮ��ᡱ֮һ��
��������������ͽ�������Ĵ�����֮һ��\n");
	set("attitude", "peaceful");
	set("title", "佻����ɵ��Ĵ����ӡ�"HIC"ʮ���"NOR);
	set("str", 25);
	set("int", 20);
	set("con", 18);
	set("dex", 22);
	set("bac", 15);

	set("qi", 1900);
	set("max_qi", 1900);
	set("jingli", 1200);
	set("max_jingli", 1200);
	set("neili", 1400);
	set("max_neili", 1400);
	set("jiali", 25);
	
	set("combat_exp", 300000);
	set("shen", 5000);
	
	set_skill("force", 110);
	set_skill("jiuqu-xinfa", 110); 
	set_skill("strike", 120);
	set_skill("feixu-zhang", 120);
	set_skill("dodge", 110); 
	set_skill("huanhua-shenfa", 110); 
	set_skill("sword", 120); 
	set_skill("huanhua-jian", 120); 
	set_skill("parry", 100); 
	set_skill("confu", 90); 
	set_skill("literate", 90); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("sword", "huanhua-jian");
	map_skill("parry", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");

	setup();

	create_family("佻�����", 4, "����");

	carry_object("/d/huanhua/npc/obj/jinpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mantian" :),
		(: perform_action, "sword.luanhong" :),
		(: perform_action, "strike.fenfei" :),
		(: recover_ob :)
	}) );
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	mapping my_fam;

	if( !ob || environment(ob) != environment() ) return;

	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
		command("welcome "+ob->query("id"));

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



	if ( ob->query_skill("huanhua-jian",1) < 60
		||ob->query_skill("huanhua-shenfa",1) < 60
		||ob->query_skill("jiuqu-xinfa",1) < 60)
	{
		command("say 佻�������佻����������ķ�������佻�����������Ĺ������ˮƽ�ò�����");
		command("say ������һЩ�������Ұɡ�");
		return;
	}

	command("say ��Ȼ��Ĺ����Ѿ�����һ���ĸ��ף����Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));

	return;
}
