//Npc ��ʦ
//by godzilla 11.18.99

#include <ansi.h>

string ask_job();

inherit NPC;

void create()
{
        set_name("��ʦ", ({"chu shi","chu","shi",}));
        set("long",
                "����λ���ֵ������ˣ��������Ϊ�����շ����˵�Ե�ʣ�����˷����İɡ�\n"
        );
        set("gender", "����");
        set("attitude", "peaceful");
        set("age", 44);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 400);
        set("max_jingli", 200);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 10);
        set("combat_exp", 2000);
        
        set_skill("force", 12);
        set_skill("dodge", 12);
        set_skill("unarmed", 12);
        set_skill("parry", 12);
        set("inquiry", ([
        "job"       : (: ask_job :),
        ]));
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
}
void init()
{
	object me;
	::init();
	if(interactive(me=this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting",1,me);
	}	
}
string ask_job()
{       
        mapping fam;
        object ob,me;
        me=this_player();
        if (!(fam = this_player()->query("family"))
            ||fam["family_name"] != "������")
            return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";
        if (me->query("combat_exp")>=55000)
            return RANK_D->query_respect(me)+"���������̫ί�����ˣ��㻹��ȥ�ɱ�İɣ�";
        if (me->query_temp("do_job1",1))
            return RANK_D->query_respect(me)+"�㻹�������ʲô����ȥ��������"; 
        ob = new(__DIR__"obj/chaidao");
        ob->move(me);
        me->set_temp("do_job1",1);
        me->add_temp("do_num",5+random(5));
        command("nod "+me->query("id"));
        message_vision("˵��$n�ݸ���$Nһ��"+RED+"�񵶡�\n"NOR,me,this_object());
        return "�ðɣ���ȥ���ߵĲ�ȥ��Щ�����ɡ�";
        
}
void greeting(object me)
{
	if( !me || environment(me) != environment() )
	return;
        if (me->query_temp("do_over_job1"))
        {
        	tell_object(me,HIR"��ʦ����˵������λ"+RANK_D->query_respect(me)+"������Щ��𣬻��Ѿ������ˣ�\n\n"NOR);
        }
        else
        {
        command("smile "+me->query("id"));
        }
}       
	 


 

 



