// huagufen.c ���·�	

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("���·�",({"hua gufen","hua"}));
	set("long",
	"���������ܿ������·ص���ʵ���ݣ����������ޱȣ����������µ���\n"
	"������û��һ�����˵ġ�\n"
	"ѩ�׵��·����԰׵��֣�������������ݡ�\n");
	set("party/rank",HIC"�ٶ���ħ"NOR);
	set("party/party_name","Ȩ����");
	set("age",35);
	set("gender","����");
	set("autitude","friendly");
	set("str",22);
	set("con",24);
	set("dex",31);
	set("int",29);
	
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
    set_skill("poison",220);
	set_skill("force",180);
	set_skill("sword",200);
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
        if( !arg || arg!="hua" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"���·�Ŀǰ��ѧ���ļ��ܣ�    \n\n"+
"  �����Ṧ (dodge)                         - �����뻯 150/    0     \n"+
"  �����ڹ� (force)                         - һ����ʦ 180/    0   \n"+
"  �������� (sword)                         - ��ɲ� 200/    0   \n"+
"  ����ȭ�� (unarmed)                       - ����似 120/    0  \n"+
"  �������� (poison)                        - �������� 220/    0       0/    0    \n");
"  �����Ṧ (dodge)                         - ��ɲ� 200/    0        \n"+
"  �����ڹ� (force)                         - ��ɲ� 200/    0        \n"+
"  �����м� (parry)                         - ��ɲ� 200/    0        \n"+
"  �������� (sword)                         - ��ɲ� 220/    0        \n"+
"  ����д�� (literate)                      - �����ž� 180/    0       0/    0  \n"+
"������֮�� (wuxing-jian)                   - �������� 220/    0       0/    0  \n");
   return 1;
}
