// wei.c Τ�ϰ� 

inherit F_DEALER;
#include "/d/bianliang/npc/hhjob.h"

void create()
{
	set_name("���ƹ�", ({ "hu zhanggui", "hu", "zhanggui" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);
	set("gender", "����");
	set("age", 35);
	set("long",
		"�����ǻ�����Ψһһ���ӻ�����ϰ壬�з����¶��һ˿������\n");
	set_skill("strike", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 4000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/bag",
		__DIR__"obj/kuang",
		__DIR__"obj/yupei",
		__DIR__"obj/tongjing",
		__DIR__"obj/pixue",
		__DIR__"obj/caoxie",
		__DIR__"obj/sanzijing",
		__DIR__"obj/mupa",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
