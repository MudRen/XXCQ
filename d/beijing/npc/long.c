// longchuichui.c 

inherit NPC;

#include <ansi.h>

//string *query_killer() { return killer; }

void create()
{
	set_name("������", ({ "long chuichui", "long" }));
	set("long", 
"����������ֵ����ֳ�ˮ��������廨�ᣬһ����\n"
"׼�ٲ��硣��������С�������ӳ��úܾ����忡��\n"
"����С�Ĵ�����֮һ��Ҳ�����������������һ����\n");
	set("gender", "����");
	set("age", 20);
        set("title", BLU"Ѳ��"NOR);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 8000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("club", 100);
	set_skill("strike", 100);
	set_skill("cuff", 100);

	set("chat_chance", 1);
	set("chat_msg", ({
		(: random_move :),
	}));

	setup();

	carry_object("d/beijing/npc/obj/yayifu")->wear();
	carry_object("/clone/weapon/gangdao");
	carry_object("d/beijing/npc/obj/shuihuo-gun")->wield();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

//	add_action("do_fight", "fight");
//	add_action("do_kill","kill");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "�����������ȵ����������صأ���ֹ��ܶ�Ź��������û�У�������\n");
			break;
		case 1:
			say( "�������ñ�������۹�ע�����ڳ���ÿһ���ˡ�\n");
			break;
		case 2:
			say( "�������������������ÿ����ÿ���������\n");
			break;
	}
}
/*
int do_fight()
{
	object ob,me;
	ob = this_player();
	me = this_object();
	message_vision("$N����$n���һ����������ǰ��ܣ�������ѽ��\n", me, ob);
	message_vision("ֻ��$N����ľ����$n�ݺݵ�һ�ӡ�\n", me, ob);
	ob->unconcious();
	ob->move("/u/exam/laofang");
	return 0;
}

int do_kill()
{
	object ob,me;
	ob = this_player();
	me = this_object();
	message_vision("$N����$n���һ����������ǰ���ף������ﻹ��������\n", me, ob);
	command("unwield gun");
	command("wield dao");
	me->kill_ob(ob);
	return 1;
}
*/