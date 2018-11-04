// yizhan.c

// Changed by Rest 99.10.15

inherit ROOM;



void init()

{

        add_action("do_gu", "gu");

	add_action("do_qu", "qu");
 
}



void check_trigger(object me)

{

	object room, where;

        where = environment(me);

	if( !(room = find_object("/clone/room/mache")) )

		room = load_object("/clone/room/mache");

	if( room = find_object("/clone/room/mache") )

	{

		if((int)room->query("che_trigger")==0)

		{

                  	message_vision("С���߽�һ��������ඣ�������δ�䣬С���Ѿ�ǣ��һ����ƥ�������ת�˳�����\n", me);

			message_vision("С��Ц��˵�������Ǻ�����������վ�ոտ��ţ���Ѵ�������˵ȥ�ľ�����(type qu XXX)��\n", me);

                        message_vision("С��˵����������������(bl)����(hy)��ɽ(ss)����(lm)���з�վ�������Թͳ������\n\n", me);

			me->set_temp("guche", 1);

                 }        

               	else if(where->query("short")==room->query_temp("envname"))

                    {

                     message_vision("С��Ǹ���˵��������û����,�������Ѿ��������ˣ������Ȼ���ɡ���\n",me);

                    }

             else

             {

		message_vision("С������Ǹ���˵������λ�͹٣����ڳ�����ȥ��,���Ȼ����?��\n", me);

             }

        }

        else

            message("vision", "ERROR: che not found\n", this_object() );

}


int do_gu(string arg)

{

	object me;

	me = this_player();



	if(!arg || arg != "che")

		return notify_fail("��Ҫ��ʲô������ֻ����(che)���Թ͡�\n");

	

	message_vision("$N�����Ű壬�е���ι�������𣿹ͳ�������\n", me);

        check_trigger(me);

        return 1;

}



int do_qu(string arg, int num)

