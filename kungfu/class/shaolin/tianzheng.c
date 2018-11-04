// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

int ask_bao();

void create()
{
	set_name("������ʦ", ({
		"tianzheng dashi",
		"tianzheng",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
		"������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);


	set("title", "��������ʮ�������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
         set("max_qi", 3000);
         set("max_jing", 2000);
         set("neili", 4000);
         set("max_neili", 4000);
         set("jiali", 150);
         set("combat_exp", 2000000);
         set("score", 1000000);
     set_skill("force", 400);
     set_skill("banruo-changong", 400);
     set_skill("dodge", 400);
    set_skill("dashou-yin", 400);
      set_skill("club", 400);
      set_skill("sword", 400);
     set_skill("unarmed", 400);
       set_skill("wuxiang-shengong",400);
       set_skill("damo-jian",360);
       set_skill("huoyan-dao",360);
       set_skill("blade",360);
       set_skill("cuff",400);
       set_skill("shaolin-quan",400);
     set_skill("shaolin-shenfa", 400);
     set_skill("finger", 440);
     set_skill("strike", 360);
     set_skill("hand", 380);
     set_skill("claw", 360);
     set_skill("parry", 400);
     set_skill("nianhua-zhi", 440);
     set_skill("buddha", 440);
         set_skill("literate", 220);

    map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	create_family("������", 35, "����");
        set("inquiry", ([
                "��������" : (: ask_bao :),
        ]) );

	setup();

        carry_object("/d/shaolin/npc/obj/jinjiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}
        if (me->query_skill("banruo-changong",1)<160)
          {  command("say ��İ���������Ҫ����ѧϰ����!\n");
          return;
          }
          if(me->query_skill("buddha",1)<150)
          {  command("say �㻹û����ᵽ��ҵ�����!\n");
          return;
          }
          if(me->query_skill("finger",1)<150)
          { command("say ��Ļ���ָ������,ѧ�����ҵ����ž���!\n");
           return;
          }
         if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
      {
          new_name = "ľ" + name[2..3];
          ob->set("name", new_name);
          command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ������ľ�ֱ����� !");
          command("recruit " + ob->query("id"));
          return;
        }

	else
	{
		command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
		return;
	}

	return;
}

int ask_bao()
{
command("say �ðɣ��Ҿʹ���ȥ����λ���ϣ�����ҪС��!\n");
this_player()->move("/d/shaolin/zhulin17");
return 1;
}

