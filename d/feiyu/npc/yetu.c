// NPC: yetu.c
// Created by Zeus 1999.4.10
// Modified by M.A.D. 1999.7.21
// 
// 

inherit NPC;

void create()
{
        set_name("Ұ��", ({ "ye tu", "ye", "hare" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ�ÿɰ���СҰ�á�\n");
        set("attitude", "peaceful");
	
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 500);
	
        set_temp("apply/attack", 2);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

        setup();
}

void die()
{
        object ob;
        message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        ob = new("/d/feiyu/obj/turou");
        ob->move(environment(this_object()));
        destruct(this_object());
}
	
