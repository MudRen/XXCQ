// xixiangfang.c ���᷿
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","���᷿");
        set("long",
"�����ǻ��������᷿������������黹���飬ֻ��ǽ�Ϲ�����һ����
��������ɨü������չü�������������ʾ����������Ǹ�����˫ȫ����
��˿��������������ԡ�\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"south" : __DIR__"xiting",
	]));
	set("objects",([
		__DIR__"npc/song" : 1,
	]));
	setup();
	replace_program(ROOM);
}
