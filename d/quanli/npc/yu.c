// yukuyu.c �����	

#include <ansi.h>

inherit NPC;
int ask_box();

void create()
{
	set_name("�����",({"yu kuyu","yu"}));
	set("long",
	"������ö��������ƴ�ͻ��·أ�Ȩ����ʮ����ħ֮һ��\n"
	"������һ�Ŵ�����Ȼ���۾������ӣ���Ͷ���С��С��ʱ������\n"
	"ɳ�ƵĹ�������\n");
	set("party/rank",HIC"������ħ"NOR);
    set("accept",2000);
	set("party/party_name","Ȩ����");
	set("age",52);
	set("gender","����");
	set("autitude","friendly");
	set("str",22);
	set("con",24);
	set("dex",31);
	set("int",30);
	
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
    set_skill("gudu",200);
    set_skill("parry",150);
    set_skill("poison",200);
	
        set("inquiry", ([
                "gudu" : (: ask_box :),
                "�ƶ�֮��" : (: ask_box :),
        ]) );
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
        if( !arg || arg!="yu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"�� �����Ŀǰ��ѧ���ļ��ܣ�    \n"+
"\n  �����Ṧ (dodge)                         - �����뻯 150/    0    \n"+
"  �����ڹ� (force)                         - �����뻯 150/    0        \n"+
"  �����м� (parry)                         - �����뻯 150/    0      \n"+
"  �ƶ�֮�� (gudu)                          - ��֪һ�� 200/    0       0/    0     \n"+
"  �������� (poison)                        - �������� 200/    0       0/    0       \n");
   return 1;
}
int ask_box()
{
   object obj,me = this_player();
   if( me->query_skill("gudu",1) < 100 )
   {  command("say ��Ĺƶ�֮�������У��Ҳ��ܰѹƺн�����!\n");
     return 1;
     }
    command("ok");
    command("say �ҽ��ƺи��㣬Ҫ�úõ��������������ǳ���Ȩ���������!\n");
   obj = new("/d/quanli/npc/obj/box");
   obj->move(me);
    return 1;
}
