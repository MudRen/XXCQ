int ask_job()
{
        object me;
          mapping myfam;

        me=this_player();
        myfam=(mapping)me->query("family");
        
        if (  !myfam || myfam["family_name"]!="Ѫ����"  )
        {
                command("say ���뱾�ɺ��޹�ϵ�������²�����������");
                return 1;
        }
        
        if ( (int)me->query("combat_exp")<40000 )
        {
                command("say �����컹��Ҫ���æ,������ȥ�ɣ�");
                return 1;
        }
              if (me->query("combat_exp")>300000)
             {
                  command("say ���Ѿ�С�������ˣ��ܴ󱯻�����µ��������ġ�");
                    return 1;
             }

        if ( me->query_temp("xhjob_failed") )
        {
                command("poor "+me->query("id"));
                command("say �㻹������������ɣ�����ְѹ��������ˡ�");
                        me->delete_temp("xhjob_start");
                        me->delete_temp("xhjob_failed");
                return 1;
        }
        
        if (me->query_condition("job_nodo") > 0)
        {
                command("say ���ڲ���Ҫ��ȥ��,�㻹�ǳ����ʱ����������ɡ�");
                return 1;
        }

        if ( me->query_temp("xhjob_start") && !(me->query_temp("xhjob_ok")) )
        {
                command("hmm");
                command("say ���Ѿ��й����ˡ�������ȥ����");
                return 1;
        }
        
        if (me->query_temp("xhjob_ok") ==1 )
        {
                command("say �úã��ɵĺã�����ȥЪЪ�ɡ�");
                me->add("potential", 100+random(80));
                me->add("combat_exp", 120+random(100));
                me->delete_temp("xhjob_start");
                me->add("kill",20);
                me->delete_temp("xhjob_ok");
                return 1;
        }
        
        command("say ���������ã���˵�����ڹؿ���æ�������ˣ���ȥ�������");
        command("say ע�⣬���ý�����ʿ�����ˡ�");
        command("say ������һ����֮�ڸϵ�����ȥ��");
        
        me->set_temp("xhjob_start",1);
        me->set_temp("where","/d/longmen/guanka");
        
        call_out("do_goto", 60, me);

        return 1;
}

void do_goto(object me)
{
        object where;

        where = environment(me);

        if ((file_name(where)==me->query_temp("where")) || (file_name(where)=="/d/longmen/guanka1"))
        {
                if (!(me->query_temp("shouwei")))  {
                tell_object(me,HIC"��Ӧ�ÿ�ʼ����(shouwei)�ˡ�\n"NOR);
                }
                return;
        }
        else
        {
                tell_object(me,"\n����Ȼû����һ����֮�ڸϵ�Ŀ�ĵأ�����ʧ�ܡ�\n");
                me->set_temp("xhjob_failed",1);
                  me->apply_condition("job_nodo",30);
        }
        return;
}

