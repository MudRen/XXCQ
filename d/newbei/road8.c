// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short",  "�ٵ�");
	set("long",
"����һ��������ֱ�Ĺٵ�������·�棬����ݵ���ʮ���ۡ�����ͨ��\n"
"��͢�Ļʳǣ�����ͨ�������ǡ�������һ���������Ƶĸ�ɽ�����˶���֮Ϊ\n"
WHT"����ѩɽ��"NOR+"���ֶ�����������ѧϰ���������漼�ܡ�\n"
);
	set("exits",  ([
//		"north"  :  "/d/chaoting/chengmeng",
		"westup"  :  __DIR__"shanjiao",
		"east"  :  __DIR__"road7",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
