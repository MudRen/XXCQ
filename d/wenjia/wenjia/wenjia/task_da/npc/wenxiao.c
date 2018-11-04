// NPC: wenxiao.c ��Ц �Դ����� ������ȡ���ֺ������
// Created by Zeus 1999.5.28
// Modified by Zeus 1999.5.28
// 
// 

inherit NPC;
#include <ansi.h>
void recover_ob();

void create()
{
        set_name("��Ц", ({ "wen xiao"}) );
        set("nickname", GRN"��Ц����" + HIM"֮Ц��Ϻ"NOR );
        set("gender", "����" );
        set("age", 30);
        set("long",
                "��Цר�š�����������������������\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 500);
        set("max_jingli", 500);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 5);

        set("combat_exp", 10000);

        set_skill("lphand", 40);    //ʩ���ַ�
        set_skill("force", 40);     //�����ڹ�
        set_skill("dodge", 40);     //�����Ṧ
        set_skill("parry", 40);     //�����м�
        set_skill("zhixin", 50);    //�¹�֪��
        set_skill("qianli", 50);    //����ǧ��
        set_skill("bupangguan", 50);//���ֲ��Թ�
        set_skill("literate", 60);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "bupangguan");
        map_skill("parry", "bupangguan");

	prepare_skill("lphand", "bupangguan");

	create_family("���ֺ��¼�", 6, "����");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: recover_ob :)
        }) );

        setup();

        add_money("silver", 5);

	carry_object("/d/wenjia/obj/redduanda")->wear();
}


void recover_ob()
{
        command("yun recover");
        return;
}

int accept_object(object who,object ob)
{
        object room;
        
        if ( who->query_temp("taskda/done") ) {
                command("? "+who->query("id"));
                message_vision("��Ц�ɻ�ض�$N˵�����㲻���Ѿ����˶�ҩ����,��ô��������?��\n",who);
                return 1;
        }

        if ( (string)ob->query("name","��֪����ҩ") && who->query_temp("taskda/given")
             && who->query_temp("taskda/p_given")) {
                command("nod");
                command("thank "+who->query("id"));
                message_vision("��Ц��$N˵�����յ��ˣ��������ȥ����ͷ�������칦��!\n",who);
                who->set_temp("taskda/done",1);
                destruct(ob);
                return 1;
        } else        	
        {
                command("say ����������ʲô?");
                return 0;
        }

}
