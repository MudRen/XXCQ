// NPC �ƹ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

int ask_me();
int ask_ok();

void create()
{
	set_name("��δ", ({ "chi wei", "chi", "wei" }) );
	set("title", HIB"ҩ����"NOR+WHT"����"NOR);
	set("long", "���ǻش��õ��ʷ�����������ش��õ����ۡ�\n" );
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

int ask_me()
{
	object ob, me;
	me = this_player();

	if( me->query("party/party_name")!=HIB"ҩ����"NOR ) {
		command("say �㲻������Ļ�ƣ����ֻ���ô��������أ�\n");
		return 1; }

	if( (int)me->query_skill("healing",1)>=20 ) {
		command("say �㲻��Ҫ�����ֻ�ģ�\n");
		return 1; }

	if ( !me->query_temp("renwu_name") ) {
		ob = new(__DIR__"obj/saoba");
		ob->move(me);
		message_vision(YEL"��δ����$Nһ֧ɨ�ѡ�\n"NOR, me);
	switch ( random(7) ) {
	case 0 :
		me->set_temp("renwu_name","��Ϣ��");
		command("say ��ȥ��ɨ(dasao)һ����Ϣ�Ұɣ�\n");
		return 1;
	case 1 :
		me->set_temp("renwu_name","����");
		command("say ��ȥ��ɨ(dasao)һ�±����ɣ�\n");
		return 1;
	case 2 :
		me->set_temp("renwu_name","����");
		command("say ��ȥ��ɨ(dasao)һ�������ɣ�\n");
		return 1;
	case 3 :
		me->set_temp("renwu_name","ͥԺ");
		command("say ��ȥ��ɨ(dasao)һ��ͥԺ�ɣ�\n");
		return 1;
	case 4 :
		me->set_temp("renwu_name","�ش���");
		command("say ��ȥ��ɨ(dasao)һ�´��Űɣ�\n");
		return 1;
	case 5 :
		me->set_temp("renwu_name","����");
		command("say ��ȥ��ɨ(dasao)һ�����ݰɣ�\n");
		return 1;
	case 6 :
		me->set_temp("renwu_name","����");
		command("say ��ȥ��ɨһ�������ɣ�\n");
		return 1;
		}
	}
	else {
		command("say ���Ȱѻ����ɣ�\n");
		return 1;
	}
}

int ask_ok()
{
	object money, me;
	int amount, i;

	me = this_player();
	amount = random(10);
          i = random(7);
	if ( me->query_temp("renwu_wancheng")==100 ) {
		me->delete_temp("renwu_wancheng");
		me->delete_temp("renwu_name");
		if ( present("saoba", me) ) {
			message_vision ("$N�������е�ɨ�ѡ�\n", me);
			destruct(present("saoba", me));
        	        money = new ("/clone/money/silver");
                	money->move(me);
			money->add_amount(amount);
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
