// huoji. ҩ�̻��

inherit NPC;
#include "/d/bianliang/npc/hhjob.h"

void create()
{
	set_name("Ƚ��Ȼ", ({ "ran yiran", "ran", "yiran"}));
	set("str", 20);
	set("gender", "����");
	set("title", "����Ⱦ�����Ĵ�����");
	set("age", 45);
	set("long", "����һ�������ְ����������ӣ���Ƚ���µ������ӣ�Ҳ��һ�ֵ�Ⱦ��������\n");
	set("combat_exp", 250);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "Ƚ��Ȼ��Χȹ�ϲ��˲��ֵ�����λ" + RANK_D->query_respect(ob)
				+ "��������ҪȾ����\n");
}
