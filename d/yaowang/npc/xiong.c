// /d/lingjiu/npc/lu.c
// By ɽèAdx 16:53 99-10-25
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIB"����"NOR, ({ "hei xiong", "xiong" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�ߴ�ĺ��ܣ��ǳ���׳��\n");
        set("attitude", "peaceful");
 
        set("str", 30);
        set("cor", 26);

        set("limbs", ({ "ͷ��", "����", "צ��"}) );
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
	object ob1, ob2, ob3;
	message_vision(HIR"$N����һ�ᣬ���ڵ��ϣ�$N���ˡ�\n"NOR, this_object());
	ob1 = new(__DIR__"obj/xiongdan");
	ob2 = new(__DIR__"obj/xiongzhang");
	ob3 = new(__DIR__"obj/xiongzhang");
	ob1->move(environment(this_object()));
	ob2->move(environment(this_object()));
	ob3->move(environment(this_object()));
	destruct(this_object());
}
