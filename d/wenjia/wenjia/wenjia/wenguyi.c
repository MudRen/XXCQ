// NPC: wenguyi.c �¹���
// Created by Zeus 1999.7.1
// Modified by Zeus 1999.7.1
// 
// �¼ҵ��ռ�ʦ��

inherit F_MASTER;
inherit F_DEALER;

#include <ansi.h>

void init();
void recover_ob();
int give_task(string);

void create()
{
        set_name("�¹���", ({ "wen guyi" , "wen"}) );
        set("gender", "����" );
        set("age", 38);
        set("per", 20);
        set("long",
                "��λ���ʱ���������һ�ź���,���������ֺ���ר�ܲض��Ĵ��ֺŵĸ����ˡ�\n");
        set("attitude", "friendly");

        set("qi", 5000);
        set("max_qi", 5000);
        set("jingli", 5000);
        set("max_jingli", 5000);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 200);

        set("combat_exp", 10000000);

        set_skill("lphand", 250);    //ʩ���ַ�
        set_skill("force", 250);     //�����ڹ�
        set_skill("dodge", 250);     //�����Ṧ
        set_skill("parry", 250);     //�����м�
        set_skill("poisonk", 250);   //��ҩ֪ʶ
        set_skill("duzun", 300);     //Ω������
        set_skill("zhixin", 250);    //�¹�֪��
        set_skill("qianli", 250);    //����ǧ��
        set_skill("duzi-du", 250);   //���ֶ�
        set_skill("shengdu", 250);   //����
        set_skill("bupangguan", 250);//���ֲ��Թ�
        set_skill("literate", 250);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzun");
        map_skill("parry", "duzun");

        prepare_skill("lphand", "duzun");

        create_family("���ֺ��¼�", 2, "����");

        setup();

        add_money("gold", 10);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.weiwo" :),
                (: recover_ob :)
        }) );

	carry_object(__DIR__"obj/chouduan")->wear();
}

void attempt_apprentice(object me)
{
        me = this_player();

        if (((me->query("combat_exp"))>30000) && (!(string)me->query("family/family_name") 
             || (string)me->query("family/family_name") != "���ֺ��¼�") ) {
                command("say " + RANK_D->query_respect(me)+"��Ȼ����ʦָ�����ֺα������¼ҡ�");
                return;
        }
        if ( me->query("shen") < 0) {
                command("say �����¼���Ȼ���������㲻���������ɣ��¼ҵ��Ӷ��ǲ���Ϊ�������ġ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +
                        "�Ƿ����ò�����");
                return;
        }
        if ( me->query_skill("lphand", 1) < 150) {
                command("say �������ֺ��¼���ʹ���ģ�ʩ���ַ���������˵��������һ����Ҫ��"); 
                command("say " + RANK_D->query_respect(me) + 
                        "�Ƿ�Ӧ����ʩ���ַ��϶��µ㹦��");
                return;
        }
        if ( me->query_skill("zhixin", 1) < 150) {
                command("say �������ֺ��¼���Ȼ��ʹ���ģ���ʹ��ʱ��Ҫ�ڹ��Ѷ�ҩ�ų�ȥ��"); 
                command("say " + RANK_D->query_respect(me) + 
                        "�Ƿ�Ӧ�����ڹ��ķ��϶��µ㹦��");
                return;
        }

        if ( (string)me->query("family/master_id") != "wen wen" ) {
                command("angry " + me->query("id"));
                command("say ��Ҫ�Ȱ����������¼Ҹ��ֲ��������ҡ�"); 
                command("grin " + me->query("id"));
                command("say ��ѧ�¼Ҿ�����Ω�Ҷ���û����ô���ס�"); 
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + me->query("id"));
        command("chat* nod");
        command("chat �����¼��ֶ���һ����"+me->query("id")+"һ���ĸ����ˡ�");
}

void recover_ob()
{
        command("yun recover");
        return;
}
