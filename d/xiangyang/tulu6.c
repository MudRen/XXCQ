//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��·");
        set ("long", @LONG
��������������˶����ˣ���ʱ�����˴����ڳ�������·���򽫴�
��һ��С��ׯ���ﳤ���ߵľ�ʯ��̲��С�������Ҫ��һЩ����ҲҪ����
��·����ġ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"zgeast",
		"northeast" : __DIR__"tulu5",
        "north" : "/d/room/playtown/guandao4",
	]));

        set("outdoors", "zigui");
        setup();
}
