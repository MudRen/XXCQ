 int recognize_apprentice(object ob)
 {
     if (ob->query("party/party_name")!= "Ȩ����")
     {
     message_vision("$Nҡ��ҡͷ��\n",this_object());
     command("say "+ob->query("id")+"����Ȩ������Ҳ��̡�\n");
     return 0;
     }
        if(ob->query("party/tasks") < this_object()->query("accept"))
          {
          command("say ����Ȩ���Ｖ�𻹲���,ȥ��������ʦ��!\n");
          return 0;
          }
           if(ob->query("shen") > 0)
             {
               command("say ����ô����������ʿ����Щ�߿�����Ȼ��ɱ����!\n");
               return 0;
          }
     return 1;
 }
      
