//Room:��ܰ��
//Write by godzilla 1999.11.12
#include <room.h>
inherit ROOM;

void create()
{
         set("short","��ܰ��");
         set("long",@long
���Ӳ���,����ȴ�ǳ����������ܹ����������ֻ������������
�ɾ����������һ�������������ķ��䡣
long);
         set("no_fight", 1);
         set("exits",([
             "east" : __DIR__"neitang",
]));
        set("objects",([
                __DIR__"npc/fanggeyin" : 1,
                ]));

         setup();
         replace_program(ROOM);
}

