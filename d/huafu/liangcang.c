// liangcang.c ����
// made by lks

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"������ǻ��������֣�����������װ�Ÿ��ָ�����ʳ���Ȼ���ܺ�
���ְ��á����ϸ��¥��Щ���ǵĴ������ȣ������Ը����㻹��û����
�ġ����ڹ�������ǻ�����Ĵ��٣������½���һ������õĸ��������
ʲô�ġ���������ҿ���\n"
	);
	set("exits",([
		"west" : __DIR__"caifang",
	]));
	set("valid_startroom",1);
       set("objects",([
             __DIR__"npc/puren" : 1,
       ]));
	setup();
}

/*.
void init()
{
	add_action("do_search","search");
}

int do_search(string arg)
{
	object me;
	object ob;
	me=this_player();
	
        if ( (arg=="����") || (arg=="gaoliang") )
	{
		if (ob=present("gaoliang",me))
			return notify_fail("һ��ֻ����һ����\n");
                message_vision("$N�ҵ�һ��������\n",me);
		ob=new("/d/huafu/obj/gaoliang");
		ob->move(me);
		return 1;
	}
        if ( (arg=="���") || (arg=="mianfen") )
	{
		if (ob=present("mianfen",me))
			return notify_fail("һ��ֻ����һ����\n");
                message_vision("$N�ҵ�һ����ۡ�\n",me);
		ob=new("/d/huafu/obj/mianfen");
		ob->move(me);
		return 1;
	}
	return notify_fail("����û������Ҫ�Ķ�����\n");
}

*/
