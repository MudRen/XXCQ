// huangkudajie6.c

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "�ƿ���");
        set("long", @LONG
������ƥ���Ĵ�ִ�������������������������·���Ѿ�û�и���
���̡����ˣ���������ȥ��������Զ���Ǿ������Ĺ㳡�ˡ�������ͨ
�򾩳��Ĵ����֮һ��������ʥ�˵���̳��
LONG);  
        set("valid_startroom",1);

        set("exits", ([
                "west" : __DIR__"guangchang",
                "east" : __DIR__"huangkudajie7",
        "north":__DIR__"hongniang-zhuang",
        ]));

        set("outdoors", "bianliang");
        set("area", "����");

        setup();

        replace_program(ROOM);
}

