// Room: xuetang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// Modified Study
// 

inherit ROOM;

void create ()
{
        set ("short", "ѧ��");
        set ("long", @LONG
δ����ѧ�þ�����������ԼԼ�Ķ��������߽���֮�������
��ĺܴ���������ͯ���Ƿǳ������ġ��������ŵĴ󲿷ֶ�
��С������һЩ�Ǵ��ˣ����Ǿ��������Ⱥһ�������ǡ���С��
Ŭ�����ϴ�ͼ�˱�����ǽ����������ѧ��(xuegui)��
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
//      __DIR__"npc/wenkongzi": 1,
               __DIR__"npc/wenxiaoming": 1,
               __DIR__"npc/wenxiaofang": 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/��", 0);
        return 1;
}
