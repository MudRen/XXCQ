//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
����һ���ƺӱ�ǧ���С��ׯ�е�һ�������Ӻ�С������������Ҳû
�У�����ֻ������Ҿ��񣬼��бȽϸ�ԣ�Ķ��ᵽ������������ֻ����
Щ���˻�ס�����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"minju1",
		"south" : __DIR__"tulu2",
		"north" : __DIR__"jiangpan3",
	]));

        set("outdoors", "zigui");
        setup();
}