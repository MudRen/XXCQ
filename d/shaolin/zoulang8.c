// Room: /d/shaolin/zoulang8.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ȡ������ϲ�ķ�����������ĸ�ǽ����һ����ռ���
����ϸϸ��ʯ���ϣ����������ϣ�������һ��Ƭ���֣�ܰ����������Ӱҡ
ҷ��ʫ�������ͷ������һ����Ȥ��
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"zoulang7",
		"north" : __DIR__"zhulin1",
		"south" : __DIR__"wuchang7",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

