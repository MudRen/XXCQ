// zhang.c ��˳̩
// mlf���,lks���

#include <ansi.h>
#include "/d/huafu/npc/cam.h"

inherit NPC;
#include "/kungfu/class/fameng/erdai.h"
inherit F_MASTER;
int recover_ob();

void create()
{
	set_name("��˳̩",({"zhang shuntai","zhang"}));
        set("nickname",HIC"�������"NOR);
	set("gender","����");
	set("attitude","peaceful");
	
	set("combat_exp",500000);
	set("neili",1000);
	set("jingli",500);
	set("max_neili",1000);
	set("max_jingli",500);
	set("max_qi",800);
	set("qi",800);
	
	set_skill("literate",100);
        set_skill("fengye-xiangsi",100);
	set_skill("tao",100);
	set_skill("force",160);
	set_skill("dodge",160);
	set_skill("parry",160);
	set_skill("bairen-shengong",160);
	set_skill("cuff",160);
	set_skill("yiye-zhiqiu",160);
	
	map_skill("force","bairen-shengong");
        map_skill("parry","yiye-zhiqiu");
        map_skill("dodge","fengye-xiangsi");
	map_skill("cuff","yiye-zhiqiu");
        prepare_skill("cuff","yiye-zhiqiu");
	
          create_family("���ζ���",2,"����");
	setup();
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "cuff.kuangfeng" :),
		(: recover_ob :)
	}) );	
	carry_object("/clone/misc/cloth")->wear();
}
	
	
int recover_ob()
{
	command("yun recover");
        return 1;
}	
