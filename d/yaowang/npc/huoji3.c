// NPC ���
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
//inherit F_DEALER;

string ask_me(string);
void create()
{
	set_name("���", ({ "huo ji", "huo", "ji" }) );
	set("title", HIB"ҩ����"NOR+YEL"����"NOR);
	set("gender", "����" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");

        set("inquiry", ([
		"ʳ��" :   (: ask_me, "baozi" :),
		"ˮ" :   (: ask_me, "jiudai" :),
        ]));
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/baiyao",
	}));
	set("foor_count", 10);
	setup();
        add_money("silver", 5);
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
		if( (int)ob->query_skill("healing",1)>=60
		&& ob->query("party/rank")==HIM"ҩ��"NOR ) {
		ob->set_temp("naiyaoer",3);
		command("say "+ob->query("name")+"�����Ը�����ȥ������\n");
		return 1;}
		if( (int)ob->query_skill("healing",1)>=80
		&& ob->query("party/rank")==CYN"ҩʦ"NOR ) {
		ob->set_temp("naiyaoer",4);
		command("say "+ob->query("name")+"�����Ը�����ȥ������\n");
		return 1;}
		if( (int)ob->query_skill("healing",1)>=100
		&& ob->query("party/rank")==HIC"ҽʦ"NOR ) {
		ob->set_temp("naiyaoer",5);
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

string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("party")) || fam["party_name"] != HIB"ҩ����"NOR)
		return RANK_D->query_respect(this_player()) + 
		"���뱾��������������֪�˻��Ӻ�̸��";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ���������������Ҫ�ˣ����˶���û�Է��أ�";

	if (query("foor_count") < 1)
		return "��Ǹ�������ò���ʱ�򣬿�����ʱ���Ѿ����ˡ�";

	ob = new("/clone/food/" + name);
	ob->move(this_player());

	add("foor_count", -1);

	message_vision(YEL"��Ƹ�$Nһ��" + ob->query("name") + "��\n"NOR, this_player());

	return "����";
}
