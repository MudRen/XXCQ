// wei.c Τ�ϰ� 

inherit F_DEALER;
#include "/d/bianliang/npc/hhjob.h"

void create()
{
	set_name("������", ({ "liu tiejiang", "liu", "tiejiang" }));
	set("title", "����������");
	set("shen_type", 1);
	set("gender", "����");
	set("age", 35);
	set("long",
		"�����ǻ�����Ψһһ�Ҵ����̵����ˣ���ʵ�ı۰������˺�ˮ��\n");
	set_skill("strike", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/bishou",
		__DIR__"obj/caidao",
		__DIR__"obj/chutou",
		__DIR__"obj/gangpa",
		__DIR__"obj/liandao",
		__DIR__"obj/litou",
		__DIR__"obj/tiefu",
		"/clone/weapon/changjian",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
