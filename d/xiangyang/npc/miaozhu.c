// huoji. ҩ�̻��

inherit NPC;
#include <ansi.h>

void create()
{
     set_name("��ף", ({ "miaozhu", "zhu", "miao"}));
	set("str", 20);
	set("gender", "����");
	set("title", "����������");
	set("age", 45);
	set("long", "һ����������ˣ���Ȼֻ�а�٣���ȴ����һ�ѻ��׵ĺ��ӡ�\n");
	set("max_qi",300);
	set("eff_qi",300);
	set("qi",300);
	set("combat_exp", 1000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

/* void die()
{
	object killer;

	if( objectp(killer = query_temp("last_damage_from")) ) {
		if (killer->query_temp("qljob")==2)
		{
			killer->set_temp("qljob",4);
			killer->apply_condition("jyfail",0);
		}
	}
	::die();
} */
#include "/d/quanli/npc/die_quest.c"
