// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ն���");
	set("long", @LONG
���Ǿ����ն��á������ں����ؽ࣬���õ����й��лƽ����ֵġ���
�����������سɷ𡱺͡��ຣ�ޱߣ���ͷ�ǰ����������֡����ڰ��ж�ʮ
��������ţ���ɮ���ڴ˹��������������±���ľ����ʦ�ڴ˽�����
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"southdown" : __DIR__"guangchang3",
	]));
	set("objects",([
		"/kungfu/class/shaolin/baoxiang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

