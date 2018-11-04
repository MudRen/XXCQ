// NPC: wenliangyu.c ������
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.7.10
// 
// ���ֺŵ��ϴ�

inherit NPC;
inherit F_DEALER;

#include <ansi.h>

void init();
void greeting(object);
void recover_ob();
int give_task(string);
int ask_praise();
int ask_duzun();

void create()
{
        set_name("������", ({ "wen liangyu" , "wen"}) );
        set("gender", "����" );
        set("age", 38);
        set("per", 20);
        set("long",
                "��λ���ʱ���������һ�ź���,���������ֺ���ר�ܲض��Ĵ��ֺŵĸ����ˡ�\n");
        set("attitude", "friendly");

        set("qi", 2000);
        set("max_qi", 2000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 150);
        set("lphandbook_count", 1);

        set("combat_exp", 2500000);

        set_skill("lphand", 180);    //ʩ���ַ�
        set_skill("force", 180);     //�����ڹ�
        set_skill("dodge", 180);     //�����Ṧ
        set_skill("parry", 180);     //�����м�
        set_skill("duzun", 200);     //Ω������
        set_skill("zhixin", 180);    //�¹�֪��
        set_skill("qianli", 180);    //����ǧ��
        set_skill("poisonk", 180);   //��ҩ֪ʶ
        set_skill("duzi-du", 200);   //���ֶ�
        set_skill("shengdu", 200);   //����
        set_skill("bupangguan", 200);//���ֲ��Թ�
        set_skill("literate", 160);  //����д��

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzun");
        map_skill("parry", "duzun");

        prepare_skill("lphand", "duzun");

        create_family("���ֺ��¼�", 3, "����");

        set("inquiry", ([
                "����" : (: ask_praise :),
                "duzun" : (: ask_duzun :),
                "Ω�Ҷ���" : (: ask_duzun :),
        ]) );

        setup();

        add_money("gold", 10);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.weiwo" :),
                (: recover_ob :)
        }) );

        carry_object("/d/wenjia/obj/chouduan")->wear();
}

void init()
{
        object ob;

        add_action("give_task", "task");

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                 remove_call_out("greeting");
                 call_out("greeting", 1, ob);
        }
        
        if (is_fighting()){
                 remove_call_out("arrest");
                 call_out("arrest",1,ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        if (ob->query("wentask/reg") && !(ob->query_temp("taskda/given"))) {
                 say("�����񿪿�˵��������λ" + RANK_D->query_respect(ob)
                 + "����ɴ��ֺŵ�����ɣ�����Ҫ�����(task)����\n");
        }
        else {
                 say("������˵�������¼ҵ��ӵľ�����Ω�Ҷ���(duzun)��ѧ������书�ư�������û������ġ���\n");
        }
}

void recover_ob()
{
        command("yun recover");
        return;
}

int give_task(string arg)
{
        object me,givesilver;
        int givepot,giveexp,i,tasktime;

        me=this_player();

        message_vision("$N������ò����������ѯ�ʴ��ֺ��������!\n",me);

        if ( arg || arg == "ok" ) { //����������task ok����ô��ʾ����������
                if( me->query_temp("taskda/done") ) {
                        command("pat " + me->query("id"));
                        message_vision("�������$N˵������Ȼ���Ѿ�������񣬾͸��㽱�Ͱ�!��\n",me);
                        if ( me->query("wentask/dafirst")) {
                                message_vision(HIY"������ͦ���˵Ķ�$N˵������һ����������������ĳɼ���Ҫ�����ر���!��\n"NOR,me);
                                me->add("potential", 40+random(100));
                                me->add("combat_exp", 100+random(100));
                                givesilver=new("/clone/money/gold");
                                givesilver->move(me);
                                me->set("wentask/dafirst",0);
                        }
                        givepot=15+random(10);
                        giveexp=85+random(10);
                        me->add("wentask/done",1);
                        tasktime=me->query("wentask/done");
                        me->add("potential", givepot);
                        me->add("combat_exp", giveexp);
                        message_vision(HIY"����������$N"+chinese_number(givepot)+"��Ǳ�ܺ�"+chinese_number(giveexp)+"�㾭�顣\n"NOR,me);
                        for (i=1;i<2+random(4);i++) {
                        givesilver=new("/clone/money/silver");
                        givesilver->move(me);}
                        message_vision(HIC"$N�Ѿ�Ϊ�¼�����"+chinese_number(tasktime)+"������\n"NOR,me);
                        message_vision(HIC"���������$N�������ӡ�\n"NOR,me);
                        me->delete_temp("taskda/done");
                        me->delete_temp("taskda/given");
                        me->delete_temp("taskda/p_given");
                        return 1;
                }
                else if ( !(me->query_temp("taskda/given")) ) {
                        command("angry " + me->query("id"));
                        message_vision("�������$N˵������û����������ô��������!��\n",me);
                        return 1;
                }
                else if ( me->query_temp("taskda/given") ) {
                        command("angry " + me->query("id"));
                        message_vision("�������$N˵�������������񲻸Ͽ�ȥ����վ�������ʲô!��\n",me);
                        return 1;
                }
        }        

        if ( !(me->query("wentask/reg"))) {
                if (!(string)me->query("family") || (string)me->query("family/family_name") != "���ֺ��¼�") {
                        message_vision("������ܿ����ض�$N˵�����㲻�������¼ҵ��ˣ���θ������Ĵ��?��\n",me);
                return 1;
                } {
                message_vision("�������$N˵�������ȵ��¹�����Ǽǣ�����������������!��\n",me);
                return 1;}                
        }
                
        if ( me->query_temp("taskda/given") ) {
                command("angry " + me->query("id"));
                message_vision("�������$N˵�����㲻���Ѿ�������������?���Ͽ�ȥ����վ�������ʲô!��\n",me);
                return 1;
        }

        me->set_temp("taskda/given",1);
        message_vision("�������$N˵������Ȼ����Ϊ���ų�������ô�͵��¿�������һ����ҩ���͵���Ц�����!��\n",me);

        return 1;
}

int ask_praise()
{
       int worktime;
       object me,ob;

       me=this_player();

       worktime=me->query("wentask/done");

       if (worktime>400 ){
               message_vision("�������$N˵��������!��Ȼ������˾�����Ϊ�¼ҳ�����������Ӧ�õ�!��\n",me);
               if ( query("lphandbook_count") < 1 ){
                           message_vision("�������ֶ�$N˵�����������������ˣ��ؼ��Ѿ����������ˡ���\n",me);
                           return 1;
               }
               add("lphandbook_count", -1);
               ob=new("/d/wenjia/treasure/lphandbook");
               ob->move(me);
               message_vision("�������$N˵�����Ȿʩ���ַ����ؼ�ƪ�͸����ˣ���úõ�ѧ��!��\n",me);
               return 1;
       }
       message_vision("�������$N˵�����㻹δŬ�����¼ҳ�������ȥ�������!��\n",me);
       return 1;
}

int ask_duzun()
{
       object me;

       me=this_player();
       message_vision("�������$N˵�����ҿɲ��ܽ���Ω�Ҷ�����ѧ��Ҫȥ���¹���Ϊʦ����\n",me);
       return 1;
}