// qi.c ����ϼ


inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    set_name("����", ({ "men wei", "wei" }));
    set("gender", "����");
	set("age", 23);
        create_party(HIG"���ζ���"NOR,HIM"��Ժ"NOR,2);
        set("rank","����");

	set("combat_exp", 60000);
        set_skill("tao",50);
        set_skill("parry",50);
        set_skill("cuff",50 );
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("bairen-shengong",50);
        
        map_skill("force","bairen-shengong");
	
        create_family("���ζ���",4,"����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangdao")->wield();
}

void die()
{
        message_vision("$N�Һ�һ�������ˣ�\n", this_object());
        destruct(this_object());
}

void attempt_join()
{
        object ob;
        object mee;
        
        ob = this_player () ;
        mee=this_object();
        if ((int)ob->query("shen") < 0)
        {
        message_vision(HIC "$n��$N��ŭ����һ����Ͳ��Ǻ���!\n" NOR,ob,mee);
//      set_leader(this_player());
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, this_player()); 
        return;
        }
/*
        if ((int)ob->query("shen") < 1000)
        {
        message_vision(HIC "$Nҡҡͷ�����㻹��������!\n" NOR,mee);
        return;
        }
        if (ob->query("combat_exp")<10000)
        {
        message_vision(HIC "$n��$Nҡͷ�������ʵս����̫�͡�\n" NOR,ob,mee);
        return;
        }
*/
                command("smile");
                command("handshake "+this_player()->query("id"));
                command("nodjoin "+this_player()->query("id"));
                command("tell "+this_player()->query("id")+" ��ҴӴ˾���һ�����ˡ�\n");
        return;
}

