// /u/bmw/kangchuyu.c ������	

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������",({"kang chuyu","kang"}));
	set("nickname",HIY"������"NOR);
	set("title","Ȩ����"+HIB"������ħ"NOR);
	set("long",
	"������ʮ���꿪ʼϰ������ʮ����������������ʮ�������������ߴ�������\n"
	"����Ŀ��࣬���޷��ף���Ŀ�о������䣬��һ�ѽ�һ��Ϭ����\n");
	set("age",51);
    set("accept",2000);
	set("gender","����");
	set("autitude","friendly");
	set("con",25);
	set("int",28);
	set("dex",26);
	set("str",22);
	set("per",22);
	
	set("max_qi",3000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",50);
	
	set("combat_exp",1500000);
	set("score",2000);
	
	set("inquiry",([
		"������":"�����ҵ�Ȯ�ӡ�",	
		"Ȩ����":"��ԸΪȨ���︰�����𣬾��Ҿ�����",
		]));
			
	set_skill("dodge",180);
    set_skill("guanri-jian",200);
	set_skill("force",180);
	set_skill("sword",200);
	set_skill("unarmed",120);
	
	setup();
	
    map_skill("sword","guanri-jian");
    map_skill("parry","guanri-jian");
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/weapon/changjian")->wield();

	
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
        if( !arg || arg!="kang" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"������Ŀǰ��ѧ���ļ��ܣ�   \n\n"+
"  �����Ṧ (dodge)                         - һ����ʦ 180/    0      \n"+
"  �����ڹ� (force)                         - һ����ʦ 180/    0    \n"+
"  ���ս��� (guanri-jian)                   - �������� 200/    0       0/    0     \n"+
"  �������� (sword)                         - ��ɲ� 200/    0     \n"+
"  ����ȭ�� (unarmed)                       - ����似 120/    0    \n");
   return 1;
}
