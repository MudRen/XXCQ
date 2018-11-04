//Npc ����ѩ
//by godzilla 11.18.99

#include <ansi.h>

int ask_sword();

inherit F_MASTER;

inherit NPC;

void create()
{
        set_name("����ѩ",({"song zixue","song","zixue"}));
        set("long","���������������ţ��ǰ������ѵõ���ģ������潣ԭ��ֻ���߽���
����ѩ17����Դ�15����24��ʹ���24��ȫ��������27�������Ϊ���š���������
������֮һ��\n");
        set("title",HIW"������"HIY"����"NOR);
        set("nickname",HIR"�����潣"NOR);
        set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 50);
	set("int", 55);
	set("con", 50);
	set("dex", 50);
	
	set("max_qi", 6500);
	set("max_jing", 6000);
	set("neili", 10000);
	set("max_neili", 6000);
	set("jiali", 200);
	set("combat_exp", 2000000);
	set("tianyu_1",1);
       
        set_skill("strike",200);
         set_skill("tianyu-zhenfa",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("literate", 200);
        set_skill("tianyu-qigong",200);
        set_skill("tianyu-qijian",250);
        set_skill("tianyu-bufa",200);
        set_skill("tao",250);
        
        map_skill("sword", "tianyu-qijian");
        map_skill("force", "tianyu-qigong");
        map_skill("dodge", "tianyu-bufa");
        map_skill("parry", "tianyu-qijian");
;

        set("inquiry", ([
        "��罣"       : (: ask_sword :),
        ]));
        create_family("������", 7, "����");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
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
	add_action("do_accept","accept");
}
int ask_sword()
{       
        object me,ob,obj;
        obj=this_object();
        me=this_player();
        if(me->query("family/family_name")=="������")
        {
        	if(this_object()->query("mark/ȡ��"))
        	{
        		command("say ��罣�Ѿ�����ʦ����ȥ�ˡ�\n");
        		return 1;
        	}	
        	message_vision(CYN"����ѩ��$N˵������罣�������������������������ţ�������ܽ�
        	�Ҽ��У��Ϳ��Խ轣���㡣���ͬ������(accept test)\n"NOR,me);
        	me->set_temp("try_1",1);
        	return 1;
        }
        else
        {      
        	if(this_object()->query("mark/ȡ��"))
        	{
        		command("say ���Ҵ�����������������⣬"+me->name()+"�������ɣ�");
        		this_object()->kill_ob(me);
        		return 1;
        	}	
        	message_vision(CYN"����ѩ�ȵ���$N���Ҵ�����������������⣬�ð������ʶһ�½�罣��������\n"NOR,me);
        	command("unwield jian");
        	ob=new(__DIR__"obj/jinhong-jian");
        	ob->move(this_object());
        	command("wield jinhong jian");
        	this_object()->kill_ob(me);
        	return 1;
        }	
        	
               
}
void greeting(object me)
{
	if( !me || environment(me) != environment() )
	return 0;
	if(me->query("family/family_name")=="������")
	{
		command("smile "+me->query("id"));
		command("pat "+me->query("id"));
	}
	else
	{
		message_vision(CYN"����ѩ��$N˵�����Ͽ��뿪�������ɿ���������Щ���Ҵ��ġ�\n"NOR,me);
		command("consider "+me->query("id"));
	}	
	
}
void attempt_apprentice(object ob)
{
	if(!ob->query("congra_baishi"))
	{
		command("say ���������鲻�ò�����ͽ!\n");
		return;
	}
        if((int)ob->query_skill("tianyu-qijian",1)<150)
	{
		command("say �������潣�������죬������һ�������ɣ�\n");
		return;
	}		
	command("nod "+ob->query("id"));
	command("say ��������Ҫ������������");	
	command("recruit " + ob->query("id"));
	ob->delete("congra_baishi");
	ob->set("title",HIR"�����������״�����"NOR);
}	
int do_accept(string arg)
{
	object ob,me;
	me=this_player();
	if(!arg||arg=="")
	return 0;
	if(!me->query_temp("try_1"))
	return 0;
	if(arg=="test")
	{
		command("say �ð�!�����!\n");
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
		if(me->query("qi")<150)
		{
			command("sigh");
			command("say ������ö����ϰ!");
			me->set_temp("try_1",0);
			return 1;
		}
		else
		{
			command("say ���������ܽ�������֮���Ѿ����࣬�������Ǹ�����֮�ģ�\n");
			command("say ��罣�˱��������������������ţ���Ҫ�úñ��ܣ�\n");
			ob=new(__DIR__"obj/jinhong-jian");
			ob->move(me);
			message_vision(CYN"˵��,����ѩ�����Լ���"+YEL+"��罣"+CYN+"�ݸ���$N��\n"NOR,me);
			set("mark/ȡ��",1);
			me->set_temp("try_1",0);
			return 1;
		}	
	
	}	
		
}
int accept_object(object me, object obj)
{
	object ob  = this_object();
	if(obj->query("id") == "huaming ce")
	{
		 if(me->query("family/family_name")!="������")
		 {
		 	command("say Ŷ�� û�뵽���ɵĻ����ᱻ��Ϊ"+RANK_D->query_respect(ob)+"�ҵ��ˣ�������\n");
		 	return 1;
		 }
		 if(obj->query("write_name")!=me->query("id")||!obj->query("write_name"))
		 {
		 	message_vision(CYN"����ѩ���˿��������ϵ����֣��ֿ�����$N������ʧ����ɫһ��������\n"NOR,me);
		 	command("say Ŷ��û�뵽���ɵĻ����ᱻ��Ϊ"+RANK_D->query_respect(ob)+"�ҵ��ˣ�������\n");
		 	return 1;
		  }
		  command("say ��������Ϊ�������˴󹦣����������鲻����ô�������Ϊʦ��?\n");
		  me->set("congra_baishi",1);
		  remove_call_out("destroying");
		  call_out("destroying",1,ob,obj);
		  return 1;
	}	  
}
void destroying(object ob,object obj)
{
	destruct(obj);
        return;
}        
