// Room: ���ı�
// Date: by godzilla 1999.11.18

#include <ansi.h>
inherit ROOM;
int exercising();
int exercising1();

void create()
{
	set("short", "���ı�");
	set("long", @LONG
һ�߽����͸о��������泩�����ı����滷ɽ������λ��������
��������֮�����������£���������ǰ�������ҵ����������������
LONG );
	setup();
	
}
void init()
{
	add_action("do_look","look");
        add_action("do_halt","halt");
	add_action("do_mianbi","lianqi");
	add_action("do_climb","climb");
}
int do_halt()
{
       tell_object(this_player(),"���ı�,����֮��,������ֹ�κ��ж���\n");
       return 1;
}
int do_look()
{
	object ob;
	mixed *local;
	local = localtime(time() * 60);
		
	if(local[2]>=4 && local[2]<8)
	{
		write(HIW"ɽ�����ܵ���������Ũ������������˿˿��͸��һ�����⣬΢��ϰϰ��
		\n����ĸ�����Ǻ��Ӱ�ķ������ϣ������Ŀ�����������ƮƮ����֮�С�\n"NOR,ob);
        }
        if(local[2]>=8 && local[2]<22)
        {
        	write(MAG"���Ѿ�ɢ�ˣ�����͸��ɽ�����˽���������ɽ���������ӳ���£���Ȼ
        	          \n�漣��ķ�������������һ�Ṧ������ɽ�ȶ��Ѿ�����������Χ�ˡ�\n"NOR,ob);
        }	 
        if(local[2]>=22 || local[2]<2)
        {
        	write(HIB"��ؼ佥���������������ܵ�ɽ��һ���Ӱ�������������Ҳ��������ʧ��......\n"NOR,ob);
        }
        if(local[2]>=2 && local[2]<4)
        {
            write(WHT"�������䣬����ɽ����������Ĵ̼��£�ɢ������ɫ�����塣\n");
        }	
}

int do_mianbi()
{
        object me = this_player();
	mixed *local;
        local = localtime(time() * 60);
	if (me->is_busy()||me->query_temp("pending/exercising"))
	return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() )
	return notify_fail("ս���в������������Ǻ�Σ�յġ�\n");
	if( !stringp(me->query_skill_mapped("force")) )
	return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");
	if(me->query("jingli")<100)
	return notify_fail("�����ھ����������޷�������\n");
	if(me->query("neili")<me->query("max_neili")/2)
	return notify_fail("�����������������޷�������\n");
	if(local[2]>=4 && local[2]<8)
	{
		write("�������������ù���һ����Ϣ��ʼ������������\n");
		me->set_temp("pending/exercise", 1);
		me->set_temp("exercise_cost", 70-me->query("con"));
		message_vision("$N��ϥ���£���ʼ����������\n", me);
		me->start_busy((: exercising :));
            	return 1;
        }
        if(local[2]>=8 && local[2]<22)
        {
        	write(MAG"�㾲�ľ���˫ϥ���������й���ֻ��һ�������������ܻ��ƣ���ؾ����������á�\n"NOR);
        	me->set_temp("pending/exercise",1);
        	me->set_temp("exercise_cost", 40-me->query("con"));
            	message_vision(MAG"$N������������ʼ����������\n"NOR, me);
            	me->start_busy((: exercising1 :));
            	return 1;
        }
        if(local[2]>=22 || local[2]<2)
        {
            	write("�������������ù���һ����Ϣ��ʼ������������\n");
		me->set_temp("pending/exercise", 1);
		me->set_temp("exercise_cost", 70-me->query("con"));
		message_vision("$N��ϥ���£���ʼ����������\n", me);
		me->start_busy((: exercising :));
            	return 1;
        }
        if(local[2]>=2 && local[2]<4)
        {
        	write(HIB"������һ������ͻȻ�����ؿ����ƣ���Ϣ������ȫ����ľ���ܶ�����"NOR);
        me->add("max_neili",-3);
        	me->unconcious();
        }	
        
}
int exercising()
{
	object me =this_player();
	int i = me->query_temp("exercise_cost");
	me->set_temp("exercise_cost", i -=1);
	if (i > 0)
	return 1;
	if (i <= 1)
	{
		me->set_temp("pending/exercise", 0);
		me->interrupt_me();
		me->add("max_neili", 1);
	        me->add("neili", -100);
	        me->add("jingli",-100);
	        message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
	        return 0;
	}        
     if ((int)me->query("max_neili") < (int)me->query_skill("force") * 5)
	{
		return 0;
	}	
	else
	{
		write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
		return 0;
	}
}
int exercising1()
{
	object me =this_player();
	int i = me->query_temp("exercise_cost");
	me->set_temp("exercise_cost", i-=1);
	if (i > 0)
	return 1;
	if (i <1)
	{
		me->set_temp("pending/exercise", 0);
		me->interrupt_me();
		me->add("max_neili", 1+random(2));
	        me->add("jingli",-50);
		message_vision(MAG"$Nһ�����й���ϣ�����վ��������ֻ��ȫ�������������ڹ���Ϊ������һ�֡�\n"NOR, me);
		return 0;
	}	
	if ((int)me->query("max_neili") < (int)me->query_skill("force") * 10)
	{
		return 0;
	}	
	else
	{
		write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
		return 0;
	}
}
int do_climb(string arg)
{
	object me=this_player();
	if(!arg||arg=="")
	return notify_fail("��Ҫ���Ķ�����\n");
	if(me->is_busy())
	return notify_fail("��������æ���ء�\n");
	if(arg=="up")
	message_vision("$Nץס�ڷ죬������������.....\n",me);
	if(me->query("jingli")<200)
	{
		tell_object(me,"��ֻ����Խ��Խ�������ģ�һ��ʧ���ֵ���������\n");
		tell_room(environment(me),"ֻ��"+me->name()+"�Ӱ�ɽ���ֵ���������\n");
		me->move(__DIR__"tianxinb");
		me->unconcious();
		return 1;
	}
	else
	{
		tell_object(me,"�㲻һ���������ɽ�ڡ�\n");
		me->move(__DIR__"tianxinb1");
		return 1;
	}
}	
			
			
	
	     	 
