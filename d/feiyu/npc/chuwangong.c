// NPC: chuwangong.c ������С֮һ������ʦ��  ����
// Created by M.A.D. 1999.7.21
// Modified by M.A.D. 1999.7.21
// 
// ԭ������!  �����书--����ȭ�������㽣��

#include <ansi.h>

inherit NPC;

void recover_ob();

void create()
{
        set_name("����", ({ "chu wangong","chu"}) );
        set("nickname", MAG"������С"NOR );
        set("gender", "����" );
        set("age", 20);
        set("per", 10);
        set("long",
                "�����ǡ�������������ɽׯׯ�������ϵ�ͽ��֮һ��������С֮һ,����Ҫ�����㽣����\n������ȥ��Լ��ʮ�꣬ʮ�־��������ӡ�\n");
        set("attitude", "friendly");

        set("qi", 1000);
        set("max_qi", 1000);
        set("jingli", 800);
        set("max_jingli", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);

        set("combat_exp", 100000);

        set_skill("cuff", 60);          //����ȭ��
        set_skill("force", 60);         //�����ڹ�
        set_skill("dodge", 60);         //�����Ṧ
        set_skill("parry", 60);         //�����м�
        set_skill("literate", 40);      //����д��
        set_skill("feiyu-jian", 60);   //���㽣��
        set_skill("youyu-quan", 60);    //����ȭ
        set_skill("fish-steps", 60);    //���β���
        set_skill("tianlongforce", 60); //������
        
        create_family("������", 5, "����");

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: recover_ob :)
        }) );

        add_money("silver", 10);

        carry_object("/d/feiyu/obj/jinshenfu")->wear();
        carry_object("/d/feiyu/obj/changjian")->wield();
}


void recover_ob()
{
        command("yun recover");
        return;
}
