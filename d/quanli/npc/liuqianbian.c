// liuqianbian.c ��ǧ��

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ǧ��",({"liu qianbian","liu"}));
	set("long",
	"�������ֺڰ׵��ŷ�ɥ������ǧ�䣬�������Ṧ�����Ʋ���������\n"
	"һ��ר��������ʮ����Ѩ����ʮ��СѨ��ǧ����õ����ȡ�\n"
	"�����Ķ��ţ����ǽ��������ȻӶ����¡�\n");
	set("party/rank",HIC"��Ӱ��ħ"NOR);
	set("party/party_name","Ȩ����");
	set("nickname",HIB"�����п�"NOR);
	set("age",39);
	set("gender","����");
	set("autitude","friendly");
	set("str",24);
	set("con",28);
	set("dex",33);
	set("int",27);
	
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
			
    set_skill("dodge",200);
    set_skill("force",150);
    set_skill("sword",150);
//    set_skill("qingyun-step",200);
	
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
        if( !arg || arg!="liu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"�� ��ǧ��Ŀǰ��ѧ���ļ��ܣ�    \n\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 200/    0        \n"+
"  �����ڹ� (force)                         - �����뻯 150/    0     \n"+
"  �������� (sword)                         - �����뻯 150/    0 \n");
   return 1;
}
