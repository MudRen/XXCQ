int ask_job()
{
        object me;
         object ob,killer;
        mapping myfam,quest;
        me=this_player();

        myfam=(mapping)me->query("family");
        quest = "/d/longmen/xuehepai/quest/xhquest"->query_quest();
            killer=me->query_temp("last_damage_from");
        
        if (  !myfam || myfam["family_name"]!="Ѫ����" ) 
        {
                command("say ���뱾�ɺ��޹�ϵ�������²�����������");
                return 1;
        }
        
        if ( myfam && myfam["family_name"]=="Ѫ����" )
        {
                if ( (int)me->query("combat_exp")<300000 )
                {
                        command("say ���ֹ����������죬�Ҳ�����������");
                        return 1;
                }
        }
        
        if ( me->query_temp("jobfailed") )
        {
                command("poor "+me->query("id"));
                command("say �㻹������������ɣ�����ְѹ��������ˡ�");
                me->delete_temp("jobfailed");
                me->delete_temp("jobstart");
                me->apply_condition("job_nodo",20);
                me->delete_temp("followed");
                return 1;
        }
        
        if ( me->query_temp("job-fail") )
        {
                command("sigh "+me->query("id"));
                command("say �ⲻ����Ĺ����ٸ���һ�λ���ɡ�");
                me->delete_temp("job-fail");
                me->delete_temp("jobstart");
                return 1;
        }

        if (me->query_condition("job_nodo") > 0)
        {
                command("say ���ڲ���Ҫ��ȥ��,�㻹�ǳ����ʱ����������ɡ�");
                return 1;
        }

        if ( me->query_temp("jobstart") && !(me->query_temp("jobok") && killer->query("id")!="sha shou"))
        {
                command("hmm");
                command("say ���Ѿ��й����ˡ�������ȥ����");
                return 1;
        }
        
        if (me->query_temp("jobok") ==1 )
        {
                command("say �úã��ɵĺã�����ȥЪЪ�ɡ�");
                me->add("potential", 80+random(80));
                me->add("combat_exp", 120+random(110));
               me->delete_temp("jobstart");
            me->add("kill",50);
               me->delete_temp("jobok");
                 me->delete_temp("begin");
                me->delete_temp("duishou");
                me->delete_temp("where");
                me->delete_temp("where1");
                me->delete_temp("followed");
                return 1;
        }
        
        command("say ���������ã���˵" + quest["opp_name"] + "������" + quest["file_env"] + "\n׷ɱ�����ɵ��ӣ���Ͽ�ȥԮ�ȣ����ǻ���"+quest["mudi_env"]+"��Ӧ���ǡ�");

        me->set_temp("jobstart",1);
        me->set_temp("duishou", quest["opp_name"]);
        me->set_temp("where", quest["file_name"]);
        me->set_temp("where1", quest["mudi_name"]);     
        ob=new("/kungfu/class/xuehepai/dizi");
        ob->set_name("Ѫ���ɵ���",({"di zi","zi"}));
        ob->set_skill("dodge",me->query_skill("dodge",1)/10);
            ob->set("followid",me->query("id"));
        ob->move(quest["file_name"]);
        remove_call_out("do_datan");
        call_out("do_datan",40, me);

        return 1;
}

void do_datan(object me)
{
        object where,ob,obb;

        me=this_player();
        where = environment(me);

       if (me->query_temp("begin") || me->query_temp("jobok"))
                    return;
        if (file_name(where)==me->query_temp("where"))
        {
                if (!(present("di zi",where)))
                {
                        tell_object(me,HIC"�����һ�ᣬû����Ӱ�����ܵ����Ѿ������ɱ�ˡ�\n"NOR);     
                        me->set_temp("job-fail",1);
                        me->delete_temp("jobstart");                    
                        return;
                }
        }
        else
        {
                tell_object(me,HIC"��ô���㻹û�ϵ��������Ѿ��������ˡ�\n"NOR);
                ob=find_object(me->query_temp("where")+".c");
                if (obb=present("dizi",ob)) 
                {
                        tell_room(ob,HIG"ͻȻɱ������"+me->query_temp("duishou")+"���Ӷ���"+obb->query("name")+"�Ϳ�һ��\nȻ����Ĵ�ɢ���������ˡ�\n");
                        obb->die();
                }
                me->set_temp("jobfailed",1);
                me->apply_condition("job_nodo",20);
                me->delete_temp("jobstart");
                return;
        }
        return;
}


