// NPC: wenwen.c �¼ҵ��������ӡ��߼�ʦ��  ����
// Created by Zeus 1999.6.9
// Modified by Zeus 1999.7.31
// 
// ԭ������!  �����书--����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string* medrooms = ({
        "/d/wenjia/caodi",
        "/d/wenjia/dayuan",
        "/d/wenjia/houyuan",
        "/d/wenjia/huoroad1",
        "/d/wenjia/huoroad2",
        "/d/wenjia/huoroad3",
        "/d/wenjia/huoroad4",
        "/d/wenjia/huoroad5",
        "/d/wenjia/huoroad6",
        "/d/wenjia/huoroad7",
        "/d/wenjia/huoroad8",
        "/d/wenjia/shulin1",
        "/d/wenjia/shulin2",
        "/d/wenjia/shanlu1",
        "/d/wenjia/shanlu2",
        "/d/wenjia/shanlu3",
        "/d/wenjia/shanlu4",
        "/d/wenjia/siroad1",
        "/d/wenjia/siroad2",
        "/d/wenjia/siroad3",
        "/d/wenjia/siroad4",
        "/d/wenjia/siroad5",
        "/d/wenjia/siroad6",
        "/d/wenjia/yaotian1",
        "/d/wenjia/yaotian2",
        "/d/wenjia/yaotian3",
        "/d/wenjia/yaotian4",
        "/d/wenjia/yaotian5",
        "/d/wenjia/yaotian6",
        "/d/wenjia/yaotian7",
});

string* medsources = ({
        "chihuohe",
        "mushugen",
        "fanmubie",
        "chiaisu", 
        "duanchangcao", 
        "hedinghong", 
        "kongquedan", 
});

string* chinesemedsources = ({
        "���Ы",
        "ľ���",
        "��ľ��",
        "�ఫ��",
        "�ϳ���",
        "�׶���",
        "��ȸ��",
});

int give_yaofang();
void recover_ob();

void create()
{
        set_name("����", ({ "wen wen","wen"}) );
        set("nickname", RED"һ����ɱ��һЦף��"NOR );
        set("gender", "����" );
        set("age", 50);
        set("per", 25);
        set("long",
                "�����ֽ������ˣ���С�ֺŵĸ��֣�����İ�����ʦ�ܡ�\n���Ӳ��ߣ���΢ͺ���˺�˹�ģ������ʱ��");
        set("attitude", "friendly");

        set("qi", 2500);
        set("max_qi", 2500);
        set("jingli", 3000);
        set("max_jingli", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);

        set("combat_exp", 8500000);

        set_skill("lphand", 150);    //ʩ���ַ�
        set_skill("force", 150);     //�����ڹ�
        set_skill("dodge", 150);     //�����Ṧ
        set_skill("parry", 150);     //�����м�
        set_skill("zhixin", 150);    //�¹�֪��
        set_skill("poisonk", 150);   //��ҩ֪ʶ
        set_skill("qianli", 150);    //����ǧ��
        set_skill("shengdu", 200);   //����
        set_skill("literate", 150);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "shengdu");
        map_skill("parry", "shengdu");

        prepare_skill("lphand", "shengdu");

        create_family("���ֺ��¼�", 3, "����");

        set("inquiry", ([
                "ҩ��" : (: give_yaofang :),
                "yaofang" : (: give_yaofang :),
        ]) );

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.wusheng" :),
                (: recover_ob :)
        }) );

        add_money("gold", 5);

        carry_object("/d/wenjia/obj/gubo");
        carry_object("/d/wenjia/obj/chouduan")->wear();
}

void attempt_apprentice(object me)
{
        mapping myfam;
        me = this_player();

        myfam = (mapping)me->query("family");

        if ( me->query("combat_exp")<500000 ) {
                command("say ȥ�����϶�ĥ��ĥ���ɡ�");
                return;
        }
        if ( me->query("shen") < 0) {
                command("say �����¼���Ȼ���������㲻���������ɣ��¼ҵ��Ӷ��ǲ���Ϊ�������ġ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +
                        "�Ƿ����ò�����");
                return;
        }
        if ( me->query_skill("lphand", 1) < 110) {
                command("say �������ֺ��¼���ʹ���ģ�ʩ���ַ���������˵��������һ����Ҫ��"); 
                command("say " + RANK_D->query_respect(me) + 
                        "�Ƿ�Ӧ����ʩ���ַ��϶��µ㹦��");
                return;
        }
        if ( me->query_skill("zhixin", 1) < 110) {
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

int give_yaofang()
{
        object me,obj;
        string *obj1;
        int i,med1,med2,med3,medroom1,medroom2,medroom3 ;

        me=this_player();

        if ( me->query_temp("taskxiao/given") )
	{
                command("nod " + me->query("id"));
                message_vision("���Ķ�$N˵��������������ҩ������������ȥ���Ǽ���ҩ�İ�!��\n",me);
                obj=new("/d/wenjia/task_xiao/obj/yaofang");
                med1=random(sizeof(chinesemedsources));
                med2=random(sizeof(chinesemedsources));
                med3=random(sizeof(chinesemedsources));
                medroom1=random(sizeof(medrooms));
                medroom2=random(sizeof(medrooms));
                medroom3=random(sizeof(medrooms));
                obj->set("long","��ζ��ҩ��Ҫ���⼸��ҩ����ɣ�"YEL+chinesemedsources[med1]
                         +"��"+chinesemedsources[med2]+
                          "��"+chinesemedsources[med3]+
                          NOR"��\n");
                obj->move(me);
                obj=new("/d/wenjia/task_xiao/obj/yaochu");
                obj->move(me);
                obj=new("/d/wenjia/task_xiao/obj/yaolou");
                obj->move(me);
                message_vision("������˵���������ҩ����ר��������ҩ��!���š���\n",me);
                me->set_temp("taskxiao/med1",med1);
                me->set_temp("taskxiao/med2",med2);
                me->set_temp("taskxiao/med3",med3);
                me->set_temp("taskxiao/medroom1",medroom1);
                me->set_temp("taskxiao/medroom2",medroom2);
                me->set_temp("taskxiao/medroom3",medroom3);
                return 1;
        }        

        message_vision("���Ķ�$N˵������������ҩ����ʲô?��\n",me);
        return 1;

}

int accept_object(object who, object ob)
{
        if ( ob->query("name")=="ҩ��")
		{
		         who->set_temp("taskxiao/yaochugiven",1);
                 message_vision("���Ķ�$N˵�������ҩ�����Ѿ��յ��ˣ���\n",who);
				 return 1;
        }
        if ( ob->query("name")=="ҩ��")
		{
		         who->set_temp("taskxiao/yaofanggiven",1);
                 message_vision("���Ķ�$N˵��������ҩ�����Ѿ��յ��ˣ���\n",who);
				 return 1;
        }
}