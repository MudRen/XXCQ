//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "����������");
        set ("long", @LONG
����վ���������ǻ�������������ᴩС�������������еĵ��̶�
���������ϡ�������������׾��Ƿ�Բʮ��֮��Ψһ��һ���ӻ��꣬����
��С��ľ��񣬾�����Χ�������ҲҪ��������������·������һ����
ͨ��ӡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"hyroad2",
		"south" : __DIR__"hyzahuo",
		"east" : __DIR__"hyroad4"
       ]));

        set("outdoors", "huayang");
        setup();
}
