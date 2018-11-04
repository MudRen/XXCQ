// NPC: wenchifan.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.7.11
// 
// 

inherit NPC;

void greeting(object);
void init();
void serve_tea(object);
void delete_served();

void create()
{
        set_name("�³Է�", ({ "chifan", "wen chifan"}) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long",
                "�³Է����¼������������ĳ�ʦ������ȥ���ֵģ�һ����������\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("rank_info/respect", "��ʦ");

	create_family("���ֺ��¼�", 5, "����");

        setup();

        add_money("silver", 10);
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

	say("�³Է��������˽�����ͣ�����еĻ˵��������λ" + RANK_D->query_respect(ob)
	     + "��Ҫʲô���������������֡���\n");
}


void serve_tea(object who)
{
        object obt, obc, obn;
        object room;

        if( !who || environment(who) != environment() ) return;

        if( !objectp(room = environment()) ) return;

        obn = new("/d/wenjia/obj/xingshencha");
        obn->move(room);
        message_vision("�³Է�����һ������裬˵�������������Ʒ����\n",who);

        switch( random(2) )
        {
        case 0:
                obn = new("/d/wenjia/obj/baiqieji");
                obn->move(room);
                message_vision("�³Է���һ���ճ�¯�İ��м��������ϡ�\n", who);
		
                break;
       	case 1: 
                obn = new("/d/wenjia/obj/ruzhu");
                obn->move(room);
                message_vision("�³Է���һ�������������\n", who);
	        	
        	break;
	}       	
	
        return;
}
