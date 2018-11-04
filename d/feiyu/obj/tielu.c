// Item tielu.c  
// Modified by Atlus Oct.14.1999
// 

inherit ITEM;

void create()
{
        set_name( "¯��",({ "lu zi"}));
        set_weight(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��¯�ӡ�\n");
                set("value", 50);
                set("material", "iron");
        }
}

void init()
{
        add_action("do_ran","ran");
        add_action("do_da","da");
        add_action("do_fang","fang");
        add_action("do_la","la");    
}

int do_la(string arg)
{  
        object me=this_player();

        if (!arg || arg!="����" ) {
               return notify_fail("��Ҫ��ʲô��\n");
       }
        
		if( (int)me->query("neili") > 100 )
	   {
		return notify_fail("������ȼ¯������?�α��˷������أ�\n");
        }

        if ( me->query_temp("fy_task_datie/ran"))
	    {
               return notify_fail("���¯���Ѿ�ȼ������\n");
		}
        
		me->add("qi", -50);
        message_vision("$N����������,ʹ¯�ӵ����˻�\n", me);
		me->set_temp("fy_task_datie/ran",1);
		return 1;

}

int do_ran(string arg)
{
		object me=this_player();

       if (!arg || arg!="lu zi" ) {
               return notify_fail("��Ҫȼʲô��\n");
       }

		if( (int)me->query("neili") < 100 )
	   {
		return notify_fail("�����ڵ��������㣡\n");
        }
		
		if ( me->query_temp("fy_task_datie/ran"))
	    {
               return notify_fail("���¯���Ѿ�ȼ������\n");
		}
		
		me->add("neili", -100);
        message_vision("$N��������¯�ӵ��\n", me);
		me->set_temp("fy_task_datie/ran",1);
		return 1;

}
int do_da(string arg)
{
		object me=this_player();
		object ob;

       if (!arg || arg!="����" ) {
               return notify_fail("��Ҫ��ʲô��\n");
       }

		if (!me->query_temp("fy_task_datie/given_hammer") )
		{
                message_vision("��$N�ȵ����Ϸ�ȥ�������������!\n",me);
                return 1;
		}
		if  ( !present("hammer", this_player()))
        {
		     message_vision("��$N��ȥ�������������!\n",me);
			 return 1;
	    }
		if ( me->query_temp("fy_task_datie/done"))
		{
               return notify_fail("��������Ѿ�����ˡ�\n");
		}
		
		if ( !me->query_temp("fy_task_datie/ran"))
		{
               return notify_fail("¯��û��������,��ô�ܴ���?\n");
		}

		if ( me->query_temp("fy_task_datie/has_put"))
		{
               return notify_fail("���Ѿ�������Ž�¯ȥ�ˡ�\n");
		}
        if (me->query("qi")<20)
               return notify_fail("������̫���ˣ���Ϣһ��������!\n");

		if ( !me->query_temp("fy_task_datie/hot"))
		{
               return notify_fail("���黹�ǲ����ȣ���ô��?\n");
		}

		if ( (time()-me->query_temp("fy_task_datie/tiere_time") ) > 20)
		{
				me->delete_temp("fy_task_datie/hot");
			   return notify_fail("�������������ˣ���Ҫ�ټ���һ�¡�\n");
		}

		if ( me->query_temp("fy_task_datie/da_time")<=0 )
		{
			message_vision("$N����������,�Ƴ���һ������!\n", me);
			me->set_temp("fy_task_datie/done",1);
			ob=new(__DIR__"wuqi");
			ob->move(me);
			return 1;
		}
		me->add("qi", (-1)*( random(10) + 10) );
		message_vision("$N��������,һ�´����պ��������.\n", me);

		if ( random(10) +me->query("str") > 25 )
		{
			message_vision("$N���������������״\n", me);
			me->add_temp("fy_task_datie/da_time",-1);
		} else 
		message_vision("$N�����������,ֻ���ټ����ش�!\n", me);
		return 1;

}
int do_fang (string arg)
{
		object me=this_player();

		if ( !me->query_temp("fy_task_datie/ran"))
		{
               return notify_fail("¯��û���ȣ��Ž�ȥ��ʲô�á�\n");
		}

	   if (!arg || arg!="����" ) {
               return notify_fail("��Ҫ��ʲô��\n");
       }

		if ( me->query_temp("fy_task_datie/hot"))
		{
               return notify_fail("������黹���ȵ�,������ȡ�\n");
		}
	
		if ( me->query_temp("fy_task_datie/has_put"))
		{
               return notify_fail("���Ѿ�������Ž�ȥ�ˡ�\n");
		}

        message_vision("$N���������¯���м��ȡ�\n", me);
		me->set_temp("fy_task_datie/has_put",1);
		call_out("hot_ok", 10);
		return 1;
}
int hot_ok()
{
		object tiekuai;
		object me=this_player();
		tiekuai=new(__DIR__"tiekuai");

		message_vision("������һ���������$N��ǰ��\n", me);
		me->set_temp("fy_task_datie/hot",1);
        me->set_temp("fy_task_datie/tiere_time",time());
        me->delete_temp("fy_task_datie/has_put");
		return 1;
}
