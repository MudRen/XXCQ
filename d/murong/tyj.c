// tingyuju.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",BLU"�����"NOR);
         set("long",
"��"WHT"�����"NOR"�����滷ˮ, �Ӵ�������ȥ, �����̲������۵ס������а���\n"
"һ�Ŵ�Բ��, ����������߹�����, ÿһ����ʮ�־��¡� Բ�����ܷ�����\n"
"�����ӡ�ǽ�ߵ�С���Ϸ���һ�ѡ�"BLINK HIB"��"NOR"����\n"
);        
         set("item_desc",([
             "floor" : "�����Աߵĵ��治��ʮ��ƽ����\n",
             "qin" : "����һ�ѹ��٣���һ����ʹ���Ŀ�������\n",
]));
         set("exits",([
		"east" : __DIR__"xs",
])); 
	 setup();
}                

void init()
{
	add_action("do_tan", "play");
	add_action("do_tan", "press");
        add_action("do_tan", "tan");
}

int do_tan(string arg)
{
	int i, j;
        object me, boat;
     	me = this_player();
     	boat = find_object(__DIR__"boat");
        i = 20+random(20);
        j = 20+random(20);
        if (!living(me))  return 0;
        if (arg !="qin" || !arg || arg == "") 
		return notify_fail("��Ҫ��ʲô��\n");


        if( arg=="qin")
        {
	        if(!(boat=find_object(__DIR__"boat")))
	             boat=load_object(__DIR__"boat");
	        if(boat->query_temp("busy"))
	        {
	             	write("�㵯��һ���٣��������ö������ɡ�\n");
	             	if(random(5) <2)
	             	tell_object(boat, "Զ���ĺ����ϴ������ö������ɡ�\n");
	             	return 1;
	        }
	        else 
	        {	
         	write("�㵯��һ���٣�ͻȻ����һ�գ�������ȥ��\n");
             	message("vision", me->name() + "����һ���٣�ͻȻ����һ�գ�������ȥ��\n", environment(me), ({me}) );
             	me->move(__DIR__"boat");
             	message("vision", me->name() + "������ĸ����е�������,�䵽һ��С���ϡ�\n", environment(me), ({me}) );
             	me->delete("mr/x");
             	me->delete("mr/y");
             	me->set("mr/x", i);
             	me->set("mr/y", j);
             	return 1;
             	}
         }

}
