// NPC �ʷ� ���ɼ���ҩ����
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

int ask_join();
int ask_box();

void create()
{
	set_name("������", ({ "guo laoliu", "guo", "laoliu", }));
	set("title", HIB"ҩ����"NOR+WHT"����"NOR);
	set("long", "���ǻش��õ��ʷ�����������ش��õ�������Ŀ��\n" );
	set("gender", "����");
	set("attitude", "friendly");

	set("age", 60);
	set("shen_type", 1);
	set("str", 17);
	set("int", 16);
	set("con", 18);
	set("dex", 20);
	set("max_qi", 150);
	set("max_jing", 150);
	set("jiali", 10);
	set("combat_exp", 5000);

	set_skill("force", 15);
	set_skill("dodge", 15);
	set_skill("unarmed", 15);
	set_skill("parry", 15);

        set("inquiry", ([
		"ҩ����" : (: ask_join :),
		"�ش���" : (: ask_join :),
		"join" : (: ask_join :),
		"����" : (: ask_join :),
		"��" : (: ask_join :),
		"��ĺ�" : (: ask_box :),
		"box" : (: ask_box :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int greeting(object ob)
{
	if(ob->query_temp("naiyaoer")) {
		command("say ��������ҩ���ȵ��㣬�㻹����ȥ��\n");
		return 1; }
	if((string)ob->query("party/party_name")==HIB"ҩ����"NOR) {
		if( (int)ob->query_skill("healing",1)>=20
		&& ob->query("party/rank")==YEL"����"NOR ) {
		ob->set_temp("naiyaoer",1);
		command("say ��λ�ֵ����ҽҩ�ھ����г�����������ҩ������Ҫ���˲ţ�\n");
		command("say �����Ը����Ե�ҩ����ȥ��ߵ��������һ��ѧϰ��\n");
		return 1;}
		if( (int)ob->query_skill("healing",1)>=40
		&& ob->query("party/rank")==MAG"ׯ��"NOR ) {
		ob->set_temp("naiyaoer",2);
		command("say "+ob->query("name")+"�����Ը�����ȥ������\n");
		return 1;}
	}
	else {
	switch( random(4) ) {
		case 0:
			command("bow "+ob->query("id"));
			break;
		case 1:
			command("nod "+ob->query("id"));
			break;
		case 2:
			command("hi "+ob->query("id"));
			break;
		case 3:
			command("welcome "+ob->query("id"));
			break;
		}
	}
}


int ask_join()
{
	mapping party; 
	object me;
	me=this_player();

	if( me->query("party/party_name") == HIB"ҩ����"NOR ) {
		command("say "+RANK_D->query_respect(me)+
			"���Ѿ���ҩ���ȵ����ˣ���Ҫ����ʲô��\n");
		return 1; }

	if( me->query("party") ) {
		command("say "+RANK_D->query_respect(me)+
			"�㻹�����˳�"+me->query("party/party_name")+"�ɣ�\n");
		return 1; }

	if( me->query("yaowang") ) {
		command("say "+RANK_D->query_respect(me)+
			"�㱾���ܹܴ���ӽ�ֹ����룡\n");
		return 1; }

	party = allocate_mapping(4);
	party["party_name"] = HIB"ҩ����"NOR;
	party["rank"] = YEL"����"NOR;
	party["level"] = 1;
	party["enter_time"] = time();
	me->set("party", party);

	command("ok "+me->query("id"));
	command("say ҩ���Ⱦ��������ˣ�\n");

	command("say "+RANK_D->query_respect(me)+
		"���Ҫ���Ŭ���ɻ��\n");
	return 1;
}

int ask_box()
{
	object ob, me;
	me=this_player();

	if( me->query("party/party_name") != HIB"ҩ����"NOR ) {
		command("say "+RANK_D->query_respect(me)+
			"�㲻��ҩ���ȵĵ��ӣ���ĺв��������㣡\n");
		return 1; }

	if( present("zhenjiu he", me) ) {
		command("say "+RANK_D->query_respect(me)+
			"���������ϲ�������Ҫ��ô���ʲô�أ�\n");
		return 1; }

	if( (int)me->query_skill("healing",1)<40 ) {
		command("say "+RANK_D->query_respect(me)+
			"�����ڻ�����ʹ����ĺУ�\n");
		return 1; }

	ob = new(__DIR__"obj/zhenjiu");
	ob->move(me);

	message_vision(YEL"��������$Nһ��" + ob->query("name") + "��\n"NOR, me);

	command("say "+RANK_D->query_respect(me)+
		"���Ҫ���Ŭ������\n");
	return 1;
}
