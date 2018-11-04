// fenmu.c
#include <ansi.h>
#include <localtime.h>
inherit ROOM;

void create()
{
        set("short",HIB"��Ĺ"NOR);
        set("long", 
"������Ľ���ϵ����, Ľ��������Ҫ�����������������, ��һ��\n"
"�⡣ÿ������ʱ��, Ľ�ݺ��ᶼҪ��������档\n"
);
        set("exits", ([
                "west" : __DIR__"cl3",
        ]));
	set("objects",([
	__DIR__"npc/deng" : 1,
]));
        set("outdoors", "����Ľ��");
        setup();                          
}

void init()
{
	object me = this_player();      
/*	if( me->query("family/family_name") == "����Ľ��"
	&&  me->query("family/generation") == 2 )
	{
		message_vision("ͻȻһ������������$N���򷿶���\n", me); 
		me->move(__DIR__"roof");
	}
*/	add_action("do_ketou", "ji");
}

int do_ketou(string arg)
{                                            
	mixed *ltime;
	int current_month, current_day, current_hour;
	object me;
	me = this_player();             
	ltime = localtime(time());
	current_month = ltime[LT_MON]+1;
	current_day = ltime[LT_MDAY];                     
	current_hour = ltime[LT_HOUR];
	if( !living(me) )
		return 0;
	if( !arg || arg =="" || arg != "fen")
		return 0;
	if( me->query("family/family_name") != "����Ľ��")
		return 0;
	if( me->query("family/generation") != 3)                             
		return 0;
	if( arg == "fen")
	{                                                                    
		
		if(current_month == 4 && current_day == 5 && current_hour == 1)
		me->set("jifen", 1);
		message_vision("$N���������Ĺ��ڵأ����ŷ�Ĺ��ͷ��\n", me);
		return 1;
	}
		
}		