// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"Ы��"NOR, ({ "xie zi", "xie" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ���ƴ�Ķ�Ы��β�͸߸ߵ����š�\n");
        set("attitude", "peaceful");
 
        set("str", 30);
        set("cor", 26);

        set("limbs", ({ "ͷ��", "����", "β��", "ǯ��" }) );
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
	object ob1;
	message_vision(HIR"$N���彩Ӳ�����������ȣ�$N���ˡ�\n"NOR, this_object());
	ob1 = new(__DIR__"obj/xiedu");
	ob1->move(environment(this_object()));
	destruct(this_object());
}
