// hole.c


inherit ROOM;
#include <ansi.h>

string look_out();
void create()
{
         set("short",HIR"ʯ��"NOR);
         set ("long",@long
�������һƬ��ʲô�������������ܿ�����ֻ��һ��С����(window)��
������͸����һ˿������
long);
        set("item_desc",([            
            "window" : (: look_out :),
        ]));
	setup();
	replace_program(ROOM);
}

	