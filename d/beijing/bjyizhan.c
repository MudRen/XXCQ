// Room: /city/chouduanhang.c
// YZC 1995/12/04

inherit "/clone/room/mache.h";

void create()
{
	set("short", "北京驿站");
	set("long", @LONG
这是一间用木板从大木棚隔出的一间小房，装饰的还算不错，
一个笑嘻嘻的伙计站在那里，见你进来连忙上来招呼，柜台侧面有
一个大门，门虚掩着，里面传来马的嘶鸣声，如果你想坐车，就雇
一辆(gu che)吧。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"kedian",
	]));

	setup();
}
