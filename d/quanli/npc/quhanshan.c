// quhanshan.c
// by mulan

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int do_skills(string arg);

void create()
{
        set_name("����ɽ", ({"qu hanshan", "qu"}));
        set("gender", "����");
        set("accept", 8000);
        set("age", 56);
        set("nickname",HIM"������˷"NOR);
        set("long",
                "���糤�룬�ɷ���ǣ�̬��Ӻ�ݣ����˾�������ɽ�����������еġ�������˷����Ҳ�ǡ�Ȩ����еġ���������\n");
        set("shen_type",1);
        set("shen",-100000);
        set("str", 52);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("title","��Ȩ����__������");

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 2000000);
        set("score", 300000);

        set_skill("force", 200);
        set_skill("sword", 220);
        set_skill("wuxing-jian",220);  
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("literate",180);

        map_skill("sword", "wuxing-jian");
        map_skill("parry", "wuxing-jian");

        setup();

        carry_object("/clone/weapon/changjian")->wield();
//        carry_object(__DIR__"obj/grayrobe")->wear();

}

/*
 int recognize_apprentice(object ob)
 {
     if (ob->query("party/party_name")!= "Ȩ����")
     {
     message_vision("$Nҡ��ҡͷ��\n",this_object());
     command("say "+ob->query("id")+"����Ȩ������Ҳ��̡�\n");
     return 0;
     }
        if(ob->query("party/tasks") < this_object()->query("accept"))
          {
          command("say ���Ȩ����Ĺ��׻�����,��ȥ����!\n");
          return 0;
          }
     return 1;
 }

*/
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
"������ɽĿǰ��ѧ���ļ��� 	\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 200/    0	\n"+
"  �����ڹ� (force)                         - ��ɲ� 200/    0	\n"+
"  �����м� (parry)                         - ��ɲ� 200/    0	\n"+
"  �������� (sword)                         - ��ɲ� 220/    0	\n"+
"  ����д�� (literate)                      - �����ž� 180/    0       0/    0	\n"+
"������֮�� (wuxing-jian)                   - �������� 220/    0       0/    0	\n");
   return 1;
}
