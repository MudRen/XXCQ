// Room: /welcome/houting.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"��ѩ����"NOR);
    set("long",
"��������ݵĺ����������������ѧϰ��ô��һ���򵥵����⣬������Ҫ��\n"
"�Ƕ࿴���Կ��Ķ���"+HIC"��l xxxx��"NOR+"���磺�������"
"�򵥵����⣬�������ԡ�\n"
"�����������һ��̴ľ����"+HIM"��table����\n"NOR
    );
        set("exits", ([
                "west":__DIR__"houyuan",
                "east":__DIR__"dating",
                "north":__DIR__"beilang1",
                "south":__DIR__"nanlang1",
        ]));
	set("item_desc",([
	"table" : "���Ϻ������һ����"+HIM"��book��"NOR+"�������"+
		HIW"��pick��"NOR+"����������\n",
	"book" : "��ķ������д��"+WHT"�����־���\n"NOR,
	]));
        set("no_fight", 1);
        set("valid_startroom", 1);
      setup();
}

void init()
{
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("get_available" , 1);
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("��Ҫ��ʲô?\n");
       if ( query("get_available") )  {
       obj = new (__DIR__"npc/obj/szjing");
       obj->move(me);
       add("get_available", -1);
       message_vision(YEL"$N����������һ��"+WHT"�����־�����\n"NOR,me );
       }
       else
       return notify_fail("����ʲôҲû�У���֪����˭�����ˡ�\n");
       return 1;
}