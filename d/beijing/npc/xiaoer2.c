// xiaoer2.c ���ׯС��

inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("title", "�Һͳ��ׯ����");
	set("long",
		"��λ��С����Ц�����վ�����к����������������ˡ�\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
//		__DIR__"obj/beixin",
//		__DIR__"obj/pixue",
//		__DIR__"obj/tiejia",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�����������µ����·��ɡ�\n");
			break;
		case 1:
			say( "��С�����˸�����˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}
