//changan city

#include <ansi.h>
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create ()
{
        set ("short", "����������");
        set ("long", @LONG
����վ���������ǻ�������������ᴩС�������������еĵ��̶�
���������ϡ�������������׾��Ƿ�Բʮ��֮��Ψһ��һ���ӻ��꣬����
��С��ľ��񣬾�����Χ�������ҲҪ��������������·������һ�Ҵ�
���̡�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"hyroad2",
		"south" : __DIR__"hyzahuo",
		"east" : __DIR__"hyroad4",
		"north" : __DIR__"hytiepu",
       ]));

        set("outdoors", "huayang");
        setup();
}
