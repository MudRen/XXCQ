// hhyuan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",MAG"��԰"NOR);
	set ("long",
"��԰��ׯ�������ط�һ��������"MAG"ɽ�軨"NOR", �����ڼ�ɽ"BLU"��ʯ"NOR", "GRN"����СϪ"NOR"\n"
"��, ����ν"HIY"��ǧ����ʼ����, �̱����ð����桹"NOR"�������ġ� ̧ͷ��ȥ, ֻ\n"
"��"HIC"�����"NOR"�Ĵ����뿪��,һ��"HIY"����"NOR"������ǽ�ϡ�һ��"HIW"��Ȫ"NOR"�Ӽ�ɽ��ӿ������һ\n"
"��������Ƣ��\n"
);
         set("resource/water", 1);
         set("outdoors", "����Ľ��");            

         set("exits",([
             "north" : __DIR__"hxlou",            
]));
         set("item_desc",([
             "teng" : "һ��˳��ǽ�����Ӷ��ϵ�"HIG"������"NOR"��\n"
]));
	setup();
}

void init()
{
	add_action("do_pa", "pa");
}

int do_pa(string arg)
{
	object me;
	me = this_player();
	
	if(!living(me))
		return 0;
	if( arg == "" || !arg || arg != "up")
		return notify_fail("��Ҫ����������\n");   
		
	if(arg = "up")
	{
	         write("�����Ŵ�����������ȥ��\n");
        	 message("vision", me->name()+"���Ŵ�����������ȥ��\n", environment(me), ({me}));
	         me->move(__DIR__"shuteng");
	return 1;
        }
}
		