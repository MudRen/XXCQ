//jingshi2.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�侲�ҡ����������ŵ������ɡ������ĵط�������ǳ���
����û��һ˿����������û���κΰ��裬ֻ���ڵ�������ʮ��������
�м�����������������������������
LONG);
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
			"north" : __DIR__"nzlangw2",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}