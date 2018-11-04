// NPC: wenerbao.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.3.27
// 
// 

inherit NPC;

void create()
{
        set_name("�¶���", ({ "wen erbao", "erbao"}) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long",
                "�¶������´����¼����ö�λ������"+
                "�����ڹ㳡����������ֹ�����¼ҵ��ӵܽ��롣\n");
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
