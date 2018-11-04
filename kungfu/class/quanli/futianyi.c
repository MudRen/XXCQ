inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void recover_ob();

void create()
{
	set_name("������", ({"fu tianyi", "fu", "tianyi"}));
	set("gender", "����");
	set("age", 53);
	set("nickname", WHT"������ħ"NOR);
	set("long", 
		"����ü���룬�������������ڽ�ˮ���ˡ�����ŭ���ľ�ʯ�ٽ����Ʒ粻����
����Ȩ����ʮ����ħ֮һ��\n");
	set("attitude", "peaceful");
	set("title", "Ȩ��������ֶ����");
	set("str", 26);
	set("int", 12);
	set("con", 24);
	set("dex", 18);
	set("bac", 20);

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
	set_skill("xuantian-xinfa", 100); 
	set_skill("claw", 110);
	set_skill("liekong-zhao", 110);
	set_skill("dodge", 120); 
	set_skill("pili-shenfa", 120); 
	set_skill("parry", 100); 
	set_skill("confu", 100); 
	set_skill("literate", 60); 
	
	map_skill("force", "xuantian-xinfa");
	map_skill("dodge", "pili-shenfa");
	map_skill("claw", "liekong-zhao");
	map_skill("parry", "liekong-zhao");

	prepare_skill("claw", "liekong-zhao");
	
	create_family("Ȩ����", 4, "����");
	create_party("Ȩ����","����",2);

	setup();

	carry_object("/d/quanli/npc/obj/tieyi")->wear();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "claw.qin" :),
		(: perform_action, "claw.niu" :),
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
	if (ob->query("str")<25)
	{
		command("shake");
		command("say �����Ϊʦ�����䣡");
		return;
	}
	else if (ob->query("shen")>(ob->query("combat_exp")/10))
	{
		command("say �����Ʋ�������������ʿ�ˣ�����ҹ���");
		return;
	}

	command("haha "+ob->query("id"));
	command("say ��ѽ���Ϸ���������ˣ�");
	command("recruit " + ob->query("id"));

	ob->set("title",WHT"������ħ"NOR"�������״�����");
	return;
}