
int accept_object(object who, object ob)
{
        object sil;

        int i;
        if ((string)ob->query("id") == "shi tou")
        {
                if (!(who->query_temp("job_start")))
                {
                        command("say ��û����ȥ������ȴȥ��æ���������������ĺ��˲��డ��");
                        who->add("potential", 1+random(10));
                        who->add("combat_exp", 3+random(10));
                        who->delete_temp("find");
                        return 1;
                }
                else
                {
                        command("say ��л����л�������ˣ���ȥ��Ϣ��Ϣ�ɡ�");
                        who->delete_temp("job_start");
                        who->delete_temp("find");
                        who->add("potential", 50+random(50));
                        who->add("combat_exp", 75+random(75));
                        for (i=1;i<11;i++)
                        {
                        sil = new("/clone/money/silver");
                        sil->move(who);
                        }
                        if (!(who->query("xiaojob")))
                        who->set("xiaojob",1);
                        else who->add("xiaojob",1);
                        return 1;
                }
        }
       else
        {
                command("say ����������ʲô?");
                return 0;
        }
        
}


