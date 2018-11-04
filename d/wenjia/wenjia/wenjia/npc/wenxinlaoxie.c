// NPC: wenxinlaoxie.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.7.30
// 
// 

inherit NPC;

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

#include <ansi.h>

void init();
void greeting(object);
void recover_ob();
int give_task();

void create()
{
        set_name("��������", ({ "wenxin laoxie" , "wen"}) );
        set("gender", "����" );
        set("age", 55);
        set("per", 5);
        set("long",
                "����˵ĳ���ʮ�����,����ͷ����һֻ����,����ȴ�����ֺ�\n"+
                "�еķֺ�֮һС�ֺŵ��ϴ�,������,��׼û�ù��ӳԡ�\n");
        set("attitude", "friendly");

        set("qi", 2000);
        set("max_qi", 2000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 200);

        set("combat_exp", 2500000);

        set_skill("lphand", 180);    //ʩ���ַ�
        set_skill("force", 180);     //�����ڹ�
        set_skill("dodge", 180);     //�����Ṧ
        set_skill("parry", 180);     //�����м�
        set_skill("duzun", 180);     //Ω������
        set_skill("zhixin", 180);    //�¹�֪��
        set_skill("qianli", 180);    //����ǧ��
        set_skill("literate", 160);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzun");
        map_skill("parry", "duzun");

        prepare_skill("lphand", "duzun");
  
        create_family("���ֺ��¼�", 3, "����");

        set("inquiry", ([
                "��ҩ" : (: give_task :),
                "����" : (: give_task :),
                "job" : (: give_task :),
        ]) );

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.weiwo" :),
		(: recover_ob :)
        }) );

        add_money("gold", 10);

        carry_object("/d/wenjia/obj/chouduan")->wear();
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                 remove_call_out("greeting");
                 call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        if (ob->query("wentask/reg") && !(ob->query_temp("taskxiao/given")) ) {
                 say("������������˵��������λ" + RANK_D->query_respect(ob)
                 + "����ɴ��ֺŵ�����ɣ�����Ҫ����ɡ���\n");
        }
        else {
                 say("��������˵�������¼ҵ��ӵľ�����Ω�Ҷ���(duzun)��ѧ������书�ư�������û������ġ���\n");
        }
}

void recover_ob()
{
        command("yun recover");
        return;
}

int give_task()
{
        object me,givesilver;
        int givepot,giveexp,i,tasktime;

        me=this_player();

        if ( me->query_temp("taskxiao/given") )
		{
                command("angry " + me->query("id"));
                message_vision("����������$N˵�������������񲻸Ͽ�ȥ����վ�������ʲô!��\n",me);
                return 1;
        }        

        if ( !me->query("wentask/reg") )
        {
                if (!(string)me->query("family") || (string)me->query("family/family_name") != "���ֺ��¼�") 
				{
                        message_vision("���������ܿ����ض�$N˵�����㲻�������¼ҵ��ˣ���θ������Ĵ��?��\n",me);
                        return 1;
                } else
         	    {
                        message_vision("����������$N˵�������ȵ��¹�����Ǽǣ�����������������!��\n",me);
                        return 1;
				}                
		}
                
        if ( me->query_temp("taskxiao/given") )
		{
                command("angry " + me->query("id"));
                message_vision("����������$N˵�����㲻���Ѿ�������������?���Ͽ�ȥ����վ�������ʲô!��\n",me);
                return 1;
        }

        me->set_temp("taskxiao/given",1);
        message_vision("����������$N˵������Ȼ����Ϊ���ų�������ô��ȥ��������Ҫһ��ҩ��������ҩ��(yaofang)ȥ��ԭ���ϰ�!��\n",me);

        return 1;
}

int accept_object(object who, object ob)
{
        object *inv,givesilver;
        int amount,i,givepot,giveexp,tasktime,med1,med2,med3;

		if ( ob->query("name") != "ҩ¨" )
                 return notify_fail("��������˵��������������ʲô?��\n");

		if (!who->query_temp("taskxiao/yaofanggiven"))
        {
                message_vision("����������$N˵��������ȥ��ҩ��������������?��\n",who);
                return 1;
        }

		if (!who->query_temp("taskxiao/yaochugiven"))
        {
                message_vision("����������$N˵��������ȥ��ҩ��������������?��\n",who);
                return 1;
        }

        if ( !(who->query_temp("taskxiao/given")) )
		{
                command("angry " + who->query("id"));
                message_vision("����������$N˵������û����������ô��������!��\n",who);
                return 1;
        }

        inv = all_inventory(ob);
        med1=who->query_temp("taskxiao/med1");
        med2=who->query_temp("taskxiao/med2");
        med3=who->query_temp("taskxiao/med3");
		if( !sizeof(inv) )
                 return notify_fail("������û���κζ�����\n");

        for(i=0; i<sizeof(inv); i++)
		{
				if( inv[i]->query("name") == chinesemedsources[med1] ) amount++;
                if( inv[i]->query("name") == chinesemedsources[med2] ) amount++;
                if( inv[i]->query("name") == chinesemedsources[med3] ) amount++;
        }

        if (amount < 3 ){
                message_vision("������������ɫ��ø��ѿ��ˣ���$N˵����������Ϊ�¼ҵ��ӣ���Ϊ�¼ҳ���������͵��?��ȥ��ҩ��\n��",who);
				ob->move(who);
				return 1;
		}

		message_vision("������������ɫ����ƺ���Щ�ÿ�����$N˵��������Ϊ�¼ҳ�����Ӧ�õõ����͵ģ���\n",who);
        givepot=150+random(100);
        giveexp=250+random(200);
        who->add("wentask/done",1);
        tasktime=who->query("wentask/done");
        who->add("potential", givepot);
        who->add("combat_exp", giveexp);
        message_vision(HIY"��������������$N"+chinese_number(givepot)+"��Ǳ�ܺ�"+chinese_number(giveexp)+"�㾭�顣\n"NOR,who);
        for (i=1;i<2+random(10);i++) {
        givesilver=new("/clone/money/silver");
        givesilver->move(who);}
        message_vision(HIC"$N�Ѿ�Ϊ�¼�����"+chinese_number(tasktime)+"������\n"NOR,who);
        message_vision(HIC"������������$N�������ӡ�\n"NOR,who);
        who->delete_temp("taskxiao");
        return 1;
}


//��ʬ��
//�һ���
//�̲Ϲ�
//ʮ����
//û��ҩ
//�Դ�
//���Ы
//ľ���
//��ľ��
//�ఫ��
