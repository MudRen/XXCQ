// qing.c ��ıʯ
// mlf���,lks ���

#include <ansi.h>
#include "/d/huafu/npc/cam.h"
#include "/d/wenzhai/npc/qing.h"
inherit NPC;
#include "/kungfu/class/fameng/erdai.h"
inherit F_MASTER;

int ask_me();
int ask_job();
void create()
{
	set_name("��ıʯ",({"qing moushi","qing"}));
	set("nickname",HIY"�¼�ʮʯ"NOR);
	set("gender","����");
	set("attitude","peaceful");
	set("age",33);
	set("combat_exp",500000);
	set_skill("tao",100);
	set("max_qi",1000);
	set("max_neili",1500);
	set("max_jingli",500);
	set_skill("force",180);
	set_skill("bairen-shengong",180);
	set_skill("dodge",150);
	set_skill("parry",180);
	set_skill("fengye-xiangsi",150);
        set_skill("blade",180);	
	
        map_skill("force","bairen-shengong");
	map_skill("dodge","fengye-xiangsi");
        create_family("���ζ���",2,"����");
	setup();
	
        set("inquiry",([
                "book" : (: ask_me :),
                "��" : (: ask_me :),
                "job" : (: ask_job :),
        ]));
	carry_object("/clone/misc/cloth")->wear();
	set("chat_chance", 20);
	set("chat_msg", ({
		(: exert_function, "recover" :),
		(: exert_function, "heal" :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
}
