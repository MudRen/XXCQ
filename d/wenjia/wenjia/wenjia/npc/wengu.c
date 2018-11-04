// NPC: wengu.c
// Created by Zeus 1999.5.28
// Modified by Zeus 1999.7.11
// 
// 

inherit NPC;
#include <ansi.h>

void init();
void greeting(object);
int do_join(string arg);
int uplevel();
int ask_cloth();

void create()
{
        set_name("�¹�", ({ "wen gu" , "wen"}) );
        set("nickname", HIC"�Ŷ��ܼ�"NOR );
        set("gender", "����" );
        set("age", 60);
        set("long",
                "�¹����¼ҵĹܼң����������¼ҵ�һ���ճ����\n"+
                "����ͷ���ڰ���䣬һ���ǳ����������ӡ�\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 500);
        set("max_jingli", 500);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 5);

        set("combat_exp", 10000);

        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 200);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 20);

        create_family("���ֺ��¼�", 6, "����");

        set("inquiry", ([
                "����" : (: do_join :),
                "����" : (: uplevel :),
                "����" : (: ask_cloth :),
        ]) );

        setup();

        add_money("silver", 50);
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

        if (!ob->query("wentask/reg")) {
                 say("�¹�ͣ�����еĻ˵��������λ" + RANK_D->query_respect(ob)
                 + "����������¼ҵ�����ɣ��������ǰ�(ask wen about ����)����\n");
        }
        switch (random(2))
        {
                 case 0:
                 say("�¹�˵�������¼ҵ��ӿ������������칫�÷�װ(ask wen about ����)����\n");
                 break;
                 case 1:
                 say("�¹�˵����������һ�����������񻹿�������(ask wen about ����)��!��\n");
                 break;
        }        
}

int do_join(string arg)
{
        object me;

        me=this_player();

        if (!(string)me->query("family") || (string)me->query("family/family_name") != "���ֺ��¼�") {
                message_vision("�¹źܿ����ض�$N˵�����㲻�������¼ҵ��ˣ���θ������Ĵ��?\n��",me);
                return 1;
        }

        if (me->query("wentask/reg")) {
                command("angry "+me->query("id"));
                message_vision("�¹Ŷ�$N˵�����㲻���Ѿ��μ����¼ҹ�������ô������?��\n",me);
                return 1;
        }

        me->set("wentask/reg",1);
        me->set("wentask/done",1);
        me->set("wentask/dafirst",1);
        me->set("title",RED"�¼ҵͼ��Ҷ�"NOR);
        command("smile " + me->query("id"));
        message_vision("�¹Ŷ�$N˵�������úøɰɣ�������Щ��ͷ���Ѿ����ˣ��¼ҾͿ�������Щ����!��\n",me);

        return 1;
}

int uplevel()
{
        object me;
        int donenum;

        me=this_player();
        donenum=(int)me->query("wentask/done");

        if ( donenum<150 ){
                me->set("title",RED"�¼Ҹ߼��Ҷ�"NOR);
                message_vision("�¹Ŷ�$N˵��������!�ӽ��쿪ʼ����Ǹ߼��Ҷ��ˡ���\n",me);
                return 1;
        } else if ( donenum<300 ) {
                me->set("title",GRN"�¼ҼҶ�СͷĿ"NOR);
                message_vision("�¹Ŷ�$N˵��������!�ӽ��쿪ʼ����ǼҶ�СͷĿ�ˡ���\n",me);
                return 1;
        } else if ( donenum<500 ) {
                me->set("title",YEL"�¼ҼҶ���ͷĿ"NOR);
                message_vision("�¹Ŷ�$N˵��������!�ӽ��쿪ʼ����ǼҶ���ͷĿ�ˡ���\n",me);
                return 1;
        } else if ( donenum<1000 ) {
                me->set("title",BLU"�¼Ҹ��ܼ�"NOR);
                message_vision("�¹Ŷ�$N˵��������!�ӽ��쿪ʼ����������¼ҵĸ��ܼ��ˡ���\n",me);
                return 1;
        } else if ( donenum<1500 ) {
                me->set("title",MAG"�¼Ҹ�����"NOR);
                message_vision("�¹Ŷ�$N˵��������!�ӽ��쿪ʼ����������¼ҵĸ������ˡ���\n",me);
                return 1;
        } else {
                me->set("title",CYN"�¼ҳ���"NOR);
                message_vision("�¹Ŷ�$N˵��������!�ӽ��쿪ʼ����������¼ҳ����ˡ���\n",me);
                return 1;
        }
        message_vision("�¹Ŷ�$N�����飬˵����������ô���ˣ����ǽ�̤ʵ�ص�������ɡ���\n",me);
        return 1;
}

int ask_cloth()
{
        int mygener;
        object me,ob;

        me=this_player();
        
        mygener=me->query("family/generation");

        if ( !(string)me->query("family") || (string)me->query("family/family_name") != "���ֺ��¼�" ) {
                message_vision("�¹źܿ����ض�$N˵�����㲻�������¼ҵ��ˣ���ô������Ҫ�����ˡ���\n",me);
                return 1;
        }

        switch (mygener)
        {
                case 7:{
                ob=new("/d/wenjia/obj/yelduanda");
                ob->move(me);
                message_vision("�¹������Ĺ����﷭����һ���·�����\n",me);
                message_vision("�¹Ŷ�$N˵�������ţ�����·�������ķ��Ρ���\n",me);
                return 1;
                }
                case 6:{
                ob=new("/d/wenjia/obj/redduanda");
                ob->move(me);
                message_vision("�¹������Ĺ����﷭����һ���·�����\n",me);
                message_vision("�¹Ŷ�$N˵�������ţ�����·�������ķ��Ρ���\n",me);
                return 1;
                }
                case 5:{
                ob=new("/d/wenjia/obj/grnduanda");
                ob->move(me);
                message_vision("�¹������Ĺ����﷭����һ���·�����\n",me);
                message_vision("�¹Ŷ�$N˵�������ţ�����·�������ķ��Ρ���\n",me);
                return 1;
                }
                case 4:{
                ob=new("/d/wenjia/obj/yelduanda");
                ob->move(me);
                message_vision("�¹������Ĺ����﷭����һ���·�����\n",me);
                message_vision("�¹Ŷ�$N˵�������ţ�����·�������ķ��Ρ���\n",me);
                return 1;
                }
                case 3:{
                ob=new("/d/wenjia/obj/chouduan");
                ob->move(me);
                message_vision("�¹������Ĺ����﷭����һ���·�����\n",me);
                message_vision("�¹Ŷ�$N˵�������ţ�����·�������ķ��Ρ���\n",me);
                return 1;
                }
       }
       return 1;
}                