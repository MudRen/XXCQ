// NPC: zzgirl.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit NPC;

void create()
{
        set_name("׳��СŮ��", ({ "girl"}) );
        set("gender", "Ů��" );
        set("age", 4+random(4));
        set("long",
                "����һ��׳��СŮ�������ÿɰ���\n");
        set("attitude", "friendly");

        set("qi", 200);
        set("max_qi", 200);
        set("jingli", 200);
        set("max_jingli", 200);

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 5);

        set("combat_exp", 1000);

        setup();
}
