// NPC: wendating.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.7.9
// �޸ļ���
// 

inherit NPC;

void recover_ob();

void create()
{
        set_name("�´���", ({ "wen dating", "dating"}) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long",
                "�´�������С�����¼����ö�λ������\n"+
                "�����ڹ㳡����������ֹ�����¼ҵ��ӵܽ��롣\n");
        set("attitude", "friendly");

        set("qi", 1000);
        set("max_qi", 1000);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);

        set("combat_exp", 800000);

        set_skill("lphand", 100);    //ʩ���ַ�
        set_skill("force", 100);     //�����ڹ�
        set_skill("dodge", 100);     //�����Ṧ
        set_skill("parry", 100);     //�����м�
        set_skill("duzi-du", 100);   //Ω������
        set_skill("zhixin", 100);    //�¹�֪��
        set_skill("qianli", 100);    //����ǧ��
        set_skill("literate", 60);   //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzi-du");
        map_skill("parry", "duzi-du");

        prepare_skill("lphand", "duzi-du");

        create_family("���ֺ��¼�", 5, "����");

        setup();

        add_money("silver", 10);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.feixing" :),
                (: recover_ob :)
        }) );

        carry_object("/d/wenjia/obj/grnduanda")->wear();
}


void recover_ob()
{
        command("yun recover");
        return;
}
