//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "�����򶫿�");
        set ("long", @LONG
���������򶫿���һ��С��·�����ڸ����Ǻ�������ߣ�����Ҳ��û
��������·������·���Ե�һ��С���ӣ�������������������С��Ľ���
�֣�����Ǯׯ�����������ϡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"tulu6",
		"west" : __DIR__"jinyin3",
	]));

        set("outdoors", "zigui");
        setup();
}