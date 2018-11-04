// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
void recover_ob();
int accept_object(object who, object ob);
int ask_job();
void create()
{
	set_name("����ľ", ({"li zimu", "li", "zimu"}));
	set("nickname", HIR"�����鳤"NOR);
	set("gender", "����");
	set("age", 26);
	set("long", 
		"����һ���ǳ����ɵ������ˣ���Ϊ�����鳤�����Ž�®���������⡣\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 30);
	set("con", 20);
	set("dex", 15);
	set("bac", 15);

	set("qi", 700);
	set("max_qi", 700);
	set("jingli", 400);
	set("max_jingli", 400);
	set("neili", 500);
	set("max_neili", 500);
	
	set("combat_exp", 40000);
	set("score", 2000);
	
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
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jian");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 5, "����");

        set("inquiry", ([
                "job" : (: ask_job :),
        ]) );

	setup();

	carry_object("/d/huanhua/npc/obj/jinpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	add_money("silver", 5+random(5));

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
	ob->set("title", "佻����ɵ��������ӡ�"HIR"������Ա"NOR);
	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "佻�����")
		ob->set("pay_money", ob->query("age"));

	return;
}

int ask_job()
{
	mapping myfam, quest;
	object me, ob;
	string title;

	me = this_player();
	myfam = me->query("family");
	title = me->query("title");
	quest = "/d/huanhua/quest/liquest"->query_quest();

	if ( !myfam || myfam["family_name"] != "佻�����" )
	{
		command("ah "+me->query("id"));
		command("say �㲻������佻���®���ˣ�������ô�������Ĵ���أ�");
		return 1;
	}

	else if ( myfam["generation"] > 5 && myfam["master_name"]!="����ľ" )
	{
		command("say �㲻�����ǻ������Ա������Ĺ���������������");
		return 1;
	}

	else if (me->query("combat_exp")<60000
        ||me->query_skill("sword")<20
        ||me->query_skill("parry")<20
        ||me->query_skill("dodge")<20)
	{
		command("shake");
		command("say ��Ĺ���̫����ʺ���������ǰ�ֹܼ���һЩ����ɡ�");
		return 1;
	}

	else if (me->query_temp("buygoods"))
	{
		command("hmm");
		command("say �й�������Ҫ������һ�������ֵļһ");
		return 1;
	}
         if (me->query("combat_exp")>300000)
         { 
             command("gongxi");
             command("say ���Ѿ���������Щ�ӻ���,ȥ������®��");
             return 1;
          }

	command("say ��ȥ" + quest["quest_1"] + "ȡһ������" + quest["quest_2"] + "�ɡ�");
	command("say " + quest["quest_3"] + "���ã����Ǹ�" + quest["quest_4"] + "�����ˣ���С�");
	command("say Ȩ��������ڽ�®��Χ���գ���Ҫ��ȥ��أ�·��ǧ��С�ġ�");

	me->set_temp("buygoods", "begin");
	me->set_temp("goods", quest["quest_4"]);
	ob = new("/d/huanhua/npc/obj/dingdan");
	ob->set("name", quest["quest_3"]);
	ob->set("long", "����һ��������" + quest["quest_1"] + quest["quest_4"] + "��ȡ���õ�" + quest["quest_3"] + "��\n");
	ob->move(me);
	return 1;
}

int accept_object(object who, object ob)
{
	mapping myfam;

	if ((string)ob->query("id") == "huo") 
	{
		if ( !(	myfam = who->query("family")) || myfam["family_name"] != "佻�����" )
		{
			command("say ���ǵģ���֪������˭���ġ�");
			command("thank "+who->query("id"));
  			destruct(ob);
			return 1;
		}
		else if ((string)who->query_temp("buygoods") != "over")
		{
			command("say ��Ȼ���ñ��˵��Ͷ����칦�����ǲ�ѧ�á�");
  			destruct(ob);
			return 1;
		}
		else
		{
			message_vision("$N�ѻ����������鳤���顣\n", who);
			command("say �������ɵ�ȷʵ������ȥ��Ϣ�ɡ�");
			message_vision("����ľ�к��˼����˳������������˴����ҡ�\n", who);
			who->add("potential", 80+random(80));
			who->add("combat_exp", 100+random(100));
			who->add("succeed", 2);
			who->delete_temp("buygoods");
			who->delete_temp("goods");
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
