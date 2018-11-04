// mmr.c

#include <ansi.h>

inherit NPC;
int ask_bo();
void create()
{
       	set_name("������ɮ", ({ "mengmian laoseng", "old monk", "laoseng" }) );
       	set("long","һλ���ŻҲ�ɮ�µ�ɮ�ˣ��������ŻҲ���\n" );       
       	set("gender", "����" );                
       	set("shen_type", -1);
       	set("age", 70);
       	set("combat_exp", 1800000);
       	set("attitude", "heroism");
       	set("unique", 1);
	set("shen_type", -1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("max_qi", 4500);
	set("max_jing", 4500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
	set("combat_exp", 3000000);
	set("score", 50000);                
	set("chat_chance_combat",40);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :)
}));
        set_skill("strike",200);
        set_skill("finger",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("canhe-zhi", 200);
	set_skill("murong-jianfa",200);       
        set_skill("shenyuan-gong", 200);
	set_skill("yanling-shenfa", 200);
        set_skill("douzhuan-xingyi", 230);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
        set_skill("murong-daofa", 200);
        set_skill("blade",200);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");

       set("inquiry", ([
                "Ľ�ݲ�" : (: ask_bo :),
                "Ľ�ݸ�" : "Ľ�ݸ������Ҷ��ӣ��Ǵ����Ψһ��ϣ���ˡ�\n",
       ]));

       setup();       
       
       carry_object("/clone/misc/cloth")->wear();
       add_money("silver", 10);
}


void kill_ob(object me)
{     
      command("grin");
      command("perform xingyi");
      ::kill_ob(me);
}
void init()
{
        object me = this_player();
        ::init();                          
        if(environment(me))
        {
	        if( me->query_temp("mrb_see") )
        	{
      			command("look " + me->query("id"));
	          	command("hehe");
        	  	command("say ����û��(no)���ӣ�");
          		me->set_temp("mrb_ask", 1);
        	}     

        	else 
        	{
	        	message_vision("$Nһ�Ű�$n�߳���Զ��\n", this_object(), me);
        		me->move("/d/murong/hb2");
        		message("vision", me->name()+"���˴����������˳�����\n", environment(me), ({me}));        	
        	}
        }
	add_action("yes", "yes");
       	add_action("no", "no");
	add_action("do_kneel", "kneel");	          	        
        return;
}

int no()
{
	object me = this_player();   
	if(!me->query_temp("mrb_ask")) return 0;         
	message_vision("\n$N��������δ���䣬������Ϣ��\n", me);
       	me->delete_temp("mrb_see");            
	me->force_me("halt");
	if(environment(me))	                                                            
	{
		remove_call_out("ask");
		call_out("ask", 1, me);                  
	}
	return 1;
}
                                                             
