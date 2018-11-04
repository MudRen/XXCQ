// tang.c ��һ��

#include <ansi.h>
inherit NPC;
#include "/d/huafu/npc/cam.h"

int ask_job();
void create()
{
	set_name("��һ��", ({ "tang yidu", "tang" }));
        set("nickname",HIY"��������"NOR);
	set("gender", "����");
         set("rank","����");
	set("age", 45);

	set("combat_exp", 60000);
        set_skill("cuff",50 );
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("bairen-shengong",50);
        
        map_skill("force","bairen-shengong");
       create_party(HIG"���ζ���"NOR,HIC"����"NOR,3);
	
	setup();
	set("inquiry",([
		"job" : (: ask_job :),
	]));
	carry_object("/clone/misc/cloth")->wear();
}

int ask_job()
{
	object me;
	mapping party;
	mapping myfam;
        int i;
        object money;
	me=this_player();
        party=(mapping)me->query("party");
        myfam=(mapping)me->query("family");
	
	if( (!party || party["party_name"] != HIG "���ζ���" NOR) && ( !myfam || myfam["family_name"] != "���ζ���") )
	{
		command("say "+RANK_D->query_respect(me)+"�����ҷ��ζ������ֵܣ������������ͷ����أ�");
		return 1;
	}
        if ( (me->query("combat_exp")>40000 ) && myfam )
	{
                command("say "+RANK_D->query_respect(me)+"�����Ĳ������ڲ���Ҫ���æ�ˡ�\n");
		return 1;
	}
         if ( party && !myfam) {
                command("say �������Ƿ��ζ������ֵ��ˣ�ȥ��ıʯ�ǿ�����ʲô�����ɡ�");
		return 1;
        }
          if ( me->query_temp("fmjob_ok") )
	{
          if ( me->query_temp("fmjob_start") )
		{
			command("say ��л����л�������ˣ���ȥ��Ϣ��Ϣ�ɡ�");
                        me->add("potential", 50+random(50));
                        me->add("combat_exp", 75+random(75));
                        for (i=1;i<5;i++)
                        {
                               money=new("/clone/money/silver");
                               money->move(me);
                        }
                          me->delete_temp("fmjob_start");
                          me->delete_temp("fmjob_ok");
			return 1;
		}
		command("say ��û����ȥ������ȴȥ��æ���������������ĺ��˲��డ��");
		me->add("potential", 1+random(10));
		me->add("combat_exp", 3+random(10));
                  me->delete_temp("fmjob_ok");
		return 1;
	}
	message_vision("�ð�,$N��ȥ���㷻��æ�ɣ�\n",me);
	message_vision("��Ƶ�ԭ����ȵ�����ȥ�����ɣ�\n",me);
          me->set_temp("fmjob_start",1);
	return 1;
}

void attempt_join()
{
        object ob;
        object mee;
        
        ob = this_player () ;
        mee=this_object();
        if ((int)ob->query("shen") < 0)
        {
        message_vision(HIC "$n��$N��ŭ����һ����Ͳ��Ǻ���!\n" NOR,ob,mee);
//      set_leader(this_player());
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, this_player()); 
        return;
        }
        if ((int)ob->query("shen") < 1000)
        {
        message_vision(HIC "$Nҡҡͷ�����㻹��������!\n" NOR,mee);
        return;
        }
        if (ob->query("combat_exp")<10000)
        {
        message_vision(HIC "$n��$Nҡͷ�������ʵս����̫�͡�\n" NOR,ob,mee);
        return;
        }
                command("smile");
                command("handshake "+this_player()->query("id"));
                command("nodjoin "+this_player()->query("id"));
                command("tell "+this_player()->query("id")+" ��ҴӴ˾���һ�����ˡ�\n");
        return;
}