{

	object room, me,where;

        string startname;

        me = this_player();

        where = environment(me);

        startname = where->query("short");

        switch(startname)

        {

         case "������վ": startname = "/d/huayang/hyyizhan";

                          break;

         case "������վ": startname = "/d/bianliang/blyizhan";

                          break;

         case "��ɽ��վ": startname = "/d/shaolin/ssyizhan";

                          break;

         case "������վ": startname = "/d/longmen/lmyizhan";

                          break;



        }   

        	



	if (!me->query_temp("guche"))

		return notify_fail("����û�������㣬������Լ���ɵ��\n");



	if (!arg)

		return notify_fail("�㵹��˵ȥ��ѽ��\n");



        if ( where->query("short") == "������վ")

           {

            if(arg == "hy" || arg == "huayang")

              return notify_fail("�����ڲ�����������\n");

           }

        else if ( where->query("short") == "������վ")

           {

            if(arg == "bl" || arg == "bianliang")

              return notify_fail("�����ڲ�����������\n");

           }

        else if ( where->query("short") == "������վ")

           {

            if(arg == "lm" || arg == "longmen")

              return notify_fail("�����ڲ�����������\n");

           }

        else if ( where->query("short") == "��ɽ��վ")

           {

            if(arg == "ss" || arg == "songshan")

              return notify_fail("�����ڲ�����������\n");

           }



	if( !(room = find_object("/clone/room/mache")) )

		room = load_object("/clone/room/mache");



        if( room->query("che_trigger"))

             {

                message_vision("С����$N����Ǹ���˵������λ�͹٣����ڳ�����ȥ��,���Ȼ����?��\n", me);

                return 1;

             }

        else if(where->query("short")==room->query_temp("envname"))

              {

                     message_vision("С��Ǹ���˵��������û���ˣ��������Ѿ��������ˣ������Ȼ���ɡ���\n",me);

              }

       else

       {

	if( room = find_object("/clone/room/mache") )

	{

           if(!room->query_temp("mached"))

             {

                

                if ( arg == "huayang" || arg == "hy" )

		{

			message_vision("$N���������������˵����ȥ�����ء���\n\n", me);

			message_vision("���Ц��˵�������õĿ͹٣����Ͼ���·����\n\n", me);

			me->set_temp("mache", "huayang");

                        room->set_temp("envname","������վ");

                        room->set_temp("mached","huayang");

                        room->set_temp("wherename","������");

                        room->set_temp("machedshort","hy");

		}

                else if ( arg == "longmen" || arg == "lm" )

                {

                        message_vision("$N���������������˵����ȥ�����򡣡�\n\n", me);

                        message_vision("���Ц��˵�������õĿ͹٣����Ͼ���·����\n\n", me);

                        me->set_temp("mache", "longmen");

                        room->set_temp("envname","������վ");

                        room->set_temp("mached","longmen");

                        room->set_temp("wherename","������");

                        room->set_temp("machedshort","lm");

                }

		else if ( arg == "bianliang" || arg == "bl" )

		{

			message_vision("$N���������������˵����ȥ�����ǡ���\n\n", me);

			message_vision("���Ц��˵�������õĿ͹٣����Ͼ���·����\n\n", me);

			me->set_temp("mache", "bianliang");

                        room->set_temp("mached","bianliang");

                        room->set_temp("envname","������վ");

                        room->set_temp("wherename","������");

                        room->set_temp("machedshort","bl");

		}

		else if ( arg == "songshan" || arg == "ss" )

		{

			message_vision("$N���������������˵����ȥ��ɽ����\n\n", me);

			message_vision("���Ц��˵�������õĿ͹٣����Ͼ���·����\n\n", me);

			me->set_temp("mache", "songshan");

                        room->set_temp("envname","��ɽ��վ");

                        room->set_temp("mached","songshan");

                        room->set_temp("wherename","��ɽ");

                        room->set_temp("machedshort","ss");

		}

		else

		{

                       message_vision("����Ǹ��Ц��Ц����������վֻ������(bl)����(hy)��ɽ(ss)�����ļ���վ���汧Ǹ��\n", me);

			return 1;

		}

                call_out("leave", 10, me);

                me->set_temp("startid",startname);

		me->move("/clone/room/mache");

		return 1;

             }

           else

            {

              if(arg == "huayang" || "hy" || "bianliang" || "bl" || "songshan" || "ss" || "longmen" || "lm")

              {

               if(arg == (string)room->query_temp("mached") || arg == (string)room->query_temp("machedshort"))

                {

                message_vision("$N���������������˵����ȥ" + room->query_temp("wherename") + "����\n\n", me);

		message_vision("���Ц��˵���������ó���Ŀ͹�ҲҪȥ" + room->query_temp("wherename") + "�����Ǿ�һ���߰ɣ������Ͼ���·����\n\n", me);

                me->set_temp("mache", room->query_temp("mached"));

                me->move("/clone/room/mache");

                message("vision",me->name() + "���������������˵����ȥ" + room->query_temp("wherename") + "����\n\n", environment(me),({me}));

		message("vision","���Ц��˵���������ó���Ŀ͹�ҲҪȥ" + room->query_temp("wherename") + "�����Ǿ�һ���߰ɣ������Ͼ���·����\n\n", environment(me),({me}));

                return 1;

                }

               else

                {

                 message_vision("����$NǸ���˵�����Բ�����λ�͹٣�����Ŀ͹�Ҫȥ" + room->query_temp("wherename") + ",���Ȼ��ȥ�����������һ�Ȱɡ���\n\n",me);

                 return 1;

                }

               }

             else

               {

                       message_vision("����Ǹ��Ц��Ц����������վֻ������(bl)����(hy)��ɽ(ss)�����ļ���վ���汧Ǹ��\n", me);

		return 1;

               }

                

            }

	}

   }

}



int leave(object me)

