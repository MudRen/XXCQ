int ask_me()
{
	object me;
	object ob;
	object where;
	mapping party,myfam;
	me=this_player();
	where=environment(me);
	party=(mapping)me->query("party");
	myfam=(mapping)me->query("family");
	
        if ( ( !party || party["party_name"]!=HIG "���ζ���" NOR ) && ( !myfam || myfam["family_name"]!="���ζ���" ) )
	{
		command("say �Ҳ��ܰ�������˿���");
                return 0;
	}
	
        if ( file_name(where)!="/d/wenzhai/sxge")
         {
              command("say ��������������Ҳ����顣");
              return 0;
         }
	if ( where->query("book_asked") )
	{
		command("say ���Ѿ����������ˡ�");
                return 0;
	}
	
	command("say �ðɣ��⼸������ܶ������ã��кúö����ɡ�");
	ob=new("/d/wenjia/obj/forcebook");
	ob->move(where);
	ob=new("/d/wenjia/obj/dodgebook");
	ob->move(where);
	ob=new("/d/wenjia/obj/swordbook");
	ob->move(where);
	ob=new("/d/wenjia/obj/bladebook");
	ob->move(where);
	where->set("book_asked",1);
	return 1;
}

int ask_job()
{
	object me;
	mapping party,myfam,quest;
	me=this_player();
	party=(mapping)me->query("party");
	myfam=(mapping)me->query("family");
	quest = "/d/huafu/quest/fmquest"->query_quest();
	
        if ( ( !party || party["party_name"]!=HIG "���ζ���" NOR ) && ( !myfam || myfam["family_name"]!="���ζ���" ) )
	{
		command("say ���뱾�����޹�ϵ�������²�����������");
		return 1;
	}
	
            if ((me->query("combat_exp")>700000) && party)
            {
                   command("say ���Ѿ��ǳ��������ˡ��㲻�������������ˡ�");
                   return 1;
                }
	if ( myfam && myfam["family_name"]=="���ζ���" )
	{
         if ( (int)me->query("combat_exp")<40000 )
		{
			command("say �㻹��ר����ưɣ�");
			return 1;
		}
                  if ( (int)me->query_skill("dodge",1)<50 )
		{
			command("say ����Ṧ���������ʺ������ֹ�����");
			return 1;
		}
	}
	
	if ( party && party["party_name"]==HIG "���ζ���" NOR )
	{
          if ( (int)me->query("combat_exp")<40000 )
		{
                          command("say ���ʵս����̫���ˣ�ȥ�˿�����Σ�գ�");
			return 1;
		}
          if ( (int)me->query_skill("dodge",1)<50 )
		{
			command("say ����Ṧ���������ʺ������ֹ�����");
			return 1;
		}
	}
	
        if ( me->query_temp("job_huaxin") )
        {
               command("faint "+me->query("name"));
               command("say ������������ӣ����������㾹Ȼ��ȥϴ�裡\n");
               message_vision("$N����һ˫�������Ĵ��۾����޹�������$n��\n",me,this_object());
               me->delete_temp("job_start");
               me->delete_temp("job_huaxin");
               me->apply_condition("job_nodo",50);
               return 1;
               }
	if ( me->query_temp("job_failed") )
	{
		command("poor "+me->query("id"));
		command("say �㻹������������ɣ�����ְѹ��������ˡ�");
             me->delete_temp("job_failed");
             me->delete_temp("job_start");
		return 1;
	}
	
	if (me->query_condition("job_nodo") > 0)
	{
		command("say ���ڲ���Ҫ��ȥ��,�㻹�ǳ����ʱ����������ɡ�");
       me->delete_temp("job_start");
       me->delete_temp("job_failed");
		return 1;
	}

	if ( me->query_temp("job_start") && !(me->query_temp("job_ok")) )
	{
		command("hmm");
		command("say ���Ѿ��й����ˡ�������ȥ����");
		return 1;
	}
	
	if (me->query_temp("job_ok") ==1 )
	{
		command("say �úã��ɵĺã�����ȥЪЪ�ɡ�");
                me->add("potential", 120+random(100));
               me->add("combat_exp", 150+random(120));
		me->delete_temp("job_start");
		me->delete_temp("job_ok");
                me->delete("duishou");
		me->delete_temp("where");
                me->apply_condition("job_nodo",0);
                 me->add("shen",50);
       me->delete_temp("job_failed");
                 if (party) {
                       party["tasks"]=party["tasks"]+2;
                        me->set("party",party);
                 }
		return 1;
	}
	
	command("say ���������ã���˵" + quest["opp_name"] + "��" + quest["quest_env"] + quest["quest_thing"]+"����ȥ̽��һ���鱨��");
	command("say С�ģ�����" + quest["opp_name"] + "���ӷ����ˡ�");

	me->set_temp("job_start",1);
        me->set("duishou", quest["opp_name"]);
	me->set_temp("where", quest["file_name"]);
        me->apply_condition("job_nodo",0);
	
          call_out("do_datan",25, me);

	return 1;
}

void do_datan(object me)
{
	object where;
        object ob;

	where = environment(me);

	if (file_name(where)==me->query_temp("where"))
	{
                if (!objectp(present("dizi",where)))
                {
                ob=new("/d/chengdu/npc/tufei");
                ob->set_name(me->query("duishou")+"����",({"dizi"}));
                ob->move(where);
                }
                message_vision("$N������"+me->query("duishou")+"�������˹�������æ����ͷȥ��\n"NOR, me);
                message_vision(HIC"$N���Ӿ�����ס��������ʼע��"+me->query("duishou")+"���ӵ����о�ֹ��\n"NOR, me);
              me->apply_condition("fmquest",5);
	}
       else 
	{
                  message_vision("\n$N�Ĵ���������Ȼ��û����ָ���ص㣬�������ˡ�\n", me);
		me->set_temp("job_failed",1);
               me->apply_condition("job_nodo",30);
	}
	return;
}

