// Room: xiaojing.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "С��");
        set ("long", @LONG
�߳����䳡��������һ��С�����뿪���Ǹ������˽к����ͺ���ζ��
�ط��������������������ľ�ĵط������ʱ���þ���Ϊ֮һ���ƺ���
�������ƣ�Ͷ�û���ˡ�ǰ�汱����һ�����µ�С�ᣬ���Ƿ��á�������
�����䳡��������һ�ŷ���ȴ��֪��ʲô�á�
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"xilianwuchang",
                "west" : __DIR__"task_da/shulin1",
                "north" : __DIR__"fantang",
        ]));

        setup();
        replace_program(ROOM);
}