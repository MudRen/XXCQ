inherit ROOM;

#include <room.h>
int do_drink();
void create()
{
        set("short", "������");
        set("long", @LONG
��������ʱ������ȥ����ǰ���ص��������ռ���һЩ��Ϻ֮��Ķ���
�������俪��ʯ����̶���ˮ���������������á��������������������
���Ķ����ڹ���
LONG );
        set("resource/water", 1);
            set("sleep_room",1);

           set("objects",([
                   "/d/bianliang/npc/obj/niurou" : 4,
           ]));
        set("exits", ([
                "east" : __DIR__"mishi",
        ]));
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink()
{
        int max_water;
        object me;

        me = this_player();
        max_water = me->query("str")*10 + 100;
        if (me->query("water")<max_water) {
			me->add("water",30);
            message_vision("$N����һ��ˮ��\n",me);
        }
        else write("���Ѿ��ȱ��ˡ�\n");

        return 1;
}

