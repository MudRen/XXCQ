// NPC: zzman.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit NPC;

void create()
{
        set_name("׳��������", ({ "young man"}) );
        set("gender", "����" );
        set("age", 20+random(20));
        set("long",
                "����һλ׳�������꣬�����ḻ���Ǽ������������\n");
        set("attitude", "friendly");

        set("qi", 300);
        set("max_qi", 300);
        set("jingli", 800);
        set("max_jingli", 800);

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 10);

        set("combat_exp", 3000);

        setup();
}
