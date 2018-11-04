// NPC: wenku.c �¿� �Դ����� ������ȡ���ֺ������
// Created by Zeus 1999.5.28
// Modified by Zeus 1999.6.4
// 
// 

inherit NPC;
#include <ansi.h>
void recover_ob();
void init();
int get_duyao(string arg);

void create()
{
        set_name("�¿�", ({ "wen ku"}) );
        set("nickname", GRN"��Ц����" + HIM"֮�޴�Ϻ"NOR );
        set("gender", "����" );
        set("age", 30);
        set("long",
                "�¿�ר�š�����������������������\n");
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
void init()
{
        add_action("get_duyao","��");
        add_action("get_duyao","take");
}

void recover_ob()
{
        command("yun recover");
        return;
}

int get_duyao(string arg)
{
        object me,ob;

        me=this_player();

        if (!arg || arg!="��ҩ" ) return notify_fail("��Ҫ��ʲô?\n");

        if ( me->query_temp("taskda/p_given") ) {
                command("? "+me->query("id"));
                message_vision("�¿޶�$N˵�����������Ѿ������㶾ҩ����?����ô��������Ҫҩ!��\n",me);
                return 1;
        }
                
        if ( !(me->query("wentask/reg"))) {
                if (!(string)me->query("family") || (string)me->query("family/family_name") != "���ֺ��¼�") {
                        message_vision("�¿޾��ȵض�$N˵�����㲻�������¼ҵ��ˣ���ô������Ҫ��ҩ?��\n",me);
                return 1;
                } {
                message_vision("�¿޶�$N˵������Ҫ��������?���ȵ��¹�����Ǽǣ��ڵ�ͷ������������!��\n",me);
                return 1;}                
        }

        if ( !(me->query_temp("taskda/given")) ) {
                command("? "+me->query("id"));
                message_vision("�¿޶�$N˵��������û����ͷ����������ô����������Ҫ��ҩ?��\n",me);
                return 1;
        }

        if ( me->query_temp("taskda/given") ) {
                command("nod");
                message_vision("�¿޶�$N˵��������Ȼ���Ѿ���ͷ���������������ҩ�͸�����!��\n",me);
                ob=new(__DIR__"obj/unknownp");
                ob->move(me);
                me->set_temp("taskda/p_given",1);
                if ( me->query("wentask/dafirst") ) {
                        message_vision("�¿�����һ�£�˵����$N�����ǵ�һ���Ͱ�?"+RED"�Ǹ�������һ���Թ�������Щ����������Թ���!�߳������Ҫ��ס·��ѽ!��\n"NOR,me);
                        message_vision("�¿޸���$NһЩ������\n"NOR,me);
                        ob=new(__DIR__"obj/dashuzhi");
                        ob->move(me);
                        ob=new(__DIR__"obj/xiaoshuzhi");
                        ob->move(me);
                        ob=new(__DIR__"obj/dashucha");
                        ob->move(me);
                        ob=new(__DIR__"obj/xiaoshucha");
                        ob->move(me);
                        ob=new(__DIR__"obj/dashitou");
                        ob->move(me);
                        ob=new(__DIR__"obj/xiaoshitou");
                        ob->move(me);
                        ob=new(__DIR__"obj/dashuye");
                        ob->move(me);
                        ob=new(__DIR__"obj/xiaoshuye");
                        ob->move(me);
                }
                return 1;
        }
        return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 10000) 
	{
          command("whisper "+who->query("id")+" ��Ȼ��ô�����������㣬���Թ���˳����se s e ne sw n w nw���ɱ����ͷ����");
          return 1;
	}

        if (ob->query("money_id") && ob->value() >= 500) 
	{
          command("nod "+who->query("id"));
          command("whisper "+who->query("id")+" �����㣬�߶Է��������һ���ˡ�");
          return 1;
	}

        if (ob->query("money_id") && ob->value() >= 300) 
	{
          command("nod "+who->query("id"));
          command("whisper "+who->query("id")+" �����㣬���Թ���˳��ʵ������8���������һ��λ�á�");
          return 1;
	}
	return 0;
}
