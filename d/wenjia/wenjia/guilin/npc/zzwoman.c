// NPC: zzwoman.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit NPC;

void create()
{
        set_name("׳��Ů����", ({ "young woman"}) );
        set("gender", "Ů��" );
        set("age", 20+random(20));
        set("long",
                "����һλ׳��Ů���꣬��ò�Ϻã��Ǽ������������\n");
        set("attitude", "friendly");

        set("qi", 300);
        set("max_qi", 300);
        set("jingli", 600);
        set("max_jingli", 600);

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 10);

        set("combat_exp", 3000);

        setup();
}
