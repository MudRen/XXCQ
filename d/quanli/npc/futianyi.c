// futianyi.c ������	

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������",({"fu tianyi","fu"}));
	set("long",
	"�����峣������������ųǣ�ֻ�е�Ȩ����Ҫ������ʱ���ų�ɽ��\n"
	"������ݸߣ�Ψ�����۷ǳ���׳�������ڷ���΢΢������\n");
	set("party/rank",HIC"������ħ"NOR);
	set("party/party_name","Ȩ����");
	set("age",62);
	set("gender","����");
	set("autitude","friendly");
	set("str",33);
	set("con",28);
	set("dex",30);
	set("int",25);
	
	set("max_qi",3000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",50);
	
	set("combat_exp",1500000);
	set("score",2000);
	
	set("inquiry",([
		"Ȩ����":"��ԸΪȨ���︰�����𣬾��Ҿ�����",
		]));
			
    set_skill("dodge",150);
    set_skill("force",150);
    set_skill("strike",200);
    set_skill("unarmed",200);
	
	setup();
	
    carry_object("/clone/misc/cloth")->wear();

	
}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}
int do_skills(string arg)
{
        object ob ;
        ob = this_player () ;
        if( !arg || arg!="fu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"������Ŀǰ��ѧ���ļ��ܣ�     \n"+
"  �����Ṧ (dodge)                         - �����뻯 150/    0    \n"+
"  �����ڹ� (force)                         - �����뻯 150/    0      \n"+
"  �����Ʒ� (strike)                        - ��ɲ� 200/    0      \n"+
"  ����ȭ�� (unarmed)                       - ��ɲ� 200/    0     \n");
   return 1;
}
