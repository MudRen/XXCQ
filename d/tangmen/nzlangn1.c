//nzlangn1.c		ËÄ´¨ÌÆÃÅ¡ªÇàÊ¯Ğ¡Â·

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ÇàÊ¯Ğ¡Â·");
	set("long", @LONG
ÕâÊÇÒ»ÌõÇàÊ¯ÆÌ¾ÍµÄĞ¡Â·¡£ÓÉÓÚÀ´À´ÍùÍùµÄÈËÊıÌ«¶à£¬´Ö²ÚµÄÇà
Ê¯ÒÑ¾­±»Ä¥µÄ¹â»¬Èç¾µ¡£Ò»Ğ©ÌÆÃÅµÄµÜ×ÓÍùÀ´´©Ëó£¬ÕâÀï»¹ÕæÊÇºÜÈÈ
ÄÖ¡£ÕâÀïÏò£
LONG);
	set("exits", ([
			"south" : __DIR__"neiyuan",
			"north" : __DIR__"nzlangn2",
			"east" : __DIR__"erukou",
			"west" : __DIR__"wrukou",
	]));
	set("area", "ÊñÖĞ");
	set("objects", ([__DIR__"npc/tangfang" : 1,]));
	setup();
	replace_program(ROOM);
}