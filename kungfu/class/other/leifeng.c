// leifeng.c �׷�

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�׷�", ({ "lei feng", "lei", "feng" }));
	set("nickname", "ӥצ��");
	set("title", "ӥצ������");
	set("long", 
"����һ˫�֣���ֱ����ӥצһ�㣬���˺��ļ��ӣ�\n"
"�������Ϸ�ɫ����ͩ��һ�㣬����ָצ�������ּ⣬\n"
"�������ݣ�͹�������ۣ���ǡ��һ��ӥ����\n");
	set("gender", "����");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 30);
	set("bac", 30);
	
	set("qi", 1600);
	set("max_qi", 1600);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 100000);

	set_skill("claw", 150);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("jifadodge", 100);
	set_skill("parry", 150);
	set_skill("yingzhao-gong", 150);
	set_skill("jifaforce", 100);

	map_skill("force", "jifaforce");
	map_skill("claw", "yingzhao-gong");
	map_skill("parry", "yingzhao-gong");
	map_skill("dodge", "jifadodge");

	prepare_skill("claw", "yingzhao-gong");

	create_family("ӥצ��", 3, "����");

	set("chat_msg_combat", ({
                (: exert_function, "recover" :),
	}) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 25) {
		command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ��ӥצ���书��");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));

	return;
}
