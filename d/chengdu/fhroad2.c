//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "佻�Ϫ��");
        set ("long", @LONG
����һ��С��·����佻�Ϫ���������죬·�Ķ��������µ�Ұɽ����
ɷ�Ǻÿ���·������Կ����峺��Ϫˮ���������У��ò����졣����·��
������ͨ��Զ�������ĶŸ����ã���ຢ��Ҳ�Ҵҵ���������·�ϡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"fhroad3",
		"north" : __DIR__"fhroad1",
       ]));

        set("outdoors", "xiao");
        setup();
}