// Room: /city/chouduanhang.c
// YZC 1995/12/04

#include "/clone/room/mache.h"

inherit ROOM;

void create()
{
	set("short", "汴梁驿站");
	set("long", @LONG
这是一间用木板从大木棚隔出的一间小房，装饰的还算不错，一个笑
嘻嘻的伙计站在那里，见你进来连忙上来招呼，柜台侧面有一个大门，门
虚掩着，里面传来马的嘶鸣声，如果你想坐车，就雇一辆(gu che)吧。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));

	set("area", "汴梁");

	setup();
}
