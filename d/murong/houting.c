// houting.c

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @LONG
������Ľ�ݼ�����������ĵط�������Ľ�ݵ�����ò�Ҫ������������
�������аڷ���һ���㰸������ڷ���һ����λ����(paizi)��
LONG
    );
         set("item_desc",([
             "paizi" : HIY"\t\t\tĽ\n"
             	       	  "\t\t\t��\n"
             	       	  "\t\t\t��\n"
             	       	  "\t\t\t��\n"
             	       	  "\t\t\t��\n"
             	       	  "\t\t\t��\n"
			  "\t\t\t��\n"
			  "\t\t\tλ\n"NOR

]));
         set("exits",([
             "east" : __DIR__"sf",
             "west" : __DIR__"xf1",                    
             "south" : __DIR__"cl2",
             "north" : __DIR__"yanziwu",
]));
	 set("objects",([
	 __DIR__"npc/feng" : 1,
]));
         setup();       
}

void init()
{
	add_action("ketou", "ketou");
}

int ketou(string arg)
{
	object me;
	me = this_player();
	
        if( !living(me))                             
        	return 0;                            
        if( me->is_busy())
        	return 0;
        if( me->is_fighting())
        	return 0;
        if( !me->query("jifen"))
        	return 0;
        if(arg)
        	return notify_fail("��Ҫ��ʲô��\n");     
        if(!arg)
        {
        	message_vision("$N���������ع��ڵأ�������λ��ͷ��\n", me);
        	me->set("ketou", 1);
        	return 1;
        }
}

