// hxlou.c

#include <ansi.h>

string look_hole();
inherit ROOM;

void create()
{
         set("short",HIR"��ϼ¥"NOR);
         set ("long",
HIR"��ϼ¥"NOR"����һ��"HIY"С��"NOR"��"HIY"����"NOR"�Ե�"HIC"ʯ��"NOR"�ڶ����ġ�ֻ��һ��С����(window)
͸����˿��ɭ��\n"
);
	set("exits",([
	"south" : __DIR__"hhyuan",
	"east" : __DIR__"hffang",
	"north" : __DIR__"yjl",
]));
        set("item_desc",([            
            "window" : (: look_hole :),
        ]));
	setup();
}
string look_hole()
{
    object me, room, ob;
    me = this_player();
    ob = this_object();
    if (!(room = find_object(__DIR__"hole")))
          room = load_object(__DIR__"hole");

    message_vision("$N����ת���رߣ��쳤����������������ȥ��\n", me);
    "/cmds/std/look.c"->look_room(this_player(), room);
    tell_object(room,"��������������������̽��\n");
    return "";
}