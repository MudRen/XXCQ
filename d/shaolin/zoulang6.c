// Room: /d/shaolin/zoulang6.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ȡ������ϲ�ķ�����������ĸ�ǽ����һ�����뱱��
����Ժ���ݶ�����������ǽ�Ϲ���һ������������������������ħ��
����Ԫ�񡱡�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"zoulang5",
		"east" : __DIR__"fzlou",
		"south" : __DIR__"wuchang1",
		"north" : __DIR__"chanfang1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

