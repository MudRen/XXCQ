// jiaoshi.c  ����
// made by lks

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"������ǻ���������ң�������ƵĹ������̺ܸ��ӡ���������ֹ�
��ϸ����Ҳ�ر��Щ�����Ǵ�æµ���ֳ����������Ǿ������ֲ���������
��������ǻ�������٣��͸�Ҥ���Ǽ�ƿ���ǲ����ġ�\n"
	);
	set("exits",([
		"out" : __DIR__"zaofang",
	]));
	set("valid_startroom",1);
        set("objects",([
                 __DIR__"npc/niangjiushi" : 1,
        ]));
	setup();
}

void init()
{
	add_action("do_zhuang","zhuang");
	add_action("do_fire","fire");
}

int do_zhuang(string arg)
{
	object obb;
	object me;
	me=this_player();
	
                 if (query("kaishi"))
                         return notify_fail("�Ѿ�����������ˣ����Ե�һ�ᡣ\n");
        if ( (arg=="����") || (arg=="peizi") )
	{
		if ( !obb=present("peizi",me) )
			return 0;
		message_vision("$N������װ�������У�����ƽ��Լ���Ĵ��\n",me);
		me->set_temp("zhuangpeizi",1);
		destruct(obb);
                 set("kaishi",1);
               remove_call_out("cut");
                      call_out("cut",30);
		return 1;
	}
        if ( (arg=="������") || (arg=="gaoliangfan") )
	{
		if (!obb=present("gaoliangfan",me) ) 
			return 0;
		message_vision("$N�����ȵĸ�����װ����У�ѹ������Ϳ�����ϣ��Ը���������\n",me);
		me->set_temp("zhuangfan",1);
		destruct(obb);
		return 1;
	}
	return notify_fail("��Ҫ��ʲô����װ�������棿\n");
}

int do_fire(string arg)
{
	object me;
	me=this_player();
	
        if ( (arg!="��") && (arg!="��") && (arg!="jiao") && (arg!="guo")  )
		return notify_fail("��Ҫ��ʲô�������£�\n");
        if ( (arg=="��") || (arg=="jiao") )
	{
		if ( me->query_temp("zhuangfan") )
		{
			int i;
                        i=(12-((int)me->query("max_neili")/100));
			if ( (int)me->query("neili") <=100)
			{
				message_vision("$Nƴ���������ŷ��䣬����ܵ��ϸߡ�\n",me);
				me->set_temp("firejiao",1);
				remove_call_out("del_job");
				call_out("del_job",i);
				return 1;
			}
                        else {
                            me->add("neili",-(10+random(10)));
                        }
			message_vision("$N�������ƣ��߶��Ż��硣\n",me);
			me->set_temp("firejiao",1);
			remove_call_out("del_job");
			call_out("del_job",i);
			return 1;
		}
		
		tell_object(me,"�㻹û�Ѹ�����װ�����С�\n");
                return 1;
	}
        if ( (arg=="��") || (arg=="guo") )
	{
		if ( me->query_temp("zhuangpeizi") )
		{
			int i;
                        i=(12-((int)me->query("max_neili")/100));
			if ( (int)me->query("neili") <=100)
			{
				message_vision("$Nƴ���������ŷ��䣬����ܵ��ϸߡ�\n",me);
				me->set_temp("fireguo",1);
				remove_call_out("del_job");
				call_out("del_job",i);
				return 1;
			}
                        else {
                            me->add("neili",-(10+random(10)));
                        }
			message_vision("$N�������ƣ��߶��Ż��硣\n",me);
			me->set_temp("fireguo",1);
			remove_call_out("del_job");
			call_out("del_job",i);
			return 1;
		}
		
		tell_object(me,"�㻹û������װ�������С�\n");
                return 1;
	}
}
	
int del_job()
{
	object ob;
	object me;
	me=this_player();
	
	if ( me->query_temp("firejiao") )
	{
		message_vision("$N�õ���һ�����ӣ�\n",me);
		ob=new("/d/huafu/obj/peizi");
		ob->move(me);
               me->add("qi",-(10+random(10)));
              me->delete_temp("zhuangfan");
              me->delete_temp("firejiao");
		return 1;
	}
	if ( me->query_temp("fireguo") )
	{
		message_vision("$N������¶������������һ̳�����˵�����������\n",me);
		ob=new("/d/huafu/obj/jiuyunjiu");
		ob->move(me);
               me->add("qi",-(10+random(10)));
              me->delete_temp("zhuangpeizi");
              me->delete_temp("fireguo");
                  set("kaishi",0);
		return 1;
	}
	return 0;
}

void cut()
{
          if (query("kaishi"))
                     set("kaishi",0);
                return;
}

