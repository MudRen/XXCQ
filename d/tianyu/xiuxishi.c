//Room: kefang.c �ͷ�
//Date by godzilla 1999.10.13


#include <room.h>

inherit ROOM;

void create()
{
         set("short","�ͷ�");
         set("long",@long
����һ��ͷ�, ��������,��߷���һ�Ŵ�,��������ĵ���
���ӡ�������ר��Ϊ���ÿ���׼���ġ�
long);
         set("no_fight", 1);
         set("sleep_room", 1);
         set("exits",([
             "west" : __DIR__"dating",
]));
 	 setup();
	 replace_program(ROOM);
}
