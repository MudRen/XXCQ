//duwang.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("ǧ�궾��", ({ "duwang", "wang" }) );
	set("race", "Ұ��");
	set("age", random(10));
	set("long", "��������������һֻ���󣬵��ǻ���ȴû��һ��ë���ֺ�����һ��⻬��\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 100000+random(100000));

	set_temp("apply/attack", 50+random(10));
	set_temp("apply/damage", 50+random(10));
	set_temp("apply/armor", 30+random(10));
	set_temp("apply/defence",40+random(10));
	setup();
}

void init()
{
        object me,ob;
        ::init();
        if ( interactive(me = this_player()) && living(this_object()) )
        {
		       remove_call_out("kill_ob");
        	       call_out("kill_ob", 1, me);
        }
}

int hit_ob(object me, object ob, int damage)
{
	if ((int)ob->query("combat_exp") > 500000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")	&& (int)ob->query_condition("snake_poison") < 20 )
	{
		ob->apply_condition("snake_poison", 100);
        	tell_object(ob, HIG "�����һ����ľ�ĸо��Ա�ҧ�еĵط���������ȫ��\n" NOR );
	}
}

void die()
{
	object ob;
	message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
//	ob = new("/d/shenlong/obj/shedan");
//	ob->move(environment(this_object()));
//	ob = new("/d/baituo/obj/shepi");
//	ob->move(environment(this_object()));
	destruct(this_object());
}