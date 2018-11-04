// Room: /d/shaolin/wuqiku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����µ�������ɳ����µ�һ��ʮ�˰�����������νӦ�о��С���
��һ��������ٸ��ۻ����ҡ�ǽ������һ����С���ӣ�ÿ���������˸���
�����ı�����ǽ������һ����������˷��㣬�뼺���㡱��
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"zhulin2",
		"north" : __DIR__"fangjuku",
	]));

	set("objects",([
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/mudao" : 1,
		__DIR__"npc/obj/changjian" : 1,
		__DIR__"npc/obj/chanzhang" : 1,
		__DIR__"npc/obj/jiedao" : 1,
	]));

	setup();

	replace_program(ROOM);
}

