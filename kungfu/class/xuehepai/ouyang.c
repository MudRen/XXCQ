// made by lks

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/xuehepai/ouyang.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("ŷ����",({"ouyang tuo","ouyang"}));
        set("nickname",HIR"ѪӰ����"NOR);
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
"���˱��Ը��ң������Ĵȣ��Ǹ����˿��������ˣ���\n�ۺû���������η�壬�������������Ĳ�����ν��\n�����ޣ�����ϡ����˸�񣬲�����˫���˸��֣�\n"
	);
         set("neili",5000);
         set("jingli",3000);
         set("max_neili",10000);
         set("max_jingli",6000);
         set_skill("literate",350);
         set_skill("cuff",400);
         set_skill("parry",400);
         set_skill("dodge",400);
         set_skill("youran-bu",400);
         set_skill("yudi-whip",400);
         set_skill("arrow",400);
         set_skill("whip",400);
         set_skill("jieniu-dao",400);
         set_skill("blade",400);
        set_skill("yiqiguan-riyue",400);
         set_skill("throwing",400);
         set_skill("youren-arrow",400);
         set_skill("sword",400);
         set_skill("xuehe-jian",400);
         set_skill("force",400);
         set_skill("tao",320);
         set_skill("feixue-quan",400);
          map_skill("force","yiqiguan-riyue");
        map_skill("cuff","feixue-quan");
        map_skill("sword","xuehe-jian");
        map_skill("blade","jieniu-dao");
        map_skill("arrow","youren-arrow");
        map_skill("whip","yudi-whip");
        prepare_skill("cuff","feixue-quan");
	
       create_family("Ѫ����",11,"����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
        set("chat_chance", 2);
	set("chat_msg", ({
		(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                  (: exert_function, "zhibiao" :),
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

