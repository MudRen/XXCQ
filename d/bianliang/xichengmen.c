// nanchengmen.c 

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "������");
        set("long", @LONG
 ���������ţ��������Ϸ����š����š�����������֡�
�����߾͵���梹��� ��
LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("sleep_room",1);
        set("exits", ([
                "west" : "/d/room/playtown/guandao1",
                "east" : __DIR__"huangkudajie3",
        ]));
//      set("objects", ([
//              "/clone/weapon/changjian" : 4]));
        set("area", "����");
        setup();
        replace_program(ROOM);
}
