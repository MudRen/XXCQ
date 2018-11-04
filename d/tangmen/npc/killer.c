//killer.c	������ʿ

inherit NPC;
inherit F_MASTER;

void recover_ob();
void away();

void create()
{
	set_name("������ʿ", ({"killer"}));
	set("gender", "����");
	set("age", 26);
	set("long", 
		"������ȥû��һ˿���飬���������˵���Ѳ������ˡ�\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 40);

	set("qi", 1200);
	set("max_qi", 1200);
	set("jingli", 600);
	set("max_jingli", 600);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	
	set("combat_exp", 700000);
	set("score", 20000);
	
	set_skill("force", 140);
	set_skill("strike", 130);
	set_skill("cuff",120);
	set_skill("dodge", 150); 
	set_skill("sword", 150); 
	set_skill("parry", 130); 
	set_skill("literate", 120); 
	
	create_family("�Ĵ�����", 10, "��ʿ");

	setup();

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance", 5);
	set("chat_msg", ({
		(: away :),
	}));
}

void away()
{
	if( living(this_object()) )
	{
		message_vision("���ŵ��Ӽ���ææ���߿��ˡ�\n", this_object());
		destruct(this_object());
	}
	return;
}