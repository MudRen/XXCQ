// Room: /welcome/npc/yang.c
//By adx @ CuteRabbit 15:57 99-5-18

//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "Yang yongfu", "yang" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long",
		"���ϰ������������������ˣ����˼�ʮ���С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/beixin",
		__DIR__"obj/toukui",
		__DIR__"obj/cycle",
		__DIR__"obj/surcoat",
		__DIR__"obj/huwan",
		__DIR__"obj/zhitao",
		__DIR__"obj/huyao",
		__DIR__"obj/caoxie",
		__DIR__"obj/pixue",
		__DIR__"obj/tieshou",
		__DIR__"obj/tiejia",
	}));
	
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
