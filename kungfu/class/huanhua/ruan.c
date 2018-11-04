// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
void recover_ob();

void create()
{
	set_name("������", ({"ruan xingyue", "ruan", "xingyue"}));
	set("nickname", CYN"Ȯ���鳤"NOR);
	set("gender", "����");
	set("age", 26);
	set("long", 
		"����һ�������������ˣ���Ĳ����˸�ž�������飬Ȯ���ڽ�®�縺�����������Ρ�\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("bac", 20);

	set("qi", 1200);
	set("max_qi", 1200);
	set("jingli", 700);
	set("max_jingli", 700);
	set("neili", 800);
	set("max_neili", 800);
	
	set("combat_exp", 80000);
	set("score", 5000);
	
	set_skill("force", 70);
	set_skill("jiuqu-xinfa", 70); 
	set_skill("strike", 70);
	set_skill("feixu-zhang", 70);
	set_skill("dodge", 70); 
	set_skill("huanhua-shenfa", 70); 
	set_skill("sword", 70); 
	set_skill("parry", 70); 
	set_skill("literate", 70); 
	set_skill("confu", 60); 
	set_skill("huanhua-jian", 70); 

	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jian");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 5, "����");

	setup();

	carry_object("/d/huanhua/npc/obj/jinpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: recover_ob :)
	}) );
	set("add_title","佻���®Ȯ����Ա");
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

	if (ob->query("combat_exp")<10000
		|| ob->query_skill("huanhua-shenfa",1)<40
		|| ob->query_skill("dodge",1)<40)
	{
		command("say ���в��У��㹦��̫�ɱ���˵��˷���������ɱ����ô�죿");
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

	command("say �ðɣ�" + RANK_D->query_respect(ob) +"����Ȯ�飬�ͺú�Ϊ��®�����ɡ�");
	command("recruit " + ob->query("id"));
	ob->set("title", "佻����ɵ��������ӡ�"CYN"Ȯ����Ա"NOR);
	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
		ob->set("pay_money", ob->query("age"));

	return;
}