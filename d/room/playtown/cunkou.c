// by ɽèADX @ snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short",  "���");
	set("long",
"�������"HBRED WHT"��Сѩ���硻"NOR+
"����Ҵ塣����ǳ��İ�������������Ƕ���æ\n"
"������ͣ������۰���\n"
);
	set("exits",  ([
		"north"  :  __DIR__"guandao8",
		"south"  :  __DIR__"road14",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
