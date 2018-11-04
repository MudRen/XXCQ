// NPC ��ҩ�� ҩ���ȹ���
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��ҩ��", ({ "nai yaoer","nai","yaoer"}));
	set("title", HIB"ҩ���ȹ���"NOR);
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
	if( (string)ob->query("party/party_name")!=HIB"ҩ����"NOR) {
		command("say �㲻�Ǳ������ˣ��������ʲô��������ȥ��\n");
		return 1; }
	if(!ob->query_temp("naiyaoer")&&ob->query("party/level")<6) {
		command("say ��û���ܵ������ʲô����ɻ�ȥ��\n");
		return 1; }
	if(ob->query_temp("naiyaoer")==1) {
		ob->set("party/party_name",HIB"ҩ����"NOR);
		ob->set("party/rank",MAG"ׯ��"NOR);
		ob->set("party/level",2);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"�ǹ��������������ҵ���\n");
		command("say �ã�������ڹ��кú���ϰҽҩ�ھ��ɣ�\n");
	}
	if(ob->query_temp("naiyaoer")==2) {
		ob->set("party/party_name",HIB"ҩ����"NOR);
		ob->set("party/rank",HIM"ҩ��"NOR);
		ob->set("party/level",3);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"���ҽҩ�ھ���Щ������\n");
		command("say ���������ҩ����ȡҩ���ˡ�\n");
		return 1;
	}
	if(ob->query_temp("naiyaoer")==3) {
		ob->set("party/party_name",HIB"ҩ����"NOR);
		ob->set("party/rank",CYN"ҩʦ"NOR);
		ob->set("party/level",4);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"���ҽҩ�ھ����г�����\n");
		command("say ���������ҩ�������Ƶ�ҩ�ˡ�\n");
		return 1;
	}
	if(ob->query_temp("naiyaoer")==4) {
		ob->set("party/party_name",HIB"ҩ����"NOR);
		ob->set("party/rank",HIC"ҽʦ"NOR);
		ob->set("party/level",5);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"���ҽҩ�ھ������˺ܶࡣ\n");
		command("say ���������ҩ���ȵ�ҩ�������ˡ�\n");
		return 1;
	}
	if(ob->query_temp("naiyaoer")==5) {
		ob->set("party/party_name",HIB"ҩ����"NOR);
		ob->set("party/rank",HIG"����"NOR);
		ob->set("party/level",6);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"���ҽҩ�ھ�ѧ�úܲ���\n");
		command("say �������ʽ��Ϊ��ҩ���ȵĵ����ˡ�\n");
		return 1;
	}
}
