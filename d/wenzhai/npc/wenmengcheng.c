// wenmengcheng.c ���γ�
// made by lks

#include <ansi.h>
#include "/d/huafu/npc/cam.h"

inherit NPC;
#include "/kungfu/class/fameng/yidai.h"
inherit F_MASTER;

void create()
{
        set_name("���γ�",({"wen mengcheng","wen"}));
	set("nickname",HIR"�¸�"HIW"---"HIG"������"NOR);
	set("gender","����");
	set("int",30);	
	set("con",30);
	set("str",30);
	set("dex",30);
	set("bac",40);
	set("age",40);
	set("attitude","friendly");
	set("shen_type",1);
	set("combat_exp",800000);
	set("score",1000);
	set("long",
	"���������¼ң����ڲ�������͢�鳼����������\n��������լ���뻨�ݷ�һ���齨�˷��ζ�����������־֮ʿ��\n"
	"���������뻨�ݷ��Ĺ�ϵһֱ���ã����������������ϡ�\n���ԣ����ζ����ھ�����������\n"
	);
	set("neili",2000);
	set("jingli",1000);
	set("max_neili",2000);
	set("max_jingli",1000);
         set_skill("literate",180);
        set_skill("cuff",250);
          set_skill("parry",250);
         set_skill("dodge",250);
             set_skill("force",350);
             set_skill("bairen-shengong",350);
             set_skill("tao",350);
             set_skill("yiye-zhiqiu",250);
             set_skill("fengye-xiangsi",250);
	map_skill("force","bairen-shengong");
        map_skill("cuff","yiye-zhiqiu");
        map_skill("parry","yiye-zhiqiu");
        map_skill("dodge","fengye-xiangsi");
        prepare_skill("cuff","yiye-zhiqiu");

        create_family("���ζ���",1,"�ε�����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
        set("chat_chance", 4);
	set("chat_msg", ({
		(: exert_function, "recover" :),
		(: exert_function, "heal" :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
}

