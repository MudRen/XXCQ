// Room: /d/shaolin/zoulang7.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ȡ������ϲ�ķ�����������ĸ�ǽ����һ�����뱱��
����Ժ���ݶ�����������ǽ�Ϲ���һ�����������������Դ������������
�ִ��������
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"east" : __DIR__"zoulang8",
		"west" : __DIR__"fzlou",
		"south" : __DIR__"wuchang2",
		"north" : __DIR__"chanfang2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

