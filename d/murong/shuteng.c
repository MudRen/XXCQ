// shuteng.c

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",GRN"����"NOR);
         set("long",@long
���ﳤ�������٣�һ֦һ֦������(teng)��ס�����⣬�����̸����,��
ֻ�����������������¡�
long);
         set("item_desc",([
         "teng" : "������ס�����⣬����û��һ����ߣ�ʹ�㼫���Ĳ�����֦(zhi)��\n",
]));
         setup();
}           

void init()
{
        add_action("do_move", "pa");
        add_action("do_move", "move");
        add_action("do_bo", "bo");    
}                                    

int do_move(string arg)
{
        object me;
        me = this_player();
        if (arg !="down")
        return notify_fail("��Ҫ����������\n");
        if (arg == "down")
        message_vision("$NС�ĵ���ס���٣�������ȥ��\n" , me);
        me->move(__DIR__"hhyuan");                            
        message("vision", "$NС�ĵ���ס���٣�����������\n" , environment(me), ({me}));
        return 1; 
}                                     

int do_bo(string arg)
{
        object me;
        me = this_player();
        if (arg !="teng")
        return notify_fail("��Ҫ��ʲô��\n");
        if (arg =="teng")
        write("�㲦�����٣���ǿ¶��һ˿���⣬��ʱ�㿴��һƬʢ�����һ���\n");
        return 1;
}

