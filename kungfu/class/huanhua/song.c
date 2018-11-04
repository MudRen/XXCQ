// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
void recover_ob();

void create()
{
	set_name("�η�", ({"song fei", "song", "fei"}));
	set("nickname", HIC"ӥ���鳤"NOR);
	set("gender", "����");
	set("age", 26);
	set("long", 
		"����һ���ǳ�Ӣ���������ˣ�һ�ż��������¶����������ݡ�\n");
	set("attitude", "peaceful");
	set("str", 15);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("bac", 20);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jingli", 700);
	set("max_jingli", 700);
	set("neili", 700);
	set("max_neili", 700);
	
	set("combat_exp", 70000);
	set("score", 300);
	
	set_skill("force", 40);
	set_skill("jiuqu-xinfa", 40); 
	set_skill("strike", 40);
	set_skill("feixu-zhang", 40);
	set_skill("dodge", 40); 
	set_skill("huanhua-shenfa", 40); 
	set_skill("sword", 40); 
	set_skill("parry", 40); 
	set_skill("literate", 40); 
	set_skill("confu", 40); 
	set_skill("huanhua-jian", 40); 

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 5, "����");

	setup();

	carry_object("/d/huanhua/npc/obj/jinpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
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

	if (ob->query("killding"))
	{
		command("say �󵨿�ͽ������Ӳ���������������ɣ�");
		me->kill_ob(ob);
		ob->kill_ob(me);
		return;
	}

	if ((int)ob->query("shen") <= (-100))
	{
		if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
		{
			command("hmm");
			command("say 佻��������������ɣ���������аħ������㻹����������®������");
			return;
		}
		else
		{
			command("say ����Ϊ佻�����ȴ���������壬����ħ������佻��ݲ����㣡");
			command("kaichu "+ob->query("id"));
			return;
		}
	}

	if ((!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����") && (int)ob->query("combat_exp")>20000)
	{
		command("say "+RANK_D->query_respect(ob)+"���ǽ�������֮ʿ�������ĸ�������");
		command("say �Բ����ˣ�����ذɡ�");
		return;
	}

	if ( my_fam )
	{
		if ( my_fam["family_name"] == "佻�����" )
		{
			if ( ob_fam["generation"] == my_fam["generation"] )
			{
				command("say ������ͬ�����ӣ��д��д赹�ǿ��ԣ���ʦȴ�ǴӺ�˵��");
				return;
			}
	
			if ( ob_fam["generation"] > my_fam["generation"] )
			{
				message_vision("$Nһ���ĳϻ̳Ͽֵ����������ӷ���ʲô����Ҫ�͵��ӿ���������Ц��\n", me);
				return;
			}
		}
	}

	command("say �ðɣ�" + RANK_D->query_respect(ob) +"��Ȼ����Ϊʦ������Ŭ��������������Ϊ���������һ��������");
	command("recruit " + ob->query("id"));
	ob->set("title", "佻����ɵ��������ӡ�"HIC"ӥ����Ա"NOR);
	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
		ob->set("pay_money", ob->query("age"));

	return;
}