void init()
{
        object ob;
        object me=this_player();
        mapping fam=(mapping)me->query("family");
        
        if (interactive(me))
        {
                if (fam && fam["family_name"]=="Ѫ����")
                {
                        if (me->query("combat_exp")>40000 && me->query("combat_exp")< 100000)
                        {
                                if (me->query("yiasked"))
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat �����ڴ�����������"+me->query("name")+"һ����Ѫ�£���֮����!");
                                command("say ���һ�����Ѫ�����պã����������ڱ��ɵĵ�λ��");
                                ob=new("/d/longmen/xuehepai/obj/cloth2");
                                ob->move(me);
                                me->set("cloth","/d/longmen/xuehepai/obj/cloth2");
                                me->set("yiasked",1);
                                return;
                        }
                        
                        if (me->query("combat_exp")>100000 && me->query("combat_exp")< 300000)
                        {
                                if (me->query("twoasked"))
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat �����ڴ�����������"+me->query("name")+"������Ѫ�£���֮����!");
                                command("say ����������Ѫ�����պã����������ڱ��ɵĵ�λ��");
                                ob=new("/d/longmen/xuehepai/obj/cloth3");
                                ob->move(me);
                                me->set("cloth","/d/longmen/xuehepai/obj/cloth3");
                                 me->set("twoasked",1);
                                return;
                        }                
                        if (me->query("combat_exp")>300000 && me->query("combat_exp")< 500000)
                        {
                                if (me->query("threeasked"))
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat �����ڴ�����������"+me->query("name")+"������Ѫ�£���֮����!");
                                command("say ����������Ѫ�����պã����������ڱ��ɵĵ�λ��");
                                ob=new("/d/longmen/xuehepai/obj/cloth4");
                                ob->move(me);
                                me->set("cloth","/d/longmen/xuehepai/obj/cloth4");
                                me->set("threeasked",1);
                                return;
                        }                
                        if (me->query("combat_exp")>500000 && me->query("combat_exp")< 800000)
                        {
                                if (me->query("fourasked"))
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat �����ڴ�����������"+me->query("name")+"�ĵ���Ѫ�£���֮����!");
                                command("say ����ĵ����Ѫ�����պã����������ڱ��ɵĵ�λ��");
                                ob=new("/d/longmen/xuehepai/obj/cloth5");
                                ob->move(me);
                                me->set("cloth","/d/longmen/xuehepai/obj/cloth5");
                                me->set("fourasked",1);
                                return;
                        }                
                }
        }
}

