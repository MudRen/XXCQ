// huoji. ҩ�̻��

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("����", ({ "a wang", "a", "wang", "awang"}));
	set("str", 20);
	set("gender", "����");
	set("age", 27);
	set("long", "����һ���ǳ���׳�������ˣ����ƺ����Ṧ��\n");
	set("max_qi",350);
	set("eff_qi",350);
	set("qi",350);
	set("combat_exp", 2000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

#include "die_quest.c"
