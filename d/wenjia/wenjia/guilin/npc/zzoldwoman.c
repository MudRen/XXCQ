// NPC: zzold.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit NPC;

void create()
{
        set_name("׳��������", ({ "old woman"}) );
        set("gender", "Ů��" );
        set("age", 50+random(10));
        set("long",
                "����һλ׳�������ţ�ͷ��ȫ�ף��ܴ�������ӡ�\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 600);
        set("max_jingli", 600);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 15);

        set("combat_exp", 3500);

        setup();
}
