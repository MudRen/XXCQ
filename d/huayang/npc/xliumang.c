// ding.c �Ҷ�

inherit NPC;

void create()
{
	set_name("С��å", ({ "xiao liumang", "xiao", "liumang" }));
	set("age", 19);
	set("gender", "����");
	set("long", "һ������ȥ���������������ˣ���ʱ�ĺ���С����");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 1000);
	set("shen", -500);

	set_skill("strike", 10);
	set_skill("dodge", 20);
	set_skill("parry", 10);
	set_skill("force", 10);

	set("chat_msg", ({
		"С��å���������ĳ�����·�ߵ�Ұ�������ɰײ���~~~~����\n",
		"С��å������Σ���֪����ʲô����\n",
	}));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}