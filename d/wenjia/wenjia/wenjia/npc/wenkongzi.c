// NPC: wenkongzi.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.7.12
// 
// 

#include <ansi.h>

inherit NPC;
int ask_teach();
void greeting(object);
void init();

void create()
{
        set_name("�¿���", ({ "wen kongzi", "wen"}) );
        set("gender", "����" );
        set("nickname",MAG"������"NOR);
        set("age", 25+random(10));
        set("long",
                "�¿������¼Ҷ�����īˮ�����ˡ�\n");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("strike", 20);
	set_skill("dodge", 30);
	set_skill("parry", 20);
	set_skill("force", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);

        set("inquiry", ([
                "study" : (: ask_teach :),
		"����" : (: ask_teach :),
		"ѧϰ" : (: ask_teach :),
		"literate" : (: ask_teach :),
        ]) );

	create_family("���ֺ��¼�", 4, "����");

        setup();
}

void init()
{	
        object ob;

        ::init();
        add_action("do_xue", "wen");

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say("�¿��ӿ������˽������������е��飬˵��������λ" + RANK_D->query_respect(ob)
             + "�ǵ���������ѧϰ����?��\n");
}

int ask_teach()
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if ( me->query_temp("xuet"))
	{
		tell_object(me,"�㲻������ѧϰ��?\n ");
		return 1;
	}

	message_vision("�¿����º͵�Ц��Ц����"+RANK_D->query_respect(me)+"��������ѧ�ģ�\n", me);
	command("look "+me->query("id"));

	if ((int)me->query_skill("literate", 1) > 31)
	{
		message_vision("\n�¿���ǫѷ��Ц��Ц������λ"+RANK_D->query_respect(me)+"����ѧʶ�����������ҽ̡�\n\n", me);
		return 1;
	}

	else if ((int)me->query("age") > 18)
	{
		message_vision("\n�¿���Ц��ҡ��ҡͷ������ҰС�ã�Ҳ���ǽ̺̽��ӣ��ɲ��ҽ�����\n\n", me);
		return 1;
	}

	else
	{
		message_vision("\n�¿��Ӹ��˵�˵���úã������á�\n\n", me);
		message_vision("$N�ߵ�һ������ǰ����������\n\n", me);
		me->apply_condition("xuetang", 10);
		me->set_temp("xuet", 1);
		return 1;
	}
}