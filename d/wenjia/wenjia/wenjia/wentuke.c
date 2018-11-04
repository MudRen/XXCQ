// NPC: wentuke.c �¼ҵ�������ӡ�����ʦ��  ���¿�
// Created by Zeus 1999.6.9
// Modified by Zeus 1999.7.1
// 
// ԭ������!  �����书--���ֶ�

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void recover_ob();

void create()
{
        set_name("���¿�", ({ "wen tuke","wen"}) );
        set("nickname", HIC"���ֶ�"NOR );
        set("gender", "����" );
        set("age", 30);
        set("per", 10);
        set("attitude", "friendly");

        set("qi", 1300);
        set("max_qi", 1300);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);

        set("combat_exp", 3500000);

        set_skill("lphand", 120);    //ʩ���ַ�
        set_skill("force", 120);     //�����ڹ�
        set_skill("dodge", 120);     //�����Ṧ
        set_skill("parry", 120);     //�����м�
        set_skill("zhixin", 120);    //�¹�֪��
        set_skill("poisonk", 100);   //��ҩ֪ʶ
        set_skill("qianli", 120);    //����ǧ��
        set_skill("duzi-du", 200);   //���ֶ�
        set_skill("literate", 100);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzi-du");
        map_skill("parry", "duzi-du");

        prepare_skill("lphand", "duzi-du");

        create_family("���ֺ��¼�", 5, "����");

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: recover_ob :)
        }) );

        add_money("silver", 10);

        carry_object("/d/wenjia/obj/grnduanda")->wear();
}

void attempt_apprentice(object me)
{
        mapping myfam;
        me = this_player();

        myfam = (mapping)me->query("family");

        if ( me->query("combat_exp")<100000 ) {
                command("say ȥ�����϶�ĥ��ĥ���ɡ�");
                return;
        }
        if ((int)me->query("shen") < 0) {
                command("say �����¼���Ȼ���������㲻���������ɣ��¼ҵ��Ӷ��ǲ���Ϊ�������ġ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +
                        "�Ƿ����ò�����");
                return;
        }
        if ((int)me->query_skill("lphand", 1) < 50) {
                command("say �������ֺ��¼���ʹ���ģ�ʩ���ַ���������˵��������һ����Ҫ��"); 
                command("say " + RANK_D->query_respect(me) + 
                        "�Ƿ�Ӧ����ʩ���ַ��϶��µ㹦��");
                return;
        }
        if ((int)me->query_skill("zhixin", 1) < 50) {
                command("say �������ֺ��¼���Ȼ��ʹ���ģ���ʹ��ʱ��Ҫ�ڹ��Ѷ�ҩ�ų�ȥ��"); 
                command("say " + RANK_D->query_respect(me) + 
                        "�Ƿ�Ӧ�����ڹ��ķ��϶��µ㹦��");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("say �úõ�ѧ��!");
        command("recruit " + me->query("id"));
}

void recover_ob()
{
        command("yun recover");
        return;
}
