// menwei

inherit NPC;

void create()
{
	set_name("����", ({ "men wei", "wei"}));
	set("long", 
"����xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx��\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);

	set("combat_exp", 100000);

	set_skill("force", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("blade", 40);
	set_skill("strike", 50);

	create_family("�Ĵ�����", 10, "�Ҷ�");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}