// Room: /d/shaolin/zhulin3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ�������������ܵ�����
�������˼�������Ω�����ߵ��·�棬��ɮ��ľ������΢�紵����Ҷ����
���������������˳���Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"zhulin2",
	]));
	set("outdoors", "shaolin");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
