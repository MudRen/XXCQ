// huoji. ҩ�̻��

inherit NPC;

void create()
{
	set_name("�ϴ���", ({ "meng chunhua", "meng", "chunhua"}));
	set("str", 20);
	set("gender", "Ů��");
	set("title", "������ϰ���");
	set("age", 45);
	set("long", "����һ�����ܸɵ�Ů�ˣ�ÿ���������к����˺���ֹ���ߴ����š����ˡ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");

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
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "�ϴ���ӭ����������λ" + RANK_D->query_respect(ob)
				+ "�������ϴ���������ġ�\n");
}