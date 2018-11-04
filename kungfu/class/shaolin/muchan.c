// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("ľ����ʦ", ({
		"muchan dashi",
		"muchan",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
		"������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);


	set("title", "�������޺�������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);
    set_skill("force", 180);
    set_skill("banruo-changong", 180);
    set_skill("blade", 180);
    set_skill("huoyan-dao", 180);
    set_skill("luohan-quan", 180);
    set_skill("banruo-zhang", 180);
    set_skill("cuff", 180);
    set_skill("dodge", 180);
    set_skill("shaolin-shenfa", 180);
    set_skill("strike", 180);
    set_skill("parry", 180);
    set_skill("buddha", 180);
	set_skill("literate", 110);

    map_skill("force", "banruo-changong");
    map_skill("cuff", "luohan-quan");
    map_skill("strike", "huoyan-dao");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");

	create_family("������", 35, "����");

	setup();

        carry_object("/d/shaolin/npc/obj/jinjiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
    string name,new_name;

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

    if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
	{
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}
	else
	{
        if( ob->query("bai_mu") > 0)
        {                   command("say " + RANK_D->query_respect(ob) + "����Ȼ������ʦ���Ƽ���,���Ҿ�������ɡ�\n");
                   me->delete("bai_mu");
              new_name = "��" + name[2..3];
                        ob->set("name", new_name);
                   command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ����� !");
        ob->delete("bai_mu");
          command("recruit " + ob->query("id"));
        }
        else         command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
		return;
	}

	return;
}

