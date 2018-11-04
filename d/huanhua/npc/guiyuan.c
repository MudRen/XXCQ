inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void recover_ob();

void create()
{
	set_name("��ԭ", ({"gui yuan", "gui", "yuan"}));
	set("gender", "����");
	set("age", 24);
	set("long", 
		"����佻������Ĵ���������Ե��õ�һ����Ҳ��佻���ʮ��ᡱ֮һ��\n");
	set("attitude", "peaceful");
	set("title", "佻����ɵ��Ĵ����ӡ�"HIC"ʮ���"NOR);
	set("str", 16);
	set("int", 15);
	set("con", 20);
	set("dex", 24);
	set("bac", 25);

	set("qi", 1700);
	set("max_qi", 1700);
	set("jingli", 1100);
	set("max_jingli", 1100);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jiali", 10);
	
	set("combat_exp", 200000);
	set("shen", 1000);
	
	set_skill("force", 100);
	set_skill("jiuqu-xinfa", 100); 
	set_skill("strike", 110);
	set_skill("feixu-zhang", 110);
	set_skill("dodge", 120); 
	set_skill("huanhua-shenfa", 120); 
	set_skill("sword", 110); 
	set_skill("huanhua-jian", 110); 
	set_skill("parry", 100); 
	set_skill("confu", 100); 
	set_skill("literate", 110); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("sword", "huanhua-jian");
	map_skill("parry", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("佻�����", 4, "����");

	setup();

	carry_object(__DIR__"obj/jinpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mantian" :),
		(: perform_action, "sword.luanhong" :),
		(: perform_action, "strike.fenfei" :),
		(: recover_ob :)
	}) );
}

void recover_ob()
{
	command("yun recover");
	return;
}

void attempt_apprentice(object ob)
{
	command("say ��λ"+ RANK_D->query_respect(ob) +
		"��ׯ����׼����ͽ�������������ʦ�������ұ��˰ɡ�");
	return;
}