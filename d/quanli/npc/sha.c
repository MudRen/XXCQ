// /u/bmw/shaqiandeng.c ɳǧ��

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ɳǧ��",({"sha qiandeng","sha"}));
	set("nickname",HIW"һ���ϻ�"NOR);
	set("title","Ȩ����"+HIB"�ɵ���ħ"NOR);
	set("long",
	"�����ǽ������˳ơ��������£��뵶��������ƹ�Ӱ��һ���ϻ꣡����ɳǧ�ơ�\n"
	"һ�����ŵ����Ļ��ŵ����顣��˵��յ����ʹʮ����������ѣ����λ���ָ���Ϲ\n"
	"�ۣ���������һ�����ϻ������\n");
	set("age",48);
    set("accept",4800);
	set("gender","����");
	set("autitude","friendly");
	set("shen_type",1);
	set("con",25);
	set("int",25);
	set("dex",30);
	set("str",20);
	set("per",18);
	
	set("max_qi",3000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",50);
	
	set("combat_exp",1300000);
	set("score",2000);
	
//	set("inquiry",([
//		"�����":(: ask_li() :),
//		"��ʦ��":"��!�����Ҵ�ɩ��ʲô����ʲô��ͼ��",
//		"ʮ����ħ":(: ask_renmo() :),
//		"����¥":"����¥����������֮����������������������ˡ�",
//		"Ȩ����":(: ask_quanli :),
//		"佻�����":(: ask_huanhua :),
//		"������":"�����ҵ�Ȯ�ӡ�"
//		]));
			
	set_skill("dodge",200);
	set_skill("force",130);
	set_skill("sword",100);
	set_skill("blade",230);
	set_skill("unarmed",120);
	
	create_family("Ȩ����",2,"����");
	
	setup();
	
//    carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/dagger")->wield();

	
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
        if( !arg || arg!="sha" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"ɳǧ��Ŀǰ��ѧ���ļ��ܣ�   \n\n"+
"  �������� (blade)                         - ��ɲ� 200/    0      \n"+
"  �����Ṧ (dodge)                         - ��ɲ� 180/    0     \n"+
"  �����ڹ� (force)                         - ����似 150/    0        \n"+
"  ����ȭ�� (unarmed)                       - ����似 120/    0    \n");
   return 1;
}
