// nanpu.c

inherit NPC;
#include <ansi.h>

int serve_me(object who);
void create()
{
        set_name("����", ({ "nan pu", "pu" }));
        set("gender", "����");
        set("age", 25);

        set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
         set("food",5);
        setup();

        set("inquiry", ([
                "�Է�" : (: serve_me :),
                "�ò�" : (: serve_me :),
	]) );
        add_money("silver",3);
        carry_object("/clone/misc/cloth")->wear();
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

	say("����Ц���е�˵��������λ" + RANK_D->query_respect(ob)
	     + "��Ҫ�Ե�ʲô��������֪����һ������\n");
}


int serve_me(object who)
{
        object ob;
        object room;

        if( !who || environment(who) != environment() ) return 0;

        if( !objectp(room = environment()) ) return 0;

          if (query("food")>0) {
        ob = new("/d/wenzhai/obj/longjing");
        ob->move(room);
        message_vision("���Ͷ���һ�������衣\n",who);

        ob = new("/d/wenzhai/obj/niqiu");
        ob->move(room);
        message_vision("���ͽ�һ���ճ����ĸɱ������������ϡ�\n", who);
       add("food",-1);
       }
       else
		message_vision("����������Ǹ��Ӧ��: �ˣ��ԵĺȵĶ�û�ˡ�\n",who);
		
        return 1;
}
