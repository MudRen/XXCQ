// guandao

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "¹ÙµÀ");
        set("long", @LONG
 ÕâÊÇÒ»ÌõòêÑÑ²»Æ½µÄ¹ÙµÀ£¬Ö»¿ÉÒÔÈÃ¼¸¸öÈË²¢ĞĞ¡£Íù±±Í¨ÏòãêÁº
,ÍùÄÏÖ±´ïáÔÉ½¡££
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
        set("area", "ãêÁº");
        setup();
        replace_program(ROOM);
}

