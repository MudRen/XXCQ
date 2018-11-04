// NPC: chuwangong.c �����ϣ��߼�ʦ��  
// Created by Atlus 1999.9.24
// Modified by Atlus 1999.9.24
// 
// ԭ������!  �����书--���㽣��

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void recover_ob();

void create()
{
        set_name("������", ({ "shen xingnan","shen"}) );
        set("nickname", MAG"����������ɽׯׯ��"NOR );
		set("gender", "����" );
        set("age", 50);
        set("per", 30);
        set("long",
                "�������Ƿ���������ɽׯ������,�׵�����������\n��üĿ�续,�ɷ����,�Źڹ���,���ϻ�����һ������.\n");
        set("attitude", "friendly");

        set("qi", 3000);
        set("max_qi", 3000);
        set("jingli", 3000);
        set("max_jingli", 3000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 75);

        set("combat_exp", 1750000);

        set_skill("cuff", 300);          //����ȭ��
        set_skill("force", 300);         //�����ڹ�
        set_skill("dodge", 300);         //�����Ṧ
        set_skill("parry", 300);         //�����м�
        set_skill("literate", 250);      //����д��
        set_skill("sword", 331);         //��������
        set_skill("feiyu-jian", 330);    //���㽣��
        set_skill("youyu-quan", 300);     //����ȭ
        set_skill("fish-steps", 300);    //���β���
        set_skill("tianlongforce", 300); //������
        set_skill("tao",350);            //��ѧ�ķ�

        map_skill("cuff", "youyu-quan");
		map_skill("force", "tianlongforce");
		map_skill("sword", "feiyu-jian");
		map_skill("dodge", "fish-steps");

		prepare_skill("sword", "feiyu-jian");

		create_family("������", 2, "����");

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: recover_ob :)
        }) );

        add_money("silver", 10);

        carry_object("/d/feiyu/obj/chouduan")->wear();
        carry_object("/d/feiyu/obj/changjian")->wield();
}

void attempt_apprentice(object me)
{
        if ((string)me->query("family/family_name") != "������") {
                command("say " + RANK_D->query_respect(me)+"��Ȼ������ʦָ�����ֺ������Ϊʦ�أ�");
                return;
         }

        if ( (int)me->query("combat_exp")<400000 ) {
                command("say " + RANK_D->query_respect(me)+"�ƺ����δ������ȥ������ĥ��ĥ�������ɣ�");
                return;
        }
        if ((int)me->query_skill("feiyu-jian", 1) < 120) {
                command("say ���ڷ��㽣���ϵ���Ϊδ����"); 
                command("say " + RANK_D->query_respect(me) + 
                        "�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                return;
         }
        if ( (int)me->query_skill("literate",1) < 100 ) {
                command("say �ҿ�" + RANK_D->query_respect(me) + "�Ķ���ʶ�ֻ�ûѧ���Ұɡ�");
                return;
        }
        if (((int)me->query_skill("force",1) < 80) || ((int)me->query_skill("tianlongforce",1) < 80)) {
                command("say �ҿ�" + RANK_D->query_respect(me) + "�Ľ�������񹦻�ûѧ���Ұɡ�");
                return;
        }
        if ((int)me->query("shen") < 100000) {
                command("say �ҷ��������������������ɣ��Ե��ӵ���Ҫ���ϸ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +"�Ƿ����ò�����");
                return;
        } 
 

        command("say �ðɣ��Ҿ���������ͽ�ܰɡ�");
        command("say ���������书�������Ҫ�úõ�ѧѽ!");
        command("recruit " + me->query("id"));
}

void recover_ob()
{
        command("yun recover");
        return;
}
