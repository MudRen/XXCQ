// Room: /welcome/npc/netplay.c
//By adx @ CuteRabbit 15:57 99-5-18

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("��ϰ", ({ "jiaoxi" }));
        set("title",WHT"Сѩ������ѩɽ"NOR);
        set("long", "������ѩɽ�Ľ�ϰ���������书��\n");
        set("gender", "����");
        set("age", 65);

        set_skill("dodge", 50);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("blade", 50);

        set("combat_exp", 4000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
         if ((int)ob->query("newbei")!=1) return 0;
        return 1;
}

int accept_fight(object ob)
{
	object me  = this_object();
/*
	if (me->query("age") < 15)
	{
		command("laugh " + ob->query("id"));
		command("say " + RANK_D->query_respect(ob) + 
             "�����ڻ�С������ѩɽ��ѧϰһ��ʱ��� !\n");
		return 0;
	}
*/
    if (me->query("newbei")==1)
	{
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		return 1;
	}
	else {
		command("kick " + ob->query("id"));
		command("say " + RANK_D->query_respect(ob) + 
             "���غ��ҽ����������뿪��ѩɽ�� !\n");
		return 0;
	}
}

int checking(object me, object ob)
{

	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
                return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if ( (((int)me->query("qi")*100 / my_max_qi) <= 50) &&
		(me->query("age") >= 15) ) 
	{
		command("ok " + ob->query("id"));
		command("say " + RANK_D->query_respect(ob) + 
             "�����뿪��ѩɽ�� ! ��ϲ���� !\n");
                command("say �ڽ�����������Ҫ�Ĳ������书����Ҫѧ�Ļ��ܶ࣡");
                 command("say �����Ŭ���������������̣�") ;
                 command("say ף�������죡"); 
                 command("say ���߰ɣ�");
         ob->delete("newbei");
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("papaya " + ob->query("id"));
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ������������������ !\n");
		return 1;
	}

	return 1;  
}
