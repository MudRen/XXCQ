// guandao

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "�ٵ�");
        set("long", @LONG
 ����һ�����Ѳ�ƽ�Ĺٵ���ֻ�����ü����˲��С�����ͨ������
,����ֱ����ɽ���
LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"nanchengmen",
                "southup" : "/d/shaolin/shijie1",
        ]));
/*
        __DIR__"npc/bigwolf" : 2,
]));
*/
        set("area", "����");
        setup();
        replace_program(ROOM);
}

