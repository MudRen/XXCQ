// NPC: wensijuan.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.4.7
// 
// 

inherit NPC;

void recover_ob();

void create()
{
        set_name("��˿��", ({ "wen sijuan"}) );
        set("gender", "����" );
        set("age", 45);
        set("per", 15);
        set("long",
                "��λ�ϸ羭���������⣬���úܶ཭����ء��������ֺ������ֺŵ��ϴ�\n");
        set("attitude", "friendly");

        set("qi", 2000);
        set("max_qi", 2000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 250);

        set("combat_exp", 2000000);

        set_skill("lphand", 180);    //ʩ���ַ�
        set_skill("force", 180);     //�����ڹ�
        set_skill("dodge", 180);     //�����Ṧ
        set_skill("parry", 180);     //�����м�
        set_skill("duzun", 180);     //Ω������
        set_skill("poisonk", 180);   //��ҩ֪ʶ
        set_skill("zhixin", 180);    //�¹�֪��
        set_skill("qianli", 180);    //����ǧ��
        set_skill("literate", 160);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzun");
        map_skill("parry", "duzun");

	prepare_skill("lphand", "duzun");

	create_family("���ֺ��¼�", 3, "����");

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.weiwo" :),
		(: recover_ob :)
        }) );

        add_money("gold", 10);

	carry_object("/d/wenjia/obj/chouduan")->wear();
}

void recover_ob()
{
        command("yun recover");
        return;
}
