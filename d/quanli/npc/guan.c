// guhuanqing.c �˻���	

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�˻���",({"gu huanqing","gu"}));
	set("long",
	"�˻�����Ȩ����ʮ����ħ֮һ�����ȹ��ó��������������˽��¡�\n"
	"��ò�����ᣬ������С����˫��ȴ�ǳ����\n");
	set("party/rank",HIC"������ħ"NOR);
	set("party/party_name","Ȩ����");
	set("age",37);
	set("gender","����");
	set("autitude","friendly");
	set("str",24);
	set("con",28);
	set("dex",31);
	set("int",26);
	
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
	set_skill("force",180);
    set_skill("leg",180);
	set_skill("unarmed",120);
	
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
        if( !arg || arg!="gu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"�˻���Ŀǰ��ѧ���ļ��ܣ�   \n\n"+
"  �����Ṧ (dodge)                         - һ����ʦ 180/    0     \n"+
"  �����ڹ� (force)                         - һ����ʦ 180/    0    \n"+
"  ����ȭ�� (unarmed)                       - ����似 120/    0   \n"+
"  �����ȷ� (leg)                           - ��ͨƤë 180/    0       0/    0       \n");
   return 1;
}
