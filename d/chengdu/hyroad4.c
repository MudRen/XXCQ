//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "����������");
        set ("long", @LONG
���С����ĺ�С����վ�ĵط��������͵���С���Ψһ��·���ˡ�
����ı�����һ�Ҵ����̣������������������Źɹ����˴�����������һ
�ҿ������������լ�ӡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
            "east" : "/d/longmen/lukou",
		"west" : __DIR__"hyroad3",
//		"south" : __DIR__"hydatie",
       ]));

        set("outdoors", "huayang");
        setup();
}
