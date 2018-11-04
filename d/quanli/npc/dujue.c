// dujue.c �ž�	

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�ž�",({"du jue","du"}));
	set("long",
	"�ž�����������ž���С���˱�����ɱ�⣬�����ڶ��˼����ɱ��\n"
	"���𣬰Ѷ���ȫ��ɱ�⣬�ֶ�֮���̣����˷�ָ��\n"
	"������ɱ����壬���в���Ѫ˿���ֽ������ŵ�����\n");
	set("age",42);
	set("party/rank",HIC"�쵶��ħ"NOR);
	set("party/party_name","Ȩ����");
	set("gender","����");
	set("autitude","friendly");
	set("str",24);
	set("con",28);
	set("dex",30);
	set("int",28);
	
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
			
    set_skill("dodge",180);
    set_skill("parry",180);
    set_skill("blade",200);
    set_skill("force",180);
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();

	
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
        if( !arg || arg!="du" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"�ž�Ŀǰ��ѧ���ļ��ܣ�    \n\n"+
"  �������� (blade)                         - ��ɲ� 200/    0   \n"+
"  �����Ṧ (dodge)                         - һ����ʦ 180/    0   \n"+
"  �����ڹ� (force)                         - һ����ʦ 180/    0    \n"+
"  �����м� (parry)                         - һ����ʦ 180/    0  \n");
   return 1;
}
