// /d/lingjiu/npc/lu.c
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"��"NOR, ({ "he"}) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ��ɫ�ĺף�ͷ���ĺ���ر����ۡ�\n");
        set("attitude", "peaceful");
 
        set("str", 30);
        set("cor", 26);

        set("limbs", ({ "ͷ��", "����", "צ��", "���"}) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 3000);

        set_temp("apply/attack", 50);
        set_temp("apply/damage", 10);
	set_temp("apply/defence",30);
	set_temp("apply/armor",10);

	set("yaowang_zhuo",1);
	setup();
}

void die()
{
	object ob;
	message_vision(HIR"$N���������³�򣬵��ڵ��ϣ�$N���ˡ�\n"NOR, this_object());
	ob = new(__DIR__"obj/hedinghong");
	ob->move(environment(this_object()));
	destruct(this_object());
}
