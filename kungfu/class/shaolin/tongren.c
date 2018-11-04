// tongren.c ͭ��
// by Load

inherit NPC;

void create()
{

	set_name("ͭ��", ({"tong ren","tong","ren",}));
	set("long",
		"����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n"
	);

	set("nickname", "֪��ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);
	set("bac", 22);
	set("max_qi", 400);
	set("qi", 400);
	set("max_jingli", 300);
	set("jingli", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 20000);
	
	set_skill("force", 40);
	set_skill("banruo-changong", 40);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("cuff", 40);
	set_skill("luohan-quan", 40);
	set_skill("parry", 30);
	set_skill("buddha", 30);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");

	prepare_skill("cuff", "luohan-quan");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/npc/obj/huangjiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
}

void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	me = this_player();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	if( (string)ob->query("gender") != "����" )
	{
		command ("say �����ӷ���λʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}

	command("say �����ӷ����գ����գ�");

	if( (string)ob->query("class")!="bonze" )
	{
		command("say �����ӷ����գ����գ�");
		command("say ʩ������������ҷ𣬾�����ɽ��ͭ�ǻ���ͭ��ʦ�ְɡ�");
		return;
	}

	if ( ob_fam["generation"] > my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	command("say " + RANK_D->query_respect(ob) + "��ƶɮֻ������ɽ�ţ�������ͽ��");
}