// NPC: wenxiaobian.c �¼ҵ��������ӡ�����ʦ��  ��С��
// Created by Zeus 1999.5.28
// Modified by Zeus 1999.7.10
// 
// ԭ������!  �����书--���ֲ��Թ�

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void recover_ob();

void create()
{
        set_name("��С��", ({ "wen xiaobian","wen"}) );
        set("nickname", MAG"���ֲ��Թ�"NOR );
        set("gender", "����" );
        set("age", 30);
        set("per", 10);
        set("long",
                "��С���ǡ���������������������������\n");
        set("attitude", "friendly");

        set("qi", 1000);
        set("max_qi", 1000);
        set("jingli", 800);
        set("max_jingli", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);

        set("combat_exp", 500000);

        set_skill("lphand", 80);    //ʩ���ַ�
        set_skill("force", 80);     //�����ڹ�
        set_skill("dodge", 80);     //�����Ṧ
        set_skill("parry", 80);     //�����м�
        set_skill("poisonk", 60);   //��ҩ֪ʶ
        set_skill("zhixin", 80);    //�¹�֪��
        set_skill("qianli", 80);    //����ǧ��
        set_skill("bupangguan", 150); //���ֲ��Թ�
        set_skill("literate", 60);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "bupangguan");
        map_skill("parry", "bupangguan");

        prepare_skill("lphand", "bupangguan");

        create_family("���ֺ��¼�", 6, "����");

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: recover_ob :)
        }) );

        add_money("silver", 10);

        carry_object("/d/wenjia/obj/redduanda")->wear();
}

void attempt_apprentice(object me)
{
        if ( (int)me->query("combat_exp")>5000 && (string)me->query("family/family_name") != "���ֺ��¼�") {
                command("say " + RANK_D->query_respect(me)+"��Ȼ����ʦָ�����ֺα������¼ҡ�");
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
