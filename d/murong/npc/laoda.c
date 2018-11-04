// laoda.c

inherit NPC;
#include <ansi.h>
int ask_price();        
int ask_hire();
void create()
{
	set_name("���ϴ�", ({ "laoda" , "chuanlaoda" }) );
	set("long", "�������Ÿ��������ʹ������顣\n");
	set("gender", "����" );
	set("age", 42);
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϴ�");
	set("inquiry", ([
		"name": "��������Ĵ��ϴ󣬿͹�������̫�������ϴ����ź��š�",
		"rumors": "��̫������ǲ����Ի�֮�أ����������Ĺ���Ľ�ݺ͹���ׯ����̫�����档",
		"here": "�����Ǹ���Ψһ����ͷ�ˡ�",
		"�ʹ�": (: ask_hire :),
		"��Ǯ" : (: ask_price :),
	]) );
	setup();
}                                      

int ask_hire()
{
	command("say �͹���Ҫȥ���ﰡ��������˵��̫�����ˮ½����������Ϥ����Ҫ������ȥ��"+BLINK HIW+"��Ǯ"+CYN+"��������");
	return 1;
}
int ask_price()
{
	object ob=this_player();
	int money = 5000;

	if (ob->query("age") < 16)
		money = (ob->query("age") - 13) * 500;
	if ((ob->query("family/family_name") == "����Ľ��" 
	||  ob->query("family/family_name") == "�һ���")) 
	{
		say ("���ϴ�˵�������ҽ������ѣ���η��Ĳ�ȡ���͹����ϴ��ɡ�\n");
		command("say �������ġ�\n");                                
		message_vision("���ϴ�й���һ������������$Nһͬ����С�ۡ�\n", ob);		
		ob->move("/d/murong/xiaozhou1");                  
	}
		 
	else 
	{
		say("���ϴ���Ц��Ц��˵�����ҿ��͹����ƣ�������" + MONEY_D->price_str(money) + "�ɡ�\n" );
		command("hehe laoda");
		ob->set_temp("ask_price", 1);
	}
	return 1;
}
int accept_object(object who, object ob)
{
	int money = 5000;

	if (who->query("age") < 16)
		money = (who->query("age") - 13) * 500;
	if ( !who->query_temp("ask_price") 
	&& (who->query("family/family_name") != "����Ľ��"
	||  who->query("family/family_name") != "�һ���" )) 
	{
		command("say ���ϴ����ˣ�˵������������Ǯû����ô��\n");
		return 1;
	}		
	if (!ob->query("money_id") || ob->value() < money)  
	{
		command("say �͸���ô��Ǯ���������綼������\n");
		return 1;
	}
	command("say ���ϴ�˵�����������ġ�\n"); 
	message_vision("���ϴ�й���һ������������$Nһͬ����С�ۡ�\n", who);
	who->delete_temp("ask_price");
	who->move("/d/murong/xiaozhou1");                  
	return 1;
}