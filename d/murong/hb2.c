// hb2.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",GRN"����"NOR);
         set("long",
"�׻�˵��"+BLINK HIC+"��������, �����պ�"+NOR+"���������Ǵ��������"+BLINK HIM+"̫��"+NOR+"�������̲���\n"
"Ư��һҶҶ��"+BLINK HIW+"С��"+NOR+", һ�����ö���С�������ź��ϵ���粻ʱƯ����Ķ��С�\n"
);
         set("outdoors","����Ľ��");
         set("exits", ([
             "west" : __DIR__"hb1",
             "southeast" : __DIR__"sq",
]));
         setup();
}
void init()
{
	object me = this_player();
	object weapon;
	if( me->query_temp("is_suiciding") 
      	&& me->query("combat_exp") > 300000
	&& me->query("family/generation") == 3
       	&& me->query("family/family_name") == "����Ľ��" 
        && me->query("jifen")
     	&& me->query("ketou")
	&& !me->query("marry")
        && !me->query("meet_mrb")
        && objectp(weapon=me->query_temp("weapon") )
        && weapon)
        {                        
        message_vision("ͻȻ�ƿ���������һ��������ʮ�����������ײ��$N����"+weapon->query("name")+"��
�һ���죬$N����"+weapon->query("name")+"���ֶ�����������������Ѫ��������Ȼ���ѡ�\n", me);
	weapon->move(environment(me));
	remove_call_out("meet_bo");
	call_out("meet_bo", 2, me);       
	return;
	}            
	call_out("check", 1, me);
}
void check()
{
	object me = this_player();
	if( me->query_temp("is_suiciding"))
	{
		me->move(__FILE__);
		remove_call_out("check");
	}
	else call_out("check", 1, me);
	return;
}	
	
void meet_bo()
{
	object me = this_player();
	tell_object(me, "��ֻ���ý���һ�գ���һ���������ɮ���ץ��\n");
	message("vision", me->name()+"ֻ���ý���һ�գ���һ������ɮ���ץ����ɮ������ɣ�һ���̲����ˡ�\n", environment(me), ({me}));
	me->set_temp("mrb_see", 1);
	me->move(__DIR__"liulin1");
	return;
}

/*void init()
{
	 object me = this_player();
	 int luck = (int)me->query_temp("mrb_meet");
	 me->add("jingli", -10);
	 if( (int)me->query("mrb_fail", 1) < 5 ) 
	 {
         	if( me->query("combat_exp") > 300000
	         && me->query("family/generation") == 3
        	 && me->query("family/family_name") == "����Ľ��" 
	         && me->query("jifen")
        	 && me->query("ketou")
	         && !me->query("marry")
        	 && luck < 1
	         && !me->query("meet_mrb")
        	 && random(5) < 2)
	         {
        	 	write("��ͻȻ���ú��������������ת��ͷ��ȴ����ʲôҲû�С�\n");
         		me->set_temp("mrb_meet", 1);
	         }   
         
        	 if (luck >= 1) 
	         {
        		  write("��ͻȻ���ú��������������ת��ͷ��ȴ����ʲôҲû�С�\n"); 
	        	  me->add_temp("mrb_meet", 1); 
                 }
	        
        	 if (luck >= 10) 
        	 {
          	 	  write("��������һ�˺ٺ���Ц�˼�����\n");
          		  message_vision("\n$N��ͻ��������Ц��һ������ͷ�㷢��񱼡�\n",me);         
          		  me->delete_temp("mrb_meet");
          		  me->set_temp("mrb_meet1", 1); 
          		  call_out("wait", 10, me);         
        	 }                                        
	}
}

void wait()
{
        object me;
        int total, try;
        me = this_player();
        total = (int)me->query("int")+(int)me->query("kar");
        try = me->query("mrb_fail");
        if(total > 40)
        {
        	message_vision("$N�ŵĻ���ֻ����£�ֻ�÷���񱼡�\n",me);
	        me->set_temp("mrb_see", 1); 
        	me->delete_temp("mrb_meet1");
	        me->move(__DIR__"liulin1");
        	return;
        }
        else 
        {
        	if(!try) 
        	{
                	me->set("mrb_fail", 1);    
	                message_vision(HIR"$N����ͻȻһ����µµ�ع�������ʮ�ɣ�\n"NOR,me);
        	        me->delete_temp("mrb_meet1");     
                	me->move(__DIR__"hb");
	                me->receive_wound("qi", 100);
        	        tell_room(environment(me), HIR + me->name()+"��µµ�ع��˹��������ڵ��ϰ�������������\n" NOR,({ me }));    
	                return;
                }
        	else 
        	{
                	me->add("mrb_fail", 1);    
	                message_vision(HIR"$N����ͻȻһ����µµ�ع�������ʮ�ɣ�\n"NOR,me);
        	        me->delete_temp("mrb_meet1");     
                	me->move(__DIR__"hb");
	                me->receive_wound("qi", 100);
        	        tell_room(environment(me), HIR + me->name()+"��µµ�ع��˹��������ڵ��ϰ�������������\n" NOR,({ me }));        
	                return;
                }     
        }
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("mrb_meet1") && dir == "west")
                return notify_fail("��������һ���죬һ����Ӱ����ͷ��Ծ������������ǰ��\n");
        return ::valid_leave(me, dir);
}
*/