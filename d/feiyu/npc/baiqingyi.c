// NPC: baiqingyi.c ������
// Created by Atlus 1999.10.4
// Modified by Atlus 1999.10.4
// 

#include <ansi.h>

inherit NPC;

void recover_ob();

void create()
{
        set_name("������", ({ "bai qingyi","bai"}) );
        set("gender", "����" );
        set("age", 40);
        set("per", 30);
        set("long",
                "������ȥ�������꣬˫�޷�����\n����˫��֮��,ȴ����һ�������˱�,���з���,��������������!\n");
        set("attitude", "friendly");

        set("qi", 2300);
        set("max_qi", 2300);
        set("jingli", 2300);
        set("max_jingli", 2300);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);

        set("combat_exp", 750000);

       
        set_skill("force", 130);         //�����ڹ�
        set_skill("dodge", 200);         //�����Ṧ
        set_skill("parry", 130);         //�����м�
        set_skill("literate", 100);      //����д��
        set_skill("sword", 130);         //��������
        set_skill("feiyu-jian", 130);    //���㽣��
        set_skill("youyu-quan", 130);    //����ȭ
        set_skill("fish-steps", 200);    //���β���
        set_skill("tianlongforce", 130); //������
        set_skill("cuff", 130);          //����ȭ��

        map_skill("cuff", "youyu-quan");
		map_skill("force", "tianlongforce");
		map_skill("sword", "feiyu-jian");
		map_skill("dodge", "fish-steps");
		
		create_family("������", 3, "����");

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
