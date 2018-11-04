// xiezi.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��Ы��", ({ "duxie", "xiezi" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ�����ɫ���Ķ�Ы�ӣ���˵�޶��ޱȡ�\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "ǰ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 40000);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 2);
        set_temp("apply/armor", 10);

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
        message_vision("$Nβ�͡�ž����һ���۶ϣ�ð��һ��֭Һ�����ˡ�\n", this_object());
//        ob = new(__DIR__"xiezike");
//        ob->move(environment(this_object()));
        destruct(this_object());
}

