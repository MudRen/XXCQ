//liangongfang��c          

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
������Ȩ���ﶫ���������������ϱ�ĵط��ְ�������࣬ԭ����
��Ϊ���������ڵ��������ڹ����ķ��ľ��ҡ�
LONG);
        set("valid_startroom",1);
	set("exits", ([
                        "east" : __DIR__"dati",
	]));
        set("area", "Ȩ����");
	setup();
	replace_program(ROOM);
}
