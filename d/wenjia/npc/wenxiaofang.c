// NPC: wenxiaofang.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.3.28
// 
// 

inherit NPC;

void create()
{
        set_name("��С��", ({ "wen xiaofang"}) );
        set("gender", "Ů��" );
        set("age", 10+random(4));
        set("long",
                "��С��һ���ɰ�������СŮ��������ѧ������顣\n");
        set("combat_exp", 100);
        set("attitude", "friendly");

        set("qi", 100);
        set("max_qi", 100);
        set("jingli", 200);
        set("max_jingli", 200);

        set_skill("literate", 30);

        setup();
}

