// NPC: feiyudizi.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.5.12
// 
// 

inherit NPC;

void create()
{
        set_name("�������", ({ "dizi"}) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long",
                "����һλ���������ӡ������ﵽ�����Կ������ַ�ɫ���ˡ�\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 400);
        set("max_jingli", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 50000);

        set_skill("unarmed", 50);     //������
        set_skill("force", 50);       //�����ڹ�
        set_skill("dodge", 50);       //�����Ṧ
        set_skill("parry", 50);       //�����м�
        set_skill("literate", 30);    //����д��
 	    set_skill("youyu-quan",90);  //����ȭ
         create_family("������", 6, "����");

        setup();
}
