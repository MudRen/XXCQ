// huoji. ҩ�̻��

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("���Ϻ�", ({ "hei laohan", "hei", "laohan"}));
	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "����һ��Ƥ����ڵ��Ϻ�������ȥ�����˪��\n");
	set("max_qi",300);
	set("eff_qi",300);
	set("qi",300);
	set("combat_exp", 1000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

#include "die_quest.c"
