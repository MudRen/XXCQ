// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void recover_ob();

void create()
{
	set_name("������ʦ", ({"longhu dashi", "longhu", "dashi",}));
	set("long",
		"����һλ����һ��ĸ�ɮ����һϮ��˿������ġ�\n"
		"����ľ޴��ó��������⣬Ŀ�����ϣ��Ե��������㡣\n"
	);


	set("title", "�����½���Ժ����");
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
	set("max_jingli", 1500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 75);
	set("combat_exp", 1000000);
	set("score", 500000);
	set("banruo-changong", 2);

	set_skill("force", 170);
	set_skill("banruo-changong", 170);
	set_skill("dodge", 160);
	set_skill("shaolin-shenfa", 160);
	set_skill("cuff", 200);
	set_skill("parry", 160);
	set_skill("shaolin-quan", 200);
	set_skill("buddha", 150);
	set_skill("literate", 120);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "shaolin-quan");
	map_skill("parry", "shaolin-quan");

	prepare_skill("cuff", "shaolin-quan");

	create_family("������", 35, "����");

	setup();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: recover_ob :)
	}) );

        carry_object("/d/shaolin/npc/obj/jinjiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
}

void recover_ob()
{
	command("yun recover");
	return;
}