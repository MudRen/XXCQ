// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("ɣ����", ({"sang shuyun", "sang", "shuyun"}));
	set("title", "���հ����");
	set("nickname", "������ָ");
	set("gender", "����");
	set("age", 45);
	set("long", 
		"��д......\n");
	set("attitude", "peaceful");
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	
	set("combat_exp", 1200000);
	set("score", 20000);
	
	set_skill("force", 150);
	set_skill("tianyu-xinfa", 150); 
	set_skill("finger", 150);
	set_skill("changkong-zhi", 200); 
	set_skill("dodge", 150); 
	set_skill("tianyu-shenfa", 150); 
	set_skill("tianyu-qijian", 200); 
	set_skill("sword", 150); 
	set_skill("parry", 150); 
	
	map_skill("force", "tianyu-xinfa");
	map_skill("finger", "changkong-zhi");
	map_skill("sword", "tianyu-qijian");
	map_skill("dodge", "tianyu-shenfa");
	
	prepare_skill("finger", "changkong-zhi");

	create_family("���հ�", 1, "����");

	setup();

	carry_object("/clone/armor/changpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

}

void attempt_apprentice(object ob)
{
	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
	ob->set("title", "���հ���ͨ����");
	return;
}