{

   object room;

   remove_call_out("leave");

   if( !(room = find_object("/clone/room/mache")) )

		room = load_object("/clone/room/mache");

             if ( (string)me->query_temp("mache") == "huayang")

		{                           

			message_vision("�������������˳���һ����ӣ���ඣ�ȥ������ඣ�\n\n",me);

			message_vision("��һ�ᣬ������ʧ�������⡣\n\n",me);

			me->set_temp("mache", "huayang");

                        me->set_temp("block_msg/all",1);

                        me->move(me->query_temp("startid"));

                        me->delete_temp("block_msg/all",1);

                        message("vision","�������������˳���һ����ӣ���ඣ�ȥ������ඣ�\n\n",environment(me),({me}));

			message("vision","��һ�ᣬ������ʧ�������⡣\n\n",environment(me),({me}));       

		}

             else if ( (string)me->query_temp("mache") == "longmen")

                {                           

                        message_vision("�������������˳���һ����ӣ���ඣ�ȥ������ඣ�\n\n",me);

                        message_vision("��һ�ᣬ������ʧ�������⡣\n\n",me);

                        me->set_temp("mache", "longmen");

                        me->set_temp("block_msg/all",1);

                        me->move(me->query_temp("startid"));

                        me->delete_temp("block_msg/all",1);

                        message("vision","�������������˳���һ����ӣ���ඣ�ȥ������ඣ�\n\n",environment(me),({me}));

                        message("vision","��һ�ᣬ������ʧ�������⡣\n\n",environment(me),({me}));       

                }


		else if ( (string)me->query_temp("mache") == "bianliang")

		{

			message_vision("�������������˳���һ����ӣ���ඣ�ȥ������ඣ�\n\n", me);

			message_vision("��һ�ᣬ������ʧ�������⡣\n\n", me);

			me->set_temp("mache", "bianliang");

                        me->set_temp("block_msg/all",1);

                        me->move(me->query_temp("startid"));

                        me->delete_temp("block_msg/all",1);

                        message("vision","�������������˳���һ����ӣ���ඣ�ȥ������ඣ�\n\n",environment(me),({me}));

			message("vision","��һ�ᣬ������ʧ�������⡣\n\n",environment(me),({me}));  

		}

		else if ( (string)me->query_temp("mache")== "songshan")

		{

			message_vision("�������������˳���һ����ӣ���ඣ�ȥ��ɽඣ�\n\n", me);

			message_vision("��һ�ᣬ������ʧ�������⡣\n\n", me);

			me->set_temp("mache", "songshan");

                        me->set_temp("block_msg/all",1);

                        me->move(me->query_temp("startid"));

                        me->delete_temp("block_msg/all",1);

                        message("vision","�������������˳���һ����ӣ���ඣ�ȥ������ඣ�\n\n",environment(me),({me}));

			message("vision","��һ�ᣬ������ʧ�������⡣\n\n",environment(me),({me}));  

		}

            call_out("arrived", 15,me);

            me->set_temp("block_msg/all",1);

            me->move("/clone/room/mache");

            me->delete_temp("block_msg/all",1);

            room->set("che_trigger", 1);

            room->delete_temp("mached");

            room->delete_temp("wherename");

            room->delete_temp("machedshort");

            return 1;



}







int arrived(object me)

{

        int i;

	object room, env, *inv;

        env = environment(me);

        inv = all_inventory(env);

	if( room = find_object("/clone/room/mache") )

	{

		if (me->query_temp("mache") == "huayang")

		{

		  for(i=0;i< sizeof(inv);i++)

                    {

                      if(inv[i]->is_character())

                      inv[i]->move("/d/huayang/hyyizhan");

                    }    

		}


                else if (me->query_temp("mache") == "longmen")

                {

                  for(i=0;i< sizeof(inv);i++)

                    {

                      if(inv[i]->is_character())

                      inv[i]->move("/d/longmen/lmyizhan");

                    }    

                }


		else if (me->query_temp("mache") == "bianliang")

		{

                    for(i=0;i< sizeof(inv);i++)

                          {

                            if(inv[i]->is_character())

                            inv[i]->move("/d/bianliang/blyizhan");

                           }    

		}

		else if (me->query_temp("mache") == "songshan")

                {

                    for(i=0;i< sizeof(inv);i++)

                          {

                            if(inv[i]->is_character())

                            inv[i]->move("/d/shaolin/ssyizhan");

                           }    

		}

		me->delete_temp("mache");

		me->delete_temp("guche");

                me->delete_temp("startid");

                message_vision("\n������ͣ������������߽�һ�������ˣ�\n\n", me);

		message_vision("��һͣ��$N����������������\n\n", me);

	        room->delete("che_trigger"); 

                room->delete_temp("envname");

		return 1;

	}

}



void reset()

{

    object room;



    ::reset();

    if( room = find_object("/clone/room/mache") )

        room->delete("che_trigger"); 

}




