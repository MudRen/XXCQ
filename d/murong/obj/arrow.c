// arrow.c ����
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIY"����"NOR, ({ "gongjian" }));
        set_weight(2000);		                      	
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"����һ�Ѵ�˵�еĴ�����������õĹ�����\n"NOR);
		set("value", 50000);
                set("material", "iron");            
	}
        setup();
}

void init()
{
	add_action("do_aim", "aim");
	add_action("do_shoot", "shoot");
}

int do_aim(string arg)
{                        
	int i;
	object me, ob, room, *obj;
	me = this_player();
	ob = this_object();
	room = find_object("/d/murong/boat1");
	obj = all_inventory(room);
	if(!living(me))
		return 0;
	if(!arg || arg == "" || arg != "boat")
		return notify_fail("��Ҫ��׼ʲô��\n");
	if(!present(ob, me))
		return 0;                                      
	
	if( arg == "boat" )                
	{                                              
		if(!(room=find_object("/d/murong/boat1")))
		     room=load_object("/d/murong/boat1");
		if( room->query("busy"))
		{
			message_vision("$N���������������ڹ����Ѽ�������������׼�˺����ϵ�С����\n", me);
		}
		message_vision("$N���������������ڹ����Ѽ�����������\n", me);	
		me->set_temp("aim_target", 1);		
		return 1;		
	}
}		                                      

int do_shoot(string arg)
{                                 
	int i;
	object me, ob, room, *obj, obb;
	me = this_player();
	ob = this_object();
	room = find_object("/d/murong/boat1");
	obj = deep_inventory(room);         

	if(!living(me))
		return 0;
	if(!arg || arg == "" || arg != "boat")
		return notify_fail("��Ҫ��ʲô�ط����䣿\n");
	if(!present(ob, me))
		return 0;                                      
	if(!me->query_temp("aim_target"))
		return notify_fail("�㻹û����׼�ء�\n");	
	if( arg == "boat" )
	{                	
		if(!(room=find_object("/d/murong/boat1")))
	     	     room=load_object("/d/murong/boat1");      
	     	if( room->query("busy"))
	     	{       
	     		if( objectp(obb=present("arrow", me)) && obb->query_amount()>0 )
	     		{
	        		for(i=0; i<sizeof(obj); i++)
                		{
	                		if(obj[i]->is_character() && living(obj[i]) && !wizardp(obj[i]))
		        		{        
		                		message_vision("$N�Ӵ�����ȡ��һ֧���������ϣ�ͻȻһ���֣�һֻ���ҵļ����ź����ϵ�С����ȥ��\n", me);
		                		message_vision(HIY"HEHE"NOR, room);
		          		      	call_out("wait", 2, room);
		                		return 1;
		                	}
		                	else 
		                	{
		                		message_vision("$N�Ӵ�����ȡ��һ֧���������ϣ�ͻȻһ���֣�һֻ���ҵļ����ź����ϵ�С����ȥ��\n", me);
		                		call_out("fail", 2, me);
		                		return 1;
		                	}
		                }	
		        }
		        else 
		        {
		        	write("��ͻȻ�����������Ѿ�û�м��ˡ�\n");        
		        	return 1;
		        }
		 }
		 else
		 {
		 	write("���������۾���ͻȻ����С���ﲢû���ˡ�\n");
		 	return 1;
		 }
	}
}                