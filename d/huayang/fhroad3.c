//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "佻�Ϫ��");
        set ("long", @LONG
����һ��С��·����佻�Ϫ���������죬·��������Կ����峺��Ϫ
ˮ���������У��ò����졣��Ķ��߾���Զ�������ĶŸ����ã���ຢ��
�������߽��߳���
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"fhroad2",
		"east" : __DIR__"caotang",
       ]));

        set("outdoors", "xiao");
        setup();
}