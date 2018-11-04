// sample master.c code
// xiake island master.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;



void create()
{
    set_name("����", ({"tu fei", "fei"}));
	set("gender", "����");
	set("age", 26);
	set("long", 
                "����Ц�����Ŀ����㡣\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 15);
	set("con", 20);
	set("dex", 25);

	set("qi", 300);
	set("max_qi", 300);
	set("jingli", 200);
	set("max_jingli", 200);
	set("neili", 100);
	set("max_neili", 100);
	
	set("combat_exp", 1000);
	
	set_skill("force", 10);
	set_skill("strike", 10);
	set_skill("cuff",10);
	set_skill("dodge", 10); 
	set_skill("whip", 10); 
	set_skill("spear", 10); 
	set_skill("axe", 10); 
	set_skill("club", 10); 
	set_skill("stick", 10); 
	set_skill("sword", 10); 
	set_skill("staff", 10); 
	set_skill("blade", 10); 
	set_skill("parry", 10); 
	set_skill("literate", 10); 
	
	setup();

	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();

          add_money("silver", 10+random(20));
}


void init()
{       
        object ob;

            ob=this_player();
                   if (query("followid")!=ob->query("id"))     return;
                if (ob->query_temp("followed"))    return;
                   command("sweat");
                   command("touch "+ob->query("id"));
                   command("say ����ȵ������ˡ�");
                   command("follow "+ob->query("id"));
                  ob->set_temp("followed",1);
                  ob->set_temp("begin",1);
                   ob->apply_condition("xhquest1",20);
}

void die()
{
        message_vision(this_object()->query("name") + "�Һ�һ���������ڵأ����ˡ�\n", this_object());
                destruct(this_object());
}

void unconcious()
{
               message_vision(HIG"ͻȻɱ����������Ͷ���"+this_object()->query("name")+"�Ϳ�һ��\nȻ����Ĵ�ɢ���������ˡ�\n"NOR,this_object());
               this_object()->die();
               return;
}

