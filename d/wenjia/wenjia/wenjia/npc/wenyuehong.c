// NPC: wenyuehong.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.4.7
// 
// 

inherit NPC;
void recover_ob();

void create()
{
        set_name("��Լ��", ({ "wen yuehong", "yuehong"}) );
        set("gender", "����" );
        set("age", 36);
        set("per", 25);
        set("long",
                "����˿���ȥ��ѬѬ�ģ�һ����֪���Ǹ��ƹ��˳ơ����׹��ӡ�\n"+
                "���������ֺ��еĻ��ֺŵ��϶�����Ҳ�������ɳ�ȥִ������\n");
        set("attitude", "friendly");

        set("qi", 2000);
        set("max_qi", 2000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);

        set("combat_exp", 2500000);

        set_skill("lphand", 150);    //ʩ���ַ�
        set_skill("force", 150);     //�����ڹ�
        set_skill("dodge", 150);     //�����Ṧ
        set_skill("parry", 150);     //�����м�
        set_skill("duzun", 150);     //Ω������
        set_skill("zhixin", 150);    //�¹�֪��
        set_skill("qianli", 150);    //����ǧ��
        set_skill("poisonk", 150);   //��ҩ֪ʶ
        set_skill("bupangguan", 150);//���ֲ��Թ�
        set_skill("literate", 130);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "bupangguan");
        map_skill("parry", "bupangguan");

	prepare_skill("lphand", "bupangguan");

	create_family("���ֺ��¼�", 3, "����");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
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
