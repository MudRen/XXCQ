// xiaoyuan.c СԺ
// Written by Doing Lu 1998/11/17

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "СԺ");
	set("long", @LONG
	������һ��СԺ����������һ���ˣ�����������ж������Χ���ĸ���
��ͯ�ӣ��������������̵���Ժ����һЩ��δ���͵�ʯ�ߣ�ľģ�������ķǳ���ϸ��
ʵ�������������������ݡ�
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("objects", ([
		"/adm/npc/luban.c"   : 1,
		__DIR__"npc/tongzi1" : 1,
		__DIR__"npc/tongzi2" : 1,
		__DIR__"npc/tongzi3" : 1,
		__DIR__"npc/tongzi4" : 1,
	]));

	set("exits", ([
         "east"    : __DIR__"playtown/chunzhangjia",
		"dule"    : __DIR__"dule/xiaoyuan",
		"caihong" : __DIR__"caihong/xiaoyuan",
	]));

	setup();
}
