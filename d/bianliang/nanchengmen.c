// nanchengmen.c 

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "�ϳ���");
        set("long", @LONG
 �����ϳ��ţ��������Ϸ����š����š�����������֡�
������һƬ��ɽ���룬һ������С����ɽ�����Ѷ��ϡ�
LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"nandajie1",
                "south" : __DIR__"guandao10",
]));
           set("objects", ([
           "d/bianliang/npc/youke" : 2, 
]));
        replace_program(ROOM);
}
