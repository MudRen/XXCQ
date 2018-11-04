// NPC: chuzi.c
// Created by Zeus 1999.3.27
// Modified by M.A.D. 1999.7.21
// 
// 

inherit NPC;

void greeting(object);
void init();
void serve_tang(object);
void delete_served();

void create()
{
        set_name("����", ({ "chuzi"}) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long",
                "�������������ĳ�ʦ������ȥ�ְ����ֵģ�һ����������\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("rank_info/respect", "��ʦ");

	create_family("������", 5, "����");

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

	say("���ӿ������˽�����ͣ�����еĻ˵��������λ" + RANK_D->query_respect(ob)
	     + "��Ҫʲô���������������֡���\n");
}


void serve_tea(object who)
{
        object obn;
        object room;

        if( !who || environment(who) != environment() ) return;

        if( !objectp(room = environment()) ) return;

        obn = new("/d/feiyu/obj/tang");
        obn->move(room);
        message_vision("���Ӷ���һ������˵�����������á���\n",who);

        switch( random(2) )
        {
        case 0:
                obn = new("/d/feiyu/obj/kaoya");
                obn->move(room);
                message_vision("���ӽ�һ���ճ�¯�Ŀ�Ѽ�������ϡ�\n", who);
		
                break;
       	case 1: 
                obn = new("/d/feiyu/obj/ruzhu");
                obn->move(room);
                message_vision("���ӽ�һ�������������\n", who);
	        	
        	break;
	}       	
	
        return;
}
