// Room: xiaojing.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// Modified Long
// 

inherit ROOM;
void create ()
{
        set ("short", "С��");
        set ("long", @LONG
�߳����䳡��������һ��С�����뿪���Ǹ������˽к����ͺ�
��ζ�ĵط��������������������ľ�ĵط������ʱ���þ���Ϊ֮
һ���ƺ��ո������ƣ�Ͷ�û���ˡ�ǰ�汱����һ�����µ�С�ᣬ
���Ƿ��á������������䳡��
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "south" : __DIR__"xilianwuchang",
                "north" : __DIR__"fantang",
        ]));
        replace_program(ROOM);
        setup();
}