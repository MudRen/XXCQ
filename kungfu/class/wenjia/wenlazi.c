// NPC: wenlazi.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.4.7
// 
// 

inherit NPC;

void create()
{
        set_name("������", ({ "wen lazi", "lazi"}) );
        set("gender", "����" );
        set("age", 50);
        set("per", 10);
        set("long",
                "����������ֺ������ֺŵĸ����ԣ�����Ĭ���ԣ�\n"+
                "��ɫ������˫��һֱ���������\n");
        set("attitude", "friendly");

        set("qi", 1000);
        set("max_qi", 1000);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);

        set("combat_exp", 80000);

        set_skill("hand", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("literate", 60);

        add_money("silver", 10);

        setup();
}
