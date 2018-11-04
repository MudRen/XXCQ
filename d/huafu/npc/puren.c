
inherit NPC;

#include <ansi.h>
int serve_me(object who);
void create()
{
        set_name("����", ({ "pu ren", "pu" }));
        set("gender", "����");
        set("age", 25);

        set("combat_exp", 4000);
        set_skill("dodge", 20);
         set("serve",100);
        setup();

        set("inquiry", ([
                "ԭ��" : (: serve_me :),
	]) );
        add_money("silver",3);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

	
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        if( interactive(ob=this_player()) && ob->query_temp("killwei") ) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	say("����Ц���е�˵��������λ" + RANK_D->query_respect(ob)
	     + "��Ҫ��Ƶ�ԭ�ϣ���֪����һ������\n");
}


int serve_me(object who)
{
        object ob;
        object room;

       who=this_player();
        if( !who || environment(who) != environment() ) return 0;

        if( !objectp(room = environment(who)) ) return 0;
        if ((ob=present("gaoliang",who)) || (ob=present("mianfen",who)) || (ob=present("gaoliangfan",who)))
        {
               command("hmm");
               command("say ���Ѿ�����ԭ���ˣ���û�����ء�");
               return 1;
        }

          if (query("serve")>0) {
        ob = new("/d/huafu/obj/gaoliang");
        ob->move(who);
        message_vision("���˵ݸ�$Nһ��������\n",who);

        ob = new("/d/huafu/obj/mianfen");
        ob->move(who);
        message_vision("���˵ݸ�$Nһ����ۡ�\n",who);
      add("serve",-1);
       }
       else
        message_vision("�����Ĵ����˿�����$N˵����ԭ���Ѿ��ù��ˣ��Ȼ�������\n",who);
		
        return 1;
}
