// qi.c ����ϼ


inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    set_name("����", ({ "men wei", "wei" }));
    set("gender", "����");
	set("age", 23);

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

/*
void init()
{
	object ob;

	::init();
	add_action("do_join","join");
  if( interactive(ob = this_player()) && !is_fighting() ) {^M

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
    } 
}

int do_join(string arg)
{
   	object ob;
   	object mee;
   	mapping party;
   	
   	ob = this_player () ;
   	mee=this_object();
   	if( !arg || arg!="fameng" )
		return notify_fail("��Ҫ����ʲô��֯��\n"); 
   	if ((int)ob->query("shen") < 0)
        {
	message_vision(HIC "����ϼ��$N��ŭ����һ����Ͳ��Ǻ���!\n" NOR,this_player());
//	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
      	if ((int)ob->query("shen") < 1000)
        {
	message_vision(HIC "����ϼҡҡͷ�����㻹��������!\n" NOR,this_player());
  	return 1;
	}
   	if (ob->query("combat_exp")<10000)
        {
	message_vision(HIC "����ϼ��$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
  	return 1;
  	}
    	if( !mapp(party = ob->query("party")))
   	{
		party = allocate_mapping(5);
		party["party_name"] = HIG "���ζ���" NOR;
		party["rank"] = "����";
		party["level"] = 1;
		party["tasks"] = 0;
		party["enter_time"] = time();
		ob->set("party", party);

		command("smile");
		command("handshake "+this_player()->query("id"));
    		command("tell "+this_player()->query("id")+" ��ҴӴ˾���һ�����ˡ�\n");
		return 1;
	}
   	if( party["party_name"] != HIG "���ζ���" NOR )
	{
		message_vision("$N��$nҡҡͷ��˵����$n�Ѿ�������������ˡ�\n",mee,ob);
		return 1;
	}
	if( party["party_name"] = HIG "���ζ���" NOR ) 
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ����ҷ��ζ������ֵ��ˡ�\n",mee,ob);
		return 1;
	}
}
	
*/
