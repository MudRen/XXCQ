// huoji. ҩ�̻��

inherit NPC;
#include <ansi.h>

void create()
{
    set_name("����̫̫", ({ "laotai", "lao", "taitai", "li"}));
	set("str", 20);
	set("gender", "Ů��");
	set("age", 65);
	set("long", "һ���������Ƶ������̣����������ض��²����ˡ�\n");
	set("max_qi",300);
	set("eff_qi",300);
	set("qi",300);
	set("combat_exp", 1000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

#include "/d/quanli/npc/die_quest.c"
