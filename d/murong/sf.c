// shufang.c
#include <ansi.h>                   
#include <localtime.h>
inherit ROOM;

void create()
{
         set("short",HIW"�鷿"NOR);
         set ("long",@long
��������������鷿, �����书���������, ��������, �����ϱ���һ
������,����ȫ��һ���Ÿߴ����ܡ��ú�ѧϰ, �ؿɳ�Ϊһ�����֡�
long);
         set("exits",([
             "west" : __DIR__"houting",
]));
	setup();
}


void init()
{
        add_action("sit", "sit");
        add_action("zhuan", "zhuan");
        add_action("press", "press");
}


int sit(string arg)
{
	object me;
	me=this_player();
	
	if (!arg) return 0;
	if (me->is_busy()) return 0;
	if (me->is_fighting()) return 0; 
	if (arg !="chair") return 0;
	if (me->query_temp("marks/��1"))
			return notify_fail("���Ѿ����������ˡ�\n");
	if (arg=="chair")
	{
		write("�����������ϣ����������Եá�\n");
		tell_object(me, "�㷢����������һ��С���ء�\n");
		me->set_temp("marks/��1", 1);
		return 1;
	}
}
int zhuan(string arg)
{
	object me;
	me=this_player();                
	if (!arg) return 0;
	if (me->is_busy()) return 0;
	if (me->is_fighting()) return 0; 
	if (!me->query_temp("marks/��1")) return 0;	
	switch(arg)
	{                                                           
		case "��" :
		case "left" :
		write("��ѻ�����������һ�£������ֻص���ԭλ��\n");
		me->add_temp("push/left", 1);
		break;
		case "��" :
		case "right" :
		write("��ѻ�����������һ�£������ֻص���ԭλ��\n");
		me->add_temp("push/right", 1);			
		break;
		case "��" :
		case "up" :
		write("��ѻ�����������һ�£������ֻص���ԭλ��\n");
		me->add_temp("push/up", 1);			
		break;
		case "��" : 
		case "down" :
		write("��ѻ�����������һ�£������ֻص���ԭλ��\n");
		me->add_temp("push/down", 1);
		break;
		
		default : return notify_fail("ʲô��\n");
	}                                                
	return 1;
}
int press()
{
	mixed *ltime;
	int hour, min, i, j, k, l;	
	object me;
	me=this_player();                
	ltime = localtime(time());
	hour = ltime[LT_HOUR];	
	min = ltime[LT_MIN];     
	i = (int)me->query_temp("push/up");
	j = (int)me->query_temp("push/down");
	k = (int)me->query_temp("push/left");
	l = (int)me->query_temp("push/right");
	if( wizardp(me))
	{
		write(hour+"\n");
		write(i+"\n");   
		write(min+"\n");
		write(j+"\n");	
		write((min+hour)+"\n");
		write(k+"\n");	       
		write((min-hour)+"\n");
		write(l+"\n");		
	}
	if( !wizardp(me))
	{
            	me->delete_temp("marks/��1");
            	me->delete_temp("push/up");
            	me->delete_temp("push/down");
            	me->delete_temp("push/right");
            	me->delete_temp("push/left");
	}	
	if( (i > hour) 
	 && (j > min)
	 && (k > (hour+min))
	 && (l > (min-hour))
	 && (min-hour) >0)
         {            
		tell_object(me, "�����Ű����˻��أ�ͻȻ�������һת��\n");
    	        me->move(__DIR__"hssg");
		message("vision", me->name() + "��������ת�˹�����\n", environment(me), ({me}) );
            	me->delete_temp("marks/��1");
            	me->delete_temp("push/up");
            	me->delete_temp("push/down");
            	me->delete_temp("push/right");
            	me->delete_temp("push/left");		
            	return 1;
	}      
	write("�����Ű��»��أ�����һ�㷴ӦҲû�С�\n");
	return 1;
}

