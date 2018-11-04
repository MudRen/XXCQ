// NPC �ƹ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

int ask_me();
int ask_ok();

void create()
{
	set_name("½��", ({ "lu feng", "lu", "feng" }) );
	set("title", HIB"ҩ����"NOR+WHT"����"NOR);
	set("long", "����ҩ���ȸ����ƹܴ���ҩ�\n" );
	set("gender", "����" );
	set("age", 52);
	set("combat_exp", 100);
	set("attitude", "friendly");

        set("inquiry", ([
		"job" : (: ask_me :),
		"ok" : (: ask_ok :),
        ]));

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

	if (i<=90) {
		command("wa "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)
			+"�����������˰�����ȥ�ش�����ҽʦ���㿴���ɣ�\n");
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

int ask_me()
{
	object ob, me;
	me = this_player();

	if( me->query("party/party_name")!=HIB"ҩ����"NOR ) {
		command("say �㲻������Ļ�ƣ����ֻ���ô��������أ�\n");
		return 1; }

	if( (int)me->query_skill("healing",1)<20 ) {
		command("say �㻹����������ɻ\n");
		return 1; }

	if( (int)me->query_skill("healing",1)>=40 ) {
		command("say �㲻��Ҫ�����ֻ�ģ�\n");
		return 1; }

	if ( !me->query_temp("renwu_name1") ) {
		ob = new(__DIR__"obj/tong");
		ob->move(me);
		me->set_temp("renwu_name1",1);
		message_vision(YEL"½�����$Nһ��ˮͰ��\n"NOR, me);
		command("say ���Ͱˮ��ҩ�ﶼ���ã�\n");
		return 1;
	}
	else {
		command("say ���Ȱѻ����ɣ�\n");
		return 1;
	}
}

int ask_ok()
{
	object money, me;
	int amount,i;
	i=random(3);
	me = this_player();
	amount = random(30);
	if ( me->query_temp("renwu_wancheng")==100 ) {
		me->delete_temp("renwu_wancheng");
		me->delete_temp("renwu_name1");
		if ( present("tong", me) ) {
			message_vision ("$N�������е�ˮͰ��\n", me);
			destruct(present("tong", me));
        	        money = new ("/clone/money/silver");
                	money->move(me);
			money->set_amount(amount);
			command("say �ã��ɵò�����������ģ�\n");
			if(i=1) {me->add("max_jingli",1);}
		} else { 
			command("hmm "+me->query("id"));
			command("say ��û�ã�����ɻ��ѹ��߶����ˣ�\n");
			}
	} else {
		command("say ��Ͽ�ȥ�ѻ���갡��\n");
		}
        return 1;
}
