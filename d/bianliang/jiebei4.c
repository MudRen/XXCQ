// beiengmen.c 

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "������");
        set("long", @LONG
 ���Ǳ����ţ��������Ϸ����š����š�����������֡�
��������������ҩ���ȡ�
LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("sleep_room",1);
        set("exits", ([
                "north" : "/d/yaowang/shanlu1",
                "south" : __DIR__"huangshanjie3",
                "northwest"  :  "/d/newbei/road1",
        ]));
//      set("objects", ([
//              "/clone/weapon/changjian" : 4]));
        set("area", "����");
        setup();
        replace_program(ROOM);
}

