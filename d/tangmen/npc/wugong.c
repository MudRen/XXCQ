// wugong.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���", ({ "wugong", "gong", "wu" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ���ɫ�Ķ���򼣬����һ��������\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "βǯ" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 25000);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 15);

        setup();
}

int hit_ob(object me, object ob, int damage)
{
	if ((int)ob->query("combat_exp") > 100000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")	&& (int)ob->query_condition("xie_poison") < 20 )
	{
		ob->apply_condition("xie_poison", 40);
        	tell_object(ob, HIG "����ñ����еĵط�һ����ľ��\n" NOR );
	}
}

void die()
{
        object ob;
        message_vision("$N���ǡ�ž����һ�������ˣ�����鶯�˼��£����ˡ�\n", this_object());
//        ob = new(__DIR__"xiezike");
//        ob->move(environment(this_object()));
        destruct(this_object());
}

