// syz.c
#include <ansi.h>
inherit ROOM;
string look_view();
void create()
{
         set("short",HIY"�ͺ�ի"NOR);
         set("long",@long
�������ͺ�ի��������ǽ��һ�������棬��������������͵������
��ɫ(view)��
long);
         set("exits",([
		"west" : __DIR__"cl2",
	]));
	set("item_desc", ([
	"view" : (: look_view :),
]));
	set("objects", ([
	__DIR__"obj/fruit" : 2,
//	__DIR__"npc/ghost" : 1,
]));
        setup();                
}  
string look_view()
{                                              
	string str;
	object room;
	mixed *local;
	local = localtime(time() * 60);	
	room = find_object(__DIR__"boat1");                                              
	if(!(room=find_object(__DIR__"boat1")))
	     room=load_object(__DIR__"boat1");
	if( room->query("busy"))
	str = "������һ��С���ںɻ�������������\n";	                                                  
	else str = "";
        if( local[2] > 6 && local[2] <= 20 )  
        {
        	switch(random(3))
        	{
        		case 0 :
		return HIG"һƬһ���޼ʵĺɻ�����һ����ȥ, ������Ҷ, ��Ҷ, «έ, ����, \n"
		"����һģһ��, ��֮��Ҷ, ��Ҷ��ˮ��Ư��, ��ʱһ�����, �㼴\n"
		"�仯�ٶ�, ����˿̼ǵ��������, ��ʱ������ȫȻ��ͬ��\n\n"+str+"\n"NOR;
		break;
                        case 1 :
		return HIG"ԶԶ����ˮ��С�ӵ�һ�����ܡ���ֻ�����ͷ���ӹ���\n\n"+str+"\n"NOR;
		break;
		
		        case 2 :
		return HIW"����ż��������˿���������Ǻ��е�С���ϵĹ����ڲ�����Ϸ��\n\n"+str+"\n"NOR;
		break;
		}
	}
	else
	{	
		return BLU"�˿̺��������һƬ����ʲôҲ��������\n"NOR;
	}	
}
/* 
void init()
{
	add_action("do_attack", "attack");
	add_action("do_fly", "yue");
}

int do_attack()
{
	int temp_qi;
	int qi;
	object ob;
	object ob1=this_player();

	if (!ob1->query_temp("buster_temp")) return 0;
	if (ob1->query_temp("buster_temp") != 1) 
	return 0; 
	if(ob = present("ghost shadow", this_object()));
	{
	qi = ob1->query("max_qi");
	ob->set("eff_qi",qi);
	ob->set("qi",qi);
	ob1->set("eff_qi",qi);
	ob1->set("qi",qi);
	COMBAT_D->do_attack(ob1, ob, ob1->query_temp("weapon"), 0);
	temp_qi = ob->query_temp("blood") - (qi - ob->query("qi"));
	ob->set_temp("blood",temp_qi);
	ob1->set_temp("buster_temp", 2);
	}
	if (temp_qi < 1) {
		message_vision("$N�������ˡ�\n",ob);
		ob1->delete_temp("buster_temp");
	}
	return 1;
}                                   

int do_fly(string arg)
{
	object me;
	me = this_player();
	if( me->is_busy())
		return 0;
	if( me->is_fighting())
		return 0;
	if( !living(me))
		return 0;
	if(!arg)
	{
		message("vision", "$N����һԽ�������˷�����\n", environment(me), ({me}));
		write("������һԽ�������˷�����\n");
		me->move(__DIR__"roof");
		message("vision", "$N�����������˷�����\n", environment(me), ({me}));
		return 1;
	}
}*/