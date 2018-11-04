// NPC: tiejiang.c
// Created by Atlus 1999.9.27
// Modified by Atlus 1999.10.12
// 
// 
#include <ansi.h>

int ask_job();
int ask_cancal();

inherit NPC;

void create()
{
        set_name("����", ({ "tie jiang"}) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long",
                "����һλ�������������Ĵ�����\n");
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
            "job": (: ask_job :),
		    "cancal": (: ask_cancal :),
		
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

int ask_job()
{
        object me, obj;
        mapping fam;
    
        me=this_player();
        obj=this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="������") {
                command("say "+RANK_D->query_respect(me) +"���㲻�Ƿ����õĵ��ӣ��������ʲô��");
                return 1;
		}

		if( (int)me->query("combat_exp") > 50000) {

                        message_vision("������$N˵�� ��������������̫�˷��ˣ�ȥ��Щ��Ĺ����ɣ��� \n",me);

                 return 1;}
		
		
		if ( me->query_temp("fy_task_datie/given_task",1) )
		{
                command("say "+RANK_D->query_respect(me) +"�����Ѿ�Ҫ������");
                return 1;
		}

		me->set_temp("fy_task_datie/given_task",1);
		me->set_temp("fy_task_datie/da_time",5);

        command("say "+RANK_D->query_respect(me) +"����,��ȥ���Ϸ��������,�ٻ�������!");
        return 1;
}

int accept_object(object who, object ob) 
{
       int pot,exp;

		if ( !who->query_temp("fy_task_datie/huan_hammer"))
		{
                command("say ����ȥ����������,��������!");
				return 1;
		}
	   if (!who->query_temp("fy_task_datie/done"))  {
	            command("angry"+who->query("id"));
                command("say ����ô�ܹ��ñ��˵Ķ��������ҽ���!");
				return 1;
	   }

	   if (who->query_temp("fy_task_datie/done") && ob->query("id")=="wuqi" )  {
                command("nod "+who->query("id"));
                destruct(ob);
				exp=100+random(50);
                pot=25+random(15);
				who->add("potential",pot);
                who->add("combat_exp",exp);
                who->add("feiyu_job",1);
                who->delete_temp("fy_task_datie");
                message_vision(HIY"$N��������"+chinese_number(pot)+"��Ǳ�ܺ�"+chinese_number(exp)+"�㾭�顣\n"NOR,who);
                message_vision(HIC"$N�Ѿ�Ϊ����������"+chinese_number(who->query("feiyu_job"))+"������\n"NOR,who);
                command("say ����,�����ˡ���ȥ��Ϣȥ��!");
				return 1;
	   } 
       return 0;
}
int ask_cancal()
{
        object me, obj;
        mapping fam;
    
        me=this_player();
        obj=this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="������") {
                command("say "+RANK_D->query_respect(me) +"���㲻�Ƿ����õĵ��ӣ��������ʲô��");
                return 1;
		}

		
		if ( !me->query_temp("fy_task_datie/given_task",1) )
		{
                command("say "+RANK_D->query_respect(me) +"���㻹ûҪ������!");
                return 1;
		}

		me->delete_temp("fy_task_datie/given_task");
		me->delete_temp("fy_task_datie/da_time");
        me->delete_temp("fy_task_datie/given_hammer");             
		me->delete_temp("fy_task_datie");
		me->delete_temp("fy_task_datie/hot");
		me->delete_temp("fy_task_datie/done");
	    me->delete_temp("fy_task_datie/has_put");
        me->delete_temp("fy_task_datie/tiere_time");
        me->delete_temp("fy_task_datie/ran");
        me->delete_temp("fy_task_datie/huan_hammer");
        me->add("potential",-20);

        command("say "+RANK_D->query_respect(me) +"���㲻����,�Ǿ����˰�!");
        return 1;
}
