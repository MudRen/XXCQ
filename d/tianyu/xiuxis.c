//Room: kefang.c �ͷ�
//Date by godzilla 1999.10.13


#include <room.h>

inherit ROOM;

void create()
{
         set("short","��Ϣ��");
         set("long",@long
����һ����Ϣ�ң�ר��Ϊ�չ������ĵ���׼���ġ�
long);
            set("no_fight", 1);
         set("resource/water", 1);
         set("sleep_room", 1);
         set("exits",([
             "west" : __DIR__"lgs",
]));
         set("objects", ([
         __DIR__"obj/hulu" : 1,
         __DIR__"obj/meihua-zaoya" : 3,
         ]));

 	 setup();
}
void init()
{
	add_action("do_quit","quit");
}
int do_quit()
{
       object me=this_player();
       tell_object(me,"�չ�ʱ�����˳���\n");
       return 1;
}
