// NPC: chuwangong.c Ҷ��ɫ���м�ʦ��  
// Created by Atlus 1999.7.24
// Modified by Atlus 1999.7.24
// 
// ԭ������!  �����书--���㽣��

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void recover_ob();

void create()
{
        set_name("Ҷ��ɫ", ({ "ye mengse","ye"}) );
        set("gender", "Ů��" );
        set("age", 22);
        set("per", 40);
        set("long",
                "Ҷ��ɫ�ǡ�������������ɽׯׯ������Ҫ�ġ����㡱֮һ������ͨ���㽣����\n������ȥ��Լ��ʮ�꣬��Ϊ���,������ĺɫ��ڤ��,����һ�����ĵİ׻�,���������\n");
        set("attitude", "friendly");

        set("qi", 1500);
        set("max_qi", 1500);
        set("jingli", 1200);
        set("max_jingli", 1200);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);

        set("combat_exp", 500000);

        
        set_skill("force", 120);         //�����ڹ�
        set_skill("dodge", 110);         //�����Ṧ
        set_skill("parry", 120);         //�����м�
        set_skill("literate", 100);      //����д��
        set_skill("sword", 150);         //��������
        set_skill("feiyu-jian", 150);    //���㽣��
        set_skill("youyu-quan", 90);     //����ȭ
        set_skill("fish-steps", 110);    //���β���
        set_skill("tianlongforce", 110); //������
        set_skill("cuff", 120);          //����ȭ��
        set_skill("tao",150);            //��ѧ�ķ�

        map_skill("cuff", "youyu-quan");
		map_skill("force", "tianlongforce");
		map_skill("sword", "feiyu-jian");
		map_skill("dodge", "fish-steps");

		prepare_skill("sword", "feiyu-jian");

		create_family("������", 4, "����");

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
        if ((string)me->query("family/family_name") != "������") {
                command("say " + RANK_D->query_respect(me)+"��Ȼ������ʦָ�����ֺ������Ϊʦ�أ�");
                return;
         }

        if ( (int)me->query("combat_exp")<100000 ) {
                command("say " + RANK_D->query_respect(me)+"�ƺ����δ������ȥ������ĥ��ĥ�������ɣ�");
                return;
        }
        if ((int)me->query_skill("sword", 1) < 100) {
                command("say �ҵ���Ϊȫ�ڡ������ϣ���Ļ��δ����"); 
                command("say " + RANK_D->query_respect(me) + 
                        "�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                return;
         }
        if ((int)me->query("shen") < 30000) {
                command("say ���������������������ɣ��Ե���Ҫ���ϸ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +"�Ƿ����ò�����");
                return;
        }


        command("say �ðɣ��Ҿ���������ͽ�ܰɡ�");
        command("say �����������Ҫ�úõ�ѧѽ!");
        command("recruit " + me->query("id"));
}

void recover_ob()
{
        command("yun recover");
        return;
}
