// huoji. ҩ�̻��

inherit F_DEALER;

void create()
{
	set_name("���", ({ "huoji"}));
	set("str", 20);
	set("gender", "����");
	set("title", "�ش�������");
	set("age", 18);
	set("long", "������̫ʦ��ѧͽ��ƽʱ���ڵ��ﵱ��ơ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/jinchuang",
		__DIR__"obj/baiyao",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "���ӭ����������λ" + RANK_D->query_respect(ob)
				+ "Ҫ��ʲôҩ���������������һ���Ϻõ����ϰ�ҩ��\n");
			break;
		case 1:
			say( "����ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "��������������������ҩ��ȫ�ˡ�\n");
			break;
	}
}
