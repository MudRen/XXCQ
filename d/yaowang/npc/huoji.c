// NPC ���
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
//inherit F_DEALER;

void create()
{
	set_name("���", ({ "huo ji", "huo", "ji" }) );
	set("title", HIB"ҩ����"NOR+YEL"����"NOR);
	set("gender", "����" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");

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
	int i=(ob->query("eff_qi")*100)/ob->query("max_qi");

	if((string)ob->query("party/party_name")==HIB"ҩ����"NOR) {
		command("say ��λ�ֵ������ˣ��������\n");
		return 1;}

	if (i<=30) {
		command("wa "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)
			+"�����������˰������뵽������ҩ����ҽʦ���㿴���ɣ�\n");
		return 1;}

	if (i<=60) {
		command("look "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)
			+"�����˵ò��ᰡ�����뵽�������˰ɣ�\n");
		return 1;}

	if (i<=90) {
		command("pat "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)
			+"�������˵��ˣ����������ҩ���¾�û���ˣ�\n");
		return 1;}

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

