// gangyao.c  ��Ҥ
// made by lks

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","��Ҥ");
        set("long",
"�����������һ��ŨŨ�ľ����⣬���ڿ�������ͨ���е�һ˿˿ͷ
�Ρ�͸��ǽ���ϵ���⣬��ϡ���Կ���һ����ͻ���С���������涼����
���ӡ�ԭ�����������Ƶĵط���\n"
	);
	set("exits",([
		"up" : __DIR__"zaofang",
	]));
	set("valid_startroom",1);
	setup();
}

void init()
{
	add_action("do_mai","mai");
}

int do_mai(string arg)
{
	object me;
	object ob;
	me=this_player();
	
        if ( (arg!="���;�") && (arg!="jiuyunjiu") )
		return 0;
	if (!ob=present("jiuyunjiu",me))
		return 0;
	message_vision("$N��������һ���ӣ��Ѿ����˽�ȥ�������˸����ӣ�ע����Ƶ����ڡ�\n",me);
       me->set_temp("fmjob_ok",1);
	me->start_busy(random(5));
	destruct(ob);
	return 1;
}

