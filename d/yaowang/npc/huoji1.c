// NPC ���
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
//inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���", ({ "huo ji", "huo", "ji" }) );
	set("title", HIB"ҩ����"NOR+YEL"����"NOR);
	set("gender", "����" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
         "/d/bianliang/npc/obj/san",
         "/d/bianliang/npc/obj/gao1",
         "/d/bianliang/npc/obj/jinlidan",
         "/d/bianliang/npc/obj/jinchuang",
         "/d/bianliang/npc/obj/baiyao",
	}));

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
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

int greeting(object ob)
{
	if((string)ob->query("party/party_name")==HIB"ҩ����"NOR) {
		command("say ��λ�ֵ����ˣ�\n");
		return 1;}
	else {
	switch( random(4) ) {
		case 0:
			command("bow "+ob->query("id"));
			command("say "+RANK_D->query_respect(ob)
		+"����Ҫ��Щҩ�𣿳���ҩ������ۣ�����ҩ�뵽����ѡ����\n");
			break;
		case 1:
			command("nod "+ob->query("id"));
			command("say "+RANK_D->query_respect(ob)
		+"����Ҫ��Щҩ�𣿳���ҩ������ۣ�����ҩ�뵽����ѡ����\n");
			break;
		case 2:
			command("hi "+ob->query("id"));
			command("say "+RANK_D->query_respect(ob)
		+"����Ҫ��Щҩ�𣿳���ҩ������ۣ�����ҩ�뵽����ѡ����\n");
			break;
		case 3:
			command("welcome "+ob->query("id"));
			command("say "+RANK_D->query_respect(ob)
		+"����Ҫ��Щҩ�𣿳���ҩ������ۣ�����ҩ�뵽����ѡ����\n");
			break;
		}
	}
}

