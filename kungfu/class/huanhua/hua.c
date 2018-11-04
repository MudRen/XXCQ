// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
void recover_ob();

void create()
{
	set_name("����", ({"hua ling", "hua", "ling"}));
	set("nickname", HIM"�����鳤"NOR);
	set("gender", "Ů��");
	set("age", 22);
	set("long", 
		"����һ����С��һ����Ů���ӣ�һ�ż��������¶�����������ݡ�\n");
	set("attitude", "peaceful");
	set("str", 12);
	set("int", 24);
	set("con", 20);
	set("dex", 24);
	set("bac", 20);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jingli", 600);
	set("max_jingli", 600);
	set("neili", 700);
	set("max_neili", 700);
	
	set("combat_exp", 70000);
	set("score", 4000);
	
	set_skill("force", 50);
	set_skill("jiuqu-xinfa", 50); 
	set_skill("strike", 50);
	set_skill("feixu-zhang", 50);
	set_skill("dodge", 50); 
	set_skill("huanhua-shenfa", 50); 
	set_skill("sword", 50); 
	set_skill("parry", 50); 
	set_skill("literate", 50); 
	set_skill("confu", 50); 
	set_skill("huanhua-jian", 50); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jian");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 5, "����");

	setup();

	carry_object("/d/huanhua/npc/obj/liangongfu")->wear();
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

	if (ob->query("gender")=="����")
	{
		command("say ����ֻ��Ů���ӣ���Ҫ��ʦ��ȥ��������ɡ�");
		return;
	}

	command("say �ðɣ�" + RANK_D->query_respect(ob) +"���ҷ��飬�ͺú�Ϊ��®�����ɡ�");
	command("recruit " + ob->query("id"));
	ob->set("title", "佻����ɵ��������ӡ�"HIM"������Ա"NOR);
	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
		ob->set("pay_money", ob->query("age"));

	return;
}