// longchuichui.c 

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("ʿ��", ({ "shi bing", "bing" }));
	set("long", 
"���ʿ�����Ͽ���ȥ�ֺ����ģ�ÿ��͸�������Ӫ�ţ�\n"
"�����Ĵ���������֪���������á�\n");
	set("gender", "����");
	set("age", 20);
        set("title", "�����Ǳ�Ӫ����");
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

	setup();

	carry_object(__DIR__"obj/junfu")->wear();
	carry_object(__DIR__"obj/dgqiang")->wield();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_kill","kill");
	add_action("do_kill","fight");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "ʿ���ñ�������۹����´������㡣\n");
			break;
		case 1:
			say( "ʿ����������������Ӫǰ�治�ö��������߿��ߣ�������\n");
			break;
	}
}

int do_kill()
{
	object ob,me;
	ob = this_player();
	me = this_object();
	message_vision("$N����$n���һ�����ڱ�Ӫǰ�����£����ǻ�ò��ͷ��˰ɣ�\n", me, ob);
	me->kill_ob(ob);
	ob->kill_ob(me);
	return 1;
}