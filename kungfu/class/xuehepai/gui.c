// made by lks

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/xuehepai/gui.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("������",({"gui wuyin","gui"}));
        set("nickname",HIR"Ѫ������"NOR);
	set("gender","����");
	set("int",30);	
	set("con",30);
	set("str",30);
	set("dex",30);
	set("bac",40);
	set("age",40);
	set("attitude","friendly");
        set("combat_exp",1200000);
        set("kill",1000);
	set("long",
"�Ǹ��ڳԵ��ˣ���ò��ª,���Բ��ݼ��ˡ�\n"
	);
        set("neili",5000);
        set("jingli",3000);
        set("yiqiguan-riyue",2);
        set("max_neili",5000);
        set("max_jingli",3000);
        set_skill("literate",150);
        set_skill("cuff",250);
        set_skill("parry",250);
        set_skill("dodge",250);
        set_skill("youran-bu",250);
        set_skill("yudi-whip",250);
        set_skill("whip",250);
        set_skill("jieniu-dao",250);
        set_skill("blade",250);
        set_skill("yiqiguan-riyue",220);
        set_skill("throwing",250);
        set_skill("youren-arrow",250);
        set_skill("sword",250);
        set_skill("arrow",250);
        set_skill("xuehe-jian",250);
        set_skill("force",250);
        set_skill("tao",200);
        set_skill("feixue-quan",250);
        map_skill("force","yiqiguan-riyue");
        map_skill("cuff","feixue-quan");
        map_skill("sword","xuehe-jian");
        map_skill("blade","jieniu-dao");
        map_skill("arrow","youren-arrow");
        map_skill("whip","yudi-whip");
        prepare_skill("cuff","feixue-quan");
	
       create_family("Ѫ����",10,"����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
            carry_object("/clone/weapon/changjian")->wield();
        set("chat_chance", 2);
	set("chat_msg", ({
		(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                  (: exert_function, "zhibiao" :),
                  (: perform_action, "sword.xuehe" :),
                (: recover_ob :),
	}) );
}

	
void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

