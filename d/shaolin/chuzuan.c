// Room: /d/shaolin/zhulin6.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ߵ����ͻȻ������һƬ�յأ�ֻ������С�֣�����С����
����������������������ǰ����һ��ʯ�������������Զ��С���Ѿ���
��̫����ˣ�ֻ�ǳ���������׭�̴���ͦ��������������ͨ�����ʯ��
�ؾ�֮·��
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"zhulin5",
		"east" : __DIR__"zhulin11",
		"west" : __DIR__"zhulin12",
	]));

	set("no_clean_up", 0);

	set("outdoors", "shaolin");

	setup();

	replace_program(ROOM);
}

