//tangltt.c		�Ĵ����š���̫̫����

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������̫̫�����ҡ�������������������������������
��������������������������������������������������������������
˭������һ�£���ûȥ����sigh
LONG);
	set("exits", ([
			"south" : __DIR__"nzlang3",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/tangltt" : 1,]));
	setup();
	replace_program(ROOM);
}