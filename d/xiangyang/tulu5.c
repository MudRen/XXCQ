//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
�ᴩС��ׯ����·���������Ҫ�����ˣ�����·������һ��é�ݣ���
���Ѿ�������é���ˣ�·����������������Ҳ��΢����Щ��ԶԶ���Ѿ���
���������ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northeast" : __DIR__"tulu4",
		"southwest" : __DIR__"tulu6",
		"east" : __DIR__"minju5",
        "north" :  "/d/tianyu/damen",
	]));

        set("outdoors", "zigui");
        setup();
}
