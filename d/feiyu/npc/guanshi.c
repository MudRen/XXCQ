// NPC: feiyudizi.c
// Created by Atlus 1999.10.12
// Modified by Zeus 1999.5.12
// 
// 

int ask_hammer();

inherit NPC;

void create()
{
        set_name("���Ϸ�����", ({ "guan shi"}) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long",
                "����һλ�������������Ϸ��Ĺ��¡�\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 400);
        set("max_jingli", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 30000);

        set("inquiry", ([
            "����": (: ask_hammer :),
		]) );

		set_skill("unarmed", 50);     //������
        set_skill("force", 50);       //�����ڹ�
        set_skill("dodge", 50);       //�����Ṧ
        set_skill("parry", 50);       //�����м�
        set_skill("literate", 30);    //����д��
 	    set_skill("youyu-quan",90);  //����ȭ
        create_family("������", 6, "����");

        setup();
}

int ask_hammer()
{
        object me, obj, hammer;
        mapping fam;
    
        me=this_player();
        obj=this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="������") {
                command("say "+RANK_D->query_respect(me) +"���㲻�Ƿ������ĵ��ӣ��벻Ҫ��!");
                return 1;
		}

		if ( me->query_temp("fy_task_datie/given_hammer") )
		{
                command("say "+RANK_D->query_respect(me) +"���㲻���Ѿ�����������");
                return 1;
		}

		if ( !me->query_temp("fy_task_datie/given_task",1) )
		{
                command("say "+RANK_D->query_respect(me) +"����Ҫ������ʲô��");
                return 1;
		}

		me->set_temp("fy_task_datie/given_hammer",1);

		hammer=new("/d/feiyu/obj/hammer");
		hammer->move(me);
        command("say "+RANK_D->query_respect(me) +"���ú�,��Ū���ˣ�");
        return 1;
}

int accept_object(object who, object ob) 
{
	   if (who->query_temp("fy_task_datie/done") && ob->query("id")=="hammer" && !who->query_temp("fy_task_datie/huan_hammer"))  {
                command("say ����,�����ˡ���ȥ��Ϣȥ��!");
				destruct(ob);
				who->set_temp("fy_task_datie/huan_hammer",1);
				return 1;
	   } 
       return 0;
}
