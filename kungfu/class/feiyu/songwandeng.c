// NPC: songwandeng.c ������С֮һ������ʦ�� �����
// Created by M.A.D. 1999.7.21
// Modified by M.A.D. 1999.7.21
// 
// ԭ������!  �����书--����ȭ�������㽣��

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void recover_ob();

void create()
{
        set_name("�����", ({ "song wandeng","song"}) );
        set("nickname", MAG"��������ͽ"NOR );
        set("gender", "����" );
        set("age", 20);
        set("per", 20);
        set("long",
                "������ǡ�������������ɽׯׯ�������ϵĴ�ͽ��.\n������ȥ��Լ��ʮ�꣬�ߴ�����,����֮��,�������ơ�\n");
        set("attitude", "friendly");

        set("qi", 1000);
        set("max_qi", 1000);
        set("jingli", 800);
        set("max_jingli", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);

        set("combat_exp", 300000);

        set_skill("cuff", 100);          //����ȭ��
        set_skill("force", 100);         //�����ڹ�
        set_skill("dodge", 100);         //�����Ṧ
        set_skill("parry", 100);         //�����м�
        set_skill("feiyu-jian", 100);    //���㽣��
        set_skill("youyu-quan", 100);    //����ȭ
        set_skill("fish-steps", 100);    //���β���
        set_skill("tianlongforce", 100); //������
         set_skill("sword", 100);         //��������
        set_skill("tao",100);            //��ѧ�ķ�
         
		map_skill("cuff", "youyu-quan");
		map_skill("force", "tianlongforce");
		map_skill("sword", "feiyu-jian");
		map_skill("dodge", "fish-steps");

        prepare_skill("sword", "feiyu-jian");

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

void attempt_apprentice(object me)
{
        if ( (int)me->query("combat_exp")>10000 && (string)me->query("family/family_name") != "������") {
                command("say " + RANK_D->query_respect(me)+"��Ȼ������ʦָ�����ֺ������Ϊʦ�أ�");
                return;
        }

        command("say �ðɣ��Ҿ���������ͽ�ܰɡ�");
        command("say �������书�������Ҫ�úõ�ѧѽ!");
        command("recruit " + me->query("id"));
}

void recover_ob()
{
        command("yun recover");
        return;
}
