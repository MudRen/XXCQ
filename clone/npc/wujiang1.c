// wujiang.c �佫

inherit F_BUKUAI;

void create()
{
	set_name("�佫", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	set("banghui", "��͢");
	set("bhrank", 9);

        set("chat_chance", 2);
        set("chat_msg", (
                (:random_move:) 
	) );

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/armor/tiejia")->wear();
	add_money("silver",5);
}
