// Room: xuetang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.7.22
// 
// 

inherit ROOM;

void create ()
{
        set ("short", "ѧ��");
        set ("long", @LONG
δ����ѧ�þ�����������ԼԼ�Ķ��������߽���֮���������ĺܴ�
��������ͯ���Ƿǳ������ġ��������ŵĴ󲿷ֶ���С������һЩ�Ǵ�
�ˣ����Ǿ��������Ⱥһ�������ǡ���С��Ŭ�����ϴ�ͼ�˱�����ǽ����
������ѧ��(xuegui)��
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"donglianwuchang",
                "south" : __DIR__"cangshufang",
        ]));

        set("item_desc", ([
             "xuegui" : "�ս����������տ���Ŀ��ҳ��"  
                        "\nͨ��ʱ�������ζ�����ʫ����" 
                        "\n���������ʣ���ΰ�ʱ���ꡣ"
                        "\nҹ���Խ���������Ҫ������\n"
        ]));

        set("objects", ([
               __DIR__"npc/wenkongzi": 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object obj;
        
        me=this_player();

        if (dir == "south" && ((int)me->query("wentask/done") <= 150 || (int)me->query_skill("literate")<=30 )) {
                if (objectp(present("dizi", environment(me)))){
                        message_vision("һ���¼ҵ��Ӷ�$N˵�����㻹û�н����鷿������ʸ����ȥ��!\n", me);
                        return notify_fail("");
                } else {
                obj=new("/d/wenjia/npc/wenjiadizi");
                obj->move("/d/wenjia/xuetang");
                message_vision("һ���¼ҵ��ӴӲ��鷿�߳�����$N˵�����㻹û�н����鷿������ʸ����ȥ��!\n", me);
                return notify_fail("");
                }
        }

        return ::valid_leave(me, dir);
}