int yes()
{
	object me = this_player();
	if( !me->query_temp("mrb_ask1")) return 0;
	message_vision("\n$N�������գ�����������Ȼ�У�����Ը����������θɣ�\n", me);
	message_vision(CYN"\n����ɮ����������ж��ӣ������桢�游�����׶��ж��ӣ�������û�ж��ӣ�
�ٺ٣����������Ľ�����Һε�Ӣ�ۣ�ȴ���϶����������־������޺�֮�ˣ�\n\n"NOR, me);
	me->delete_temp("mrb_ask1");
	remove_call_out("wait");
	call_out("wait", 3, me);
	return 1;
}                                                            
void ask()
{
	object me = this_player();
	message_vision(CYN"\n������ɮ��$N��������(yes)û�����ڣ�\n"NOR, me);
	me->delete_temp("mrb_ask");
	me->set_temp("mrb_ask1", 1);
	return;
}

void wait()
{
	object me = this_player();
	if(environment(me))
	{
	write("\n�㲻��������ɮһϯ�������룺��������һʱ֮�ޣ���Ѱ�̼������ʱ�Ľ����
�Ӵ˾����������Ӷ�û�У���˵������ô���ڸ��������ɵ�ȫ���Ǻ���
�����̹�(kneel)�ڵء�\n\n");
	me->set_temp("mrb_said", 1);
	}
	return;
}

int do_kneel()
{
	object me = this_player();
	if( !me->query_temp("mrb_said")) return 0;
	message_vision("\n$N�����ݷ��ڵأ�˵����"+me->name()+"ʶ����׾�����ɸ�ɮָ���Խ򣬴����ã�û��������\n\n", me);
	me->delete_temp("mrb_said");
	remove_call_out("do_speech");
	call_out("do_speech", 2, me);
	return 1;
}	

void do_speech()
{
	object me = this_player();                                          
	if(environment(me))
	{
		message_vision("\n$N˵��������������$n�������� ��������ͷ��վ��������\n\n", this_object(), me);
		message_vision(CYN"\n$N���������Ľ�ݵļҴ��书���澫�£�������˫��ֻ����
��ûѧ���Ҷ��ѣ��ѵ�����Ͳ�����������ϵġ������񽣡��ˣ�
����ϸ�ˣ�$N���ʳָ������������¡�\n\n"NOR, this_object());
	remove_call_out("result");
	call_out("result", 2, me);   	
	}
	return;
}                                 

void result()
{
	object me = this_player();
	object ob;         
	if(environment(me))
	{
	message_vision(HIY"\nֻ���ÿ��������죬���ϵ�һֻ����Ӧ�����¡�\n\n"NOR, me);
	ob=new("/d/murong/obj/liutiao");
	ob->set("name", "�ϳ����ص�������");
	ob->set("weapon_prop/damage", 0);   
	ob->move(environment(me));
	remove_call_out("say");	
	call_out("say", 2, me);
	}
	return;
}                              

void say()
{
	object me = this_player();
	if(environment(me))
	{	
	message_vision(CYN"\n������ɮ����˵�����������Ľ�ݼҵġ��κ�ָ����
�������Ĵ������˴�ѧ����Ҳ����һ֪��⡢ѧ��һЩƤë���ѣ�
Ľ���ϴ���������书��֪���ж��١��ٺ٣��ѵ���ƾ��������
����һ��΢ĩ���У��㴴�ù���Ľ���ϡ��Ա�֮������ʩ����
�Ĵ���ô��\n\n"NOR, me);                
	me->set_temp("ask_bo", 1);
	write(HIY"�ѵ���λ��ɮ���ǡ�����Ľ�ݲ�����\n"NOR);
	}
	return;
}

int ask_bo()
{       
	object me = this_player();
	object ob = this_object();
	int ask = me->query_temp("ask");	
	if(!me->query_temp("ask_bo")) return 0;
	if(ob->query_temp("changed")) return 0;
	if( ask < 1 )
	{
		command("dunno");
		me->set_temp("ask", 1);        
		return 1;
	}                       
	if( ask >= 1 && ask < 6)
	{
		command("dunno "+ob->query("id"));
		me->add_temp("ask", 1);
		return 1;
	}                              
	if( ask == 6 )
	{
		command("sigh");
		command("whisper "+me->query("id")+" �������Ľ�ݲ���");
		me->delete_temp("ask");
		me->delete_temp("ask_bo");		
		ob->set_temp("changed", 1); 
		remove_call_out("change");
		call_out("change", 3, me);
		return 1;
	}

}

void change()
{
	object me = this_player();
	object ob = this_object();
	if(environment(me))
	{
	message_vision("$N�⿪���������ϵĻҲ���¶���˱��������ݡ�\n", ob);
	ob->set("name", "Ľ�ݲ�");                  
	ob->set("title", HIC"�Ա�֮�� ��ʩ����"NOR);
	ob->set("long", "��λ�������������ų��Ա�֮������ʩ����Ĺ���Ľ�ݲ���\n");
	}
	if( !me->query("meet_mrb"))
	{
		remove_call_out("teach");                      	
		call_out("teach", 2, me);
	}
	return;
}

void teach()
{
      	object me, mrb;
      	int i,lvl=1, level;
	mapping skills;
	string *sk;
      	me = this_player();
      	mrb = this_object();    
        level = (int)me->query_skill("douzhuan-xingyi", 1);
       	if(environment(me) && !me->query("meet_mrb"))
       	{
	      	if(me->query("int") < 27)
      		{       
      			command("say ���Ҵ˷�����������Ե�֣��粻������Щ�书����������������Ϊ��Ľ�����ˣ�");
	        	command("say ���������㽲�Ȿ�Ŷ�ת���Ƶ���ѧҪּ����������������̫�ֻ�ô��������ˡ�");
		        command("sigh");
        		skills = me->query_skills();
			if (mapp(skills)) 
			{
				sk = keys(skills);
				for (i=0;i<sizeof(sk);i++)
					skills[sk[i]]+=lvl;
			}
			me->add("combat_exp", 1000);
	      		me->set("potential", i);                                     
		      	me->set("meet_mrb", 1);
		      	tell_object(me, HIC"�����ѧ��Ϊ����ˣ�\n"NOR);             
	      		call_out("do_back", 15, me);           
	        	return;
        	}     
	      	else
      		{                                    
	      		command("say �ҿ������ʲ����������㶷ת������Ҫ��ϣ�����ܹ��Ľ����ѧ��
�����������Ա�֮������ʩ�������ٺ٣�");
        		tell_object(me, HIC "\nĽ�ݲ���ʼ���㽲�⶷ת���Ƶ���ѧҪּ������\n" NOR );              
	        	me->set_skill("douzhuan-xingyi", level+5);        
        		me->add("str", 1);
	        	skills = me->query_skills();
			if (mapp(skills)) {
				sk = keys(skills);
				for (i=0;i<sizeof(sk);i++)
					skills[sk[i]]+=lvl;
		}
		me->add("combat_exp", 1000);
	        me->set("meet_mrb", 1);
	      	tell_object(me, HIC"�����ѧ��Ϊ����ˣ�\n"NOR);             		
	      	remove_call_out("do_back");
		call_out("do_back", 15, me);    
        }
    }           
}

void do_back()
{     
      object me;
      me = this_player();    
      if(environment(me))
      {
	      message_vision(CYN"\n$N����Ц��������������ȴ¶��ʹ������顣\n"NOR, this_object());
	      message_vision(HIY"\n���к�Ȼ��ֻС�����ڰ�շ��Ӷ�����\n\n"NOR,me);
	      remove_call_out("do_leave");
	      call_out("do_leave", 5, me);                   
      }
      return;
}

void do_leave()
{
      object me, mrb;
      me = this_player();
      mrb = this_object();    
      if(environment(me))
      {   
      	      message_vision("$NͻȻ����ѽ��һ������ֻ����ǰһ����$N��Ӱ�����䵽����֮�⡣\n", mrb, me);
      	      destruct(mrb);      
      }       
      return;
}