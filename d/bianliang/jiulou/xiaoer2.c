// xiaoer2.c �Ƶ�С��

inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("title", "����¥����");
	set("long",
		"��λ��С����Ц�����æ�����Ѿ��۵���ͷ���ˡ�\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		"d/bianliang/npc/obj/jitui",
		"d/bianliang/npc/obj/jiudai",
		"d/bianliang/npc/obj/baozi",
		"d/bianliang/npc/obj/niurou",
	}));
	setup();
	carry_object("clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������Ե�ʲô�ɣ������������Ҷ��������ġ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "��������������������\n");
			break;
	}
}
