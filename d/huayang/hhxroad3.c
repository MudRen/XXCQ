//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "佻�Ϫ��");
        set ("long", @LONG
����һ��С��·����佻�Ϫ���������죬·�����������µ�Ұɽ����
ɷ�Ǻÿ���·��Ϫ����һ�����ƽʯ��������ǹ⻬������佻�Ѿ��Χ
�����ʯͷ��ϴ�·������Ǳ�ϴ��˵Ц�ţ��ò����֡�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"hhxroad1",
		"north" : __DIR__"hhxroad4",
        ]));

	set("hhjob", 1);
        set("outdoors", "xiao");
        setup();
}