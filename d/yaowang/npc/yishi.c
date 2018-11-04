// NPC �ƹ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

int ask_me();

void create()
{
	set_name("�ƶﻯ", ({ "tang ehua", "tang", "ehua" }) );
	set("title", HIB"ҩ����"NOR+HIC"ҽʦ"NOR);
	set("long", "���ǻش��õ�������ҽʦ�������������\n" );
	set("gender", "����" );
	set("age", 52);
	set("combat_exp", 100);
	set("attitude", "friendly");

        set("inquiry", ([
		"heal" : (: ask_me :),
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

	if((string)ob->query("party/party_name")==HIB"ҩ����"NOR) {
		command("say ��λ�ֵ������ˣ��������\n");
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
	object me;
	int i, obj;

	me = this_player();
	i = (me->query("max_qi")-me->query("eff_qi"));
	obj = me->query("max_qi");

	if(!me->query_temp("heal")) {
		command("say "+RANK_D->query_respect(me)+
			"���Ƚ����"+MONEY_D->price_str(i*10)+"�ɣ�\n");
		return 1;
	}
	me->delete_temp("heal");
	me->set("eff_qi", obj);
	me->set("qi", obj);
	message_vision ("�ƶﻯΪ$N���˰������ó�һ��������$NѨλ�����˼��¡�\n", me);
	command("say ����˺õò���ˣ�");
	return 1;
}

int accept_object(object me, object ob)
{
	int i=(me->query("max_qi")-me->query("eff_qi"));

	if(i<5) i=5;

	command("smile");
	command("say �Ǻǣ���л��λ" + RANK_D->query_respect(me) + " ��");

	if( ob->query("money_id") ) 
	{
		if(ob->value() < (i*10))
		{
			command("say ��λ����δ�����˵㡣");
			return 1;
		}
		else
		{
			me->set_temp("heal",1);
			command("say ���������ˣ�");
			return 1;
		}
	}
	return 1;
}
