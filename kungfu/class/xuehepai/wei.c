// made by lks

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/xuehepai/wei.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("������",({"wei beihui","wei"}));
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
"Ӣ������,���д󽫷�ȡ���Ҳ�ѲŰ�\n�������������ˮһ���У��������ż����С�\n"
	);
        set("neili",5000);
        set("jingli",3000);
        set("max_neili",5000);
        set("max_jingli",3000);
        set_skill("literate",200);
        set_skill("cuff",200);
	set_skill("parry",200);
	set_skill("dodge",200);
        set_skill("youran-bu",200);
        set_skill("yudi-whip",200);
        set_skill("whip",200);
        set_skill("jieniu-dao",200);
        set_skill("blade",200);
       set_skill("yiqiguan-riyue",200);
        set_skill("throwing",200);
        set_skill("youren-arrow",200);
        set_skill("sword",200);
        set_skill("xuehe-jian",200);
	set_skill("force",200);
        set_skill("longmen-shengong",200);
	set_skill("tao",200);
        set_skill("feixue-quan",200);
        map_skill("force","longmen-shengong");
        map_skill("cuff","feixue-quan");
        map_skill("sword","xuehe-jian");
        map_skill("blade","jieniu-dao");
        map_skill("throwing","youren-arrow");
        map_skill("whip","yudi-whip");
        prepare_skill("cuff","feixue-quan");
	
       create_family("Ѫ����",12,"����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
        set("chat_chance", 2);
	set("chat_msg", ({
		(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: exert_function, "xuanwo" :),
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

