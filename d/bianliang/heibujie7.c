// heibujie7.c  by winder

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "�ڲ���");
        set("long", @LONG
�����Ǻڲ��֣����ϱ�ɵ����пڣ�������һ��Ǯׯ������������
�������Ľ���������

LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("outdoors", "bianliang");
        set("exits", ([
                "north" : __DIR__"heibujie6",
                "south" : __DIR__"caishikou",
//              "west" : __DIR__"mingliquan",
                "west" : __DIR__"qianzhuang",
        ]));
//      set("objects", ([
//              "/clone/weapon/changjian" : 4]));
        set("area", "����");
        setup();
        replace_program(ROOM);
}

