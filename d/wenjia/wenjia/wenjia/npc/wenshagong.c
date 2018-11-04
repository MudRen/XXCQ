// NPC: wenshagong.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.4.7
// 
// 

inherit NPC;
void recover_ob();

void create()
{
        set_name("��ɰ��", ({ "wen shagong", "shagong"}) );
        set("gender", "����" );
        set("age", 65);
        set("per", 10);
        set("long",
                "���ֺ�xxxxxxxxxxxxxxxxxx��\n");
        set("attitude", "friendly");

        set("qi", 2000);
        set("max_qi", 2000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 200);

        set("combat_exp", 1300000);

        set_skill("lphand", 140);    //ʩ���ַ�
        set_skill("force", 140);     //�����ڹ�
        set_skill("dodge", 140);     //�����Ṧ
        set_skill("parry", 140);     //�����м�
        set_skill("duzun", 140);     //Ω������
        set_skill("zhixin", 140);    //�¹�֪��
        set_skill("qianli", 140);    //����ǧ��
        set_skill("poisonk", 140);   //��ҩ֪ʶ
        set_skill("shengdu", 140);   //����
        set_skill("literate", 100);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "shengdu");
        map_skill("parry", "shengdu");

	prepare_skill("lphand", "shengdu");

	create_family("���ֺ��¼�", 3, "����");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.wusheng" :),
		(: recover_ob :)
        }) );

        setup();

        add_money("gold", 5);

	carry_object("/d/huanhua/npc/obj/liangongfu")->wear();
}
void recover_ob()
{
        command("yun recover");
        return;
}
