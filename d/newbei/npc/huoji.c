// Room: /welcome/npc/huoji.c
//By adx @ CuteRabbit 15:57 99-5-18

// Room: /welcome/npc/xiaoer.c
//By adx @ CuteRabbit 15:57 99-5-18

//inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "����һ����Ͳ���Ļ�ƣ�ֻ��ץҩ��\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/bianliang/npc/obj/jinchuang",
		"/d/bianliang/npc/obj/baiyao",
	}));

	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver",1);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
