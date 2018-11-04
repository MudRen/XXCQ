// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

#include "/kungfu/class/huanhua/sidai.h"
void recover_ob();

void create()
{
	set_name("����", ({"chuanxin", "chuan"}));
	set("gender", "����");
	set("age", 24);
	set("long", 
		"����佻������Ĵ����������¸ҵ�һ����Ҳ��佻���ʮ�ꡱ֮һ��\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 40);
	set("con", 25);
	set("dex", 35);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jingli", 1200);
	set("max_jingli", 1200);
	set("neili", 1400);
	set("max_neili", 1400);
	set("jiali", 50);
	
	set("combat_exp", 250000);
	set("score", 20000);
	
	set_skill("force", 120);
	set_skill("jiuqu-xinfa", 120); 
	set_skill("strike", 120);
	set_skill("feixu-zhang", 120);
	set_skill("cuff",120);
	set_skill("tiexian-quan",120);
	set_skill("dodge", 120); 
	set_skill("huanhua-shenfa", 120); 
	set_skill("sword", 120); 
	set_skill("huanhua-jian", 120);
	set_skill("parry", 120); 
	set_skill("literate", 120);
	set_skill("confu", 120);
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("cuff", "tiexian-quan");
	map_skill("parry", "tiexian-quan");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	prepare_skill("cuff", "tiexian-quan");
	
	create_family("佻�����", 4, "����");

	setup();

	carry_object("/d/huanhua/npc/obj/liangongfu")->wear();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "cuff.chong" :),
		(: recover_ob :)
	}) );
}

void recover_ob()
{
	command("yun recover");
	return;
}