// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ǧ���");
	set("long", @LONG
����ǧ���������������ȣ��߱����硣���﹩����������
�����а��������Ľ�գ���ٰ��ޣ���ǧ���У�ʮһ���ף�ʮ��٤������
�����������������ĵȡ�ֱ�������ۻ����ҡ�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"southdown" : __DIR__"guangchang5",
	]));
	set("objects",([
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

