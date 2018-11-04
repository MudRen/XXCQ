//chufang

#include <ansi.h>
#include <room.h>
inherit ROOM;
int delete_busy();

void create()
{
        set("short","����");
        set("long", @LONG
LONG);
        set("valid_startroom",1);
        set("exits", ([
                "west" : __DIR__"qingyunge",
                  "north" : __DIR__"wuqifang",
        ]));
        set("no_fight", 1);
        set("area", "��ɽ");
        setup();
}

void init()
{
        add_action("do_yao","yao");
}

int do_yao()
{
        object ob, food, water;
        if(query("busy"))
                return notify_fail("�Բ����������æ������΢��һ�°ɣ�\n");
        set("busy",1);
        call_out("delete_busy",5);
        ob = this_player();
        food=new(__DIR__"obj/gao");
        water=new(__DIR__"obj/hulu");

        if( (present("meihua gao", ob)) && (present("da hulu", ob)) )
        {
               message_vision(HIW "��ʦ����$N˵�ţ����ȳ�������Ҫ����\n" NOR, ob);
                delete_busy();
                return 1;
        }
        else
        {
                if ( (present("meihua gao", ob)) )
                {
                        message_vision(HIW "��ʦ��һ�����«����$N��ǰ���������ȣ�����\n" NOR, ob);
                        water->move(ob);
                        return 1;
                };
                if ( (present("da hulu", ob)) )
                {
                        message_vision(HIW "��ʦ��һ��÷�������$N��ǰ���������ԣ�����\n" NOR, ob);
                        food->move(ob);
                        return 1;
                }
                else
                {
                        message_vision(HIW "��ʦ��һ��÷���⡢һ�����«����$N��ǰ��\n" NOR, ob);
                        food->move(ob);
                        water->move(ob);
                        return 1;
                }

        }
}

int delete_busy()
{
        delete("busy");
}

