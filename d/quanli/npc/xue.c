// xueying.c ѪӰ	

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ѪӰ",({"xue ying","xue"}));
	set("long",
	"ѪӰ��ħ�������µ���ͽ����һ�α������������磬�Ӵ˷���Ч��\n"
	"Ȩ�����ϧ���������¡�\n"
	"������������ģ����ϲ���ɱ�����۾��ɵô��ľ���Ҫ���˳��ˡ�\n");
	set("party/rank",HIC"ѪӰɮħ"NOR);
    set("accept",2000);
	set("party/party_name","Ȩ����");
	set("age",45);
	set("gender","����");
	set("autitude","friendly");
	set("str",33);
	set("con",28);
	set("dex",25);
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
    set_skill("xueying-zhang",200);
    set_skill("strike",180);
    set_skill("huoyan-dao",180);
    set_skill("banruo-changong",180);
    set_skill("parry",180);
	set_skill("unarmed",120);
	
	setup();
	
    map_skill("strike","xueying-zhang");
    map_skill("force","banruo-changong");
    map_skill("parry","xueying-zhang");
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
        if( !arg || arg!="qu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"��ѪӰ��ʦĿǰ��ѧ���ļ���       \n"+
"  �����Ṧ (dodge)                         - ��ɲ� 150/    0        \n"+
"  �����ڹ� (force)                         - ��ɲ� 150/    0        \n"+
"  �����м� (parry)                         - ��ɲ� 180/    0        \n"+
"  �����Ʒ� (strike)                         - ��ɲ� 180/    0        \n"+
"  �������� (banruo-changong)               - ��ͨƤë 180/    0       0/    0  \n"+
"��ѪӰ�� (xueying-zhang)                   - �������� 200/    0       0/    0    \n"+
"����浶 (huoyan-dao)                   - �������� 180/    0       0/    0  \n");
   return 1;
}

