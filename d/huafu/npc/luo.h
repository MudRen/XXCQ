int ask_kungfu()
{
           object me;
           mapping myparty;
           mapping myfam;
           int skills;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");
           skills=me->query_skill("chixin-jian",1);

           if ( (!myfam || myfam["family_name"]!="���ζ���") && (!myparty || myparty["party_name"]!=HIG"���ζ���"NOR) )
           {
                   command("say ���뱾�ź��޹ϸ𣬴˻��Ӻ�̸��");
                   return 1;
           }

           if ( me->query_temp("kungfu_asked1") )
           {
                command("hmm");
                command("say ���׾�ѧ��ֻ��һ�飬ѧ�����Ϳ����Լ����컯�ˡ�");
                return 1;
           }

            if (myfam && myfam["family_name"]=="���ζ���")
{
           if ( me->query("combat_exp")<80000)
           {
                command("say ���ʵս����̫�ͣ�ѧ�����ҵľ�ѧ��");
                return 1;
           }
             if ( me->query_skill("sword",1)<80)
           {
                command("say ��Ľ�����Ƿ���ѧ�����ҵľ�ѧ��");
                return 1;
           }
           if ( me->query("max_neili")<200)
           {
                command("say �����������̫�ѧ�����ҵľ�ѧ��");
                return 1;
           }

             if (skills>=this_object()->query_skill("chixin-jian",1))
             {
                       command("say ���Ѿ�ûʲô�ɽ̵�����");
                       return 1;
             }
             if ((skills*skills*skills/7)>me->query("combat_exp"))
             {
                       command("say ��ľ��鲻����˵����Ҳ��������");
                       return 1;
             }
            if (me->query("jingli")<20)
             {
                       command("say ��̫���ˣ���Ϣ��ɡ�");
                       return 1;
             }
                 
            me->improve_skill("chixin-jian",random(10*me->query("int")));
            tell_object(me,"��������ϼ�����һЩ���ڴ��Ľ������ʡ�\n");
            me->receive_damage("jingli",25-(me->query("int")/5));
            
            return 1;

           }
           
            if (myparty && myparty["party_name"]==HIG"���ζ���"NOR)
           {
                  if ( myparty["level"]<4 )
                  {
                       command("say ���׾�ѧ�Ҳ��ܽ��㣬�Բ���");
                       return 1;
                  }
             if ( me->query_skill("sword",1)<80)
                  {
                command("say ��Ľ�����Ƿ���ѧ�����ҵľ�ѧ��");
                       return 1;
                  }
                  if ( me->query("max_neili")<200 )
                  {
                       command("say ���������Ƿ���ѧ�����ҵľ�ѧ��");
                       return 1;
                  }
          command("say �ðɣ��㿴��ϸ�ˣ���ֻ����һ�顣");
           message_vision(HIY"$N�ڿ����ƣ���ԭ��ˣŪ�����ľ�ѧ����\n"NOR,this_object());
           if ( me->query("int")<18 )
           {
                  message_vision(YEL"$N���˰��죬�������ã�����������̫���ˣ����ղ��˾��衣\n"NOR,me);
                      me->set_temp("kungfu_asked1",1);
                     return 1;
           }
                 message_vision(HIC"$N���˰���,���������׾�ѧ�ľ��衣\n"NOR,me);
                      me->set_temp("kungfu_asked1",1);
                     me->set_skill("chixin-jian",1);
                     return 1;
           }

           return 0;
}

int ask_kungfu1()
{
           object me;
           mapping myparty;
           mapping myfam;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");

           if ( (!myfam || myfam["family_name"]!="���ζ���") && (!myparty || myparty["party_name"]!=HIG"���ζ���"NOR) )
           {
                   command("say ���뱾�ź��޹ϸ𣬴˻��Ӻ�̸��");
                   return 1;
           }
           
           command("smile");
           command("say �ұȽϾ�ͨ�����������������̽��������ʡ�");
           
           return 1;
           
}

int ask_kungfu2()
{
           object me;
           mapping myparty;
           mapping myfam;
           int skills;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");
            skills=(int)me->query_skill("sword",1);

           if ( (!myfam || myfam["family_name"]!="���ζ���") && (!myparty || myparty["party_name"]!=HIG"���ζ���"NOR) )
           {
                   command("say ���뱾�ź��޹ϸ𣬴˻��Ӻ�̸��");
                   return 1;
           }
           
             if (skills>=this_object()->query_skill("chixin-jian",1))
             {
                       command("say ���Ѿ�ûʲô�ɽ̵�����");
                       return 1;
             }

           if ((skills*skills*skills/7)>me->query("combat_exp"))
            {
                      command("say ��ľ��鲻����˵����Ҳ��������");
                      return 1;
            }
           if (me->query("jingli")<20)
            {
                      command("say ��̫���ˣ���Ϣ��ɡ�");
                      return 1;
            }
                
           me->improve_skill("sword",random(10*me->query("int")));
           tell_object(me,CYN"��������ϼ�����һЩ���ڽ��������ʡ�\n"NOR);
          me->receive_damage("jingli",25-(me->query("int")/5));
           
           return 1;
           
}

