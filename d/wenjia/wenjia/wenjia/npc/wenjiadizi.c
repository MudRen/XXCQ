// NPC: wendabao.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.7.21
// 
// 

inherit NPC;

void create()
{
        set_name("�¼ҵ���", ({ "dizi"}) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long",
                "����һλ�¼ҵ��ӡ����¼������ﵽ�����Կ������ַ�ɫ���ˡ�\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 400);
        set("max_jingli", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 30000);

        set_skill("lphand", 50);    //ʩ���ַ�
        set_skill("force", 50);     //�����ڹ�
        set_skill("dodge", 50);     //�����Ṧ
        set_skill("parry", 50);     //�����м�
        set_skill("bupangguan", 50);//���ֲ��Թ�
        set_skill("zhixin", 50);    //�¹�֪��
        set_skill("qianli", 50);    //����ǧ��
        set_skill("literate", 30);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzun");
        map_skill("parry", "duzun");

	prepare_skill("lphand", "duzun");

	create_family("���ֺ��¼�", 6, "����");

        setup();
}
