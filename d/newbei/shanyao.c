// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short",  "��ѩɽ��");
	set("long",  @LONG
������ɽ������ǰ��һ���ߴ��ɽ�ţ�����һ��Ҫ������ѧϰ�ڽ���
�еĻ������漼�ܡ�
LONG);
	set("exits",  ([
		"west"  :  __DIR__"menqian",
		"eastdown"  :  __DIR__"shanjiao",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
