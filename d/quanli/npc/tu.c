 // tugun.c ����

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����",({"tu gun","tu"}));
	set("long",
	"������š�������ʮ���֣���׮��ʮ��·������ʹ�����벼��ɱ��\n"
	"�����Σ���Ͷ��Ȩ���\n"
	"���ʷʵ���������һ����������С�۲�ʱ������ȥ��\n");
	set("party/rank",HIC"ǧ����ħ"NOR);
	set("party/party_name","Ȩ����");
	set("age",42);
	set("gender","����");
	set("autitude","friendly");
	set("str",25);
	set("con",26);
	set("dex",32);
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
			
    set_skill("dodge",150);
    set_skill("force",150);
    set_skill("throwing",200);
    set_skill("parry",150);
	
	setup();
	
    carry_object("/clone/misc/cloth")->wear();
	
}
#include "quanli.h"

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
        if( !arg || arg!="tu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"����Ŀǰ��ѧ���ļ��ܣ�   \n"+
"\n  �����Ṧ (dodge)                         - �����뻯 150/    0     \n"+
"  �����ڹ� (force)                         - �����뻯 150/    0     \n"+
"  �����м� (parry)                         - �����뻯 150/    0     \n"+
"  �������� (throwing)                      - ��ɲ� 200/    0    \n");
   return 1;
}
